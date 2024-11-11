#include <GL/glut.h>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

// Window dimensions
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
const float M_PI = 3.14159265358979323846;

// Colors (RGBA)
struct Color {
    float r, g, b, a;
    Color(float r, float g, float b, float a = 1.0f) : r(r), g(g), b(b), a(a) {}
};

const Color PINK(1.0f, 0.8f, 0.8f);
const Color LIGHT_GRAY(0.9f, 0.9f, 0.9f);
const Color WHITE(1.0f, 1.0f, 1.0f);
const Color BLACK(0.0f, 0.0f, 0.0f);
const Color BLUE(0.0f, 0.5f, 1.0f);
const Color RED(1.0f, 0.2f, 0.2f);

// UI Component base class
class UIComponent {
protected:
    float x, y, width, height;
    Color backgroundColor;
    bool isHovered;

public:
    UIComponent(float x, float y, float w, float h, Color bgColor)
        : x(x), y(y), width(w), height(h), backgroundColor(bgColor), isHovered(false) {}
    
    virtual void draw() = 0;
    virtual bool containsPoint(float px, float py) {
        return px >= x && px <= x + width && py >= y && py <= y + height;
    }
    virtual void setHovered(bool hovered) { isHovered = hovered; }
};

// Card component
class Card : public UIComponent {
private:
    std::string title;
    std::vector<std::shared_ptr<UIComponent>> children;

public:
    Card(float x, float y, float w, float h, const std::string& title, Color bgColor)
        : UIComponent(x, y, w, h, bgColor), title(title) {}

    void addChild(std::shared_ptr<UIComponent> child) {
        children.push_back(child);
    }

    void draw() override {
        // Draw card background
        glColor4f(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();

        // Draw title
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(x + 10, y + height - 20);
        for (char c : title) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }

        // Draw children
        for (auto& child : children) {
            child->draw();
        }
    }
};

// Circle gauge component
class CircleGauge : public UIComponent {
private:
    float value;
    std::string label;
    Color accentColor;

public:
    CircleGauge(float x, float y, float size, float value, const std::string& label, Color accent)
        : UIComponent(x, y, size, size, WHITE), value(value), label(label), accentColor(accent) {}

    void draw() override {
        // Draw background circle
        glColor4f(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        drawCircle(x + width/2, y + height/2, width/2, true);

        // Draw progress arc
        glColor4f(accentColor.r, accentColor.g, accentColor.b, accentColor.a);
        drawArc(x + width/2, y + height/2, width/2 * 0.9f, 0, value * 360.0f);

        // Draw label
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(x + width/2 - label.length()*4, y + height/2);
        for (char c : label) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }
    }

private:
    void drawCircle(float cx, float cy, float radius, bool filled) {
        const int segments = 100;
        glBegin(filled ? GL_POLYGON : GL_LINE_LOOP);
        for (int i = 0; i < segments; i++) {
            float theta = 2.0f * M_PI * float(i) / float(segments);
            float px = cx + radius * cosf(theta);
            float py = cy + radius * sinf(theta);
            glVertex2f(px, py);
        }
        glEnd();
    }

    void drawArc(float cx, float cy, float radius, float startAngle, float endAngle) {
        const int segments = 100;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= segments; i++) {
            float theta = startAngle + (endAngle - startAngle) * float(i) / float(segments);
            float angle = theta * M_PI / 180.0f;
            float px = cx + radius * cosf(angle);
            float py = cy + radius * sinf(angle);
            glVertex2f(px, py);
        }
        glEnd();
    }
};

// Button component
class Button : public UIComponent {
private:
    std::string label;
    std::string iconText;

public:
    Button(float x, float y, float w, float h, const std::string& label, 
           const std::string& icon, Color bgColor)
        : UIComponent(x, y, w, h, bgColor), label(label), iconText(icon) {}

    void draw() override {
        // Draw button background
        glColor4f(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();

        // Draw icon
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(x + width/2 - iconText.length()*4, y + height/2 + 10);
        for (char c : iconText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }

        // Draw label
        glRasterPos2f(x + width/2 - label.length()*4, y + height/2 - 10);
        for (char c : label) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }
    }
};

// Global UI state
std::vector<std::shared_ptr<UIComponent>> components;

// Initialize UI components
void initUI() {
    // Weather card
    auto weatherCard = std::make_shared<Card>(10, 10, 300, 150, "Hello, Rei!", PINK);
    components.push_back(weatherCard);

    // Temperature and Power gauges
    auto tempGauge = std::make_shared<CircleGauge>(330, 10, 150, 0.6f, "22°C", BLUE);
    auto powerGauge = std::make_shared<CircleGauge>(500, 10, 150, 0.8f, "135 kwh", RED);
    components.push_back(tempGauge);
    components.push_back(powerGauge);

    // Control buttons
    float buttonSize = 80;
    float startX = 10;
    float startY = 170;
    float gap = 10;

    std::vector<std::pair<std::string, std::string>> buttons = {
        {"Lights", "○"}, {"Heating", "▲"}, {"AC", "*"}, {"Cameras", "[]"},
        {"Doors", "□"}, {"Alarms", "!"}, {"Blinds", "≡"}, {"Music", "♪"}
    };

    for (size_t i = 0; i < buttons.size(); i++) {
        float x = startX + (i % 4) * (buttonSize + gap);
        float y = startY + (i / 4) * (buttonSize + gap);
        auto button = std::make_shared<Button>(x, y, buttonSize, buttonSize,
            buttons[i].first, buttons[i].second,
            (i % 2 == 0) ? PINK : LIGHT_GRAY);
        components.push_back(button);
    }
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw all components
    for (auto& component : components) {
        component->draw();
    }

    glutSwapBuffers();
}

// Reshape callback
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
}

// Mouse movement callback
void mouseMove(int x, int y) {
    for (auto& component : components) {
        component->setHovered(component->containsPoint(x, y));
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Smart Home Control");

    // Set up OpenGL state
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Initialize UI
    initUI();

    // Register callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(mouseMove);

    // Start main loop
    glutMainLoop();
    return 0;
}