#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
private:
    Vertex v1, v2, v3, v4;

public:
    Rectangle(float x1, float y1, float width, float height) {
        v1 = {x1, y1};
        v2 = {x1 + width, y1};
        v3 = {x1 + width, y1 + height};
        v4 = {x1, y1 + height};
    }

    void rotate(float angle) override {
    float radians = angle * M_PI / 180.0;

    // Calculate the center of the rectangle
    float centerX = (v1.first+v2.first+v3.first+v4.first)/4;
    float centerY = (v1.second+v2.second+v3.second+v4.second)/4;

    // Translate to the origin (center of the rectangle)
    v1 = {v1.first - centerX, v1.second - centerY};
    v2 = {v2.first - centerX, v2.second - centerY};
    v3 = {v3.first - centerX, v3.second - centerY};
    v4 = {v4.first - centerX, v4.second - centerY};

    // Perform rotation around the origin
    v1 = {v1.first * cos(radians) - v1.second * sin(radians),
          v1.first * sin(radians) + v1.second * cos(radians)};
    
    v2 = {v2.first * cos(radians) - v2.second * sin(radians),
          v2.first * sin(radians) + v2.second * cos(radians)};
    
    v3 = {v3.first * cos(radians) - v3.second * sin(radians),
          v3.first * sin(radians) + v3.second * cos(radians)};
    
    v4 = {v4.first * cos(radians) - v4.second * sin(radians),
          v4.first * sin(radians) + v4.second * cos(radians)};

    // Translate back to the original position
    v1 = {v1.first + centerX, v1.second + centerY};
    v2 = {v2.first + centerX, v2.second + centerY};
    v3 = {v3.first + centerX, v3.second + centerY};
    v4 = {v4.first + centerX, v4.second + centerY};
}


    void translate(float dx, float dy) override {
        v1.first += dx;
        v1.second += dy;
        v2.first += dx;
        v2.second += dy;
        v3.first += dx;
        v3.second += dy;
        v4.first += dx;
        v4.second += dy;
    }

    void scale(float factor) override {
        v1.first *= factor;
        v1.second *= factor;
        v2.first *= factor;
        v2.second *= factor;
        v3.first *= factor;
        v3.second *= factor;
        v4.first *= factor;
    }

    std::vector<Vertex> getVertices() const override {
        return {v1, v2, v3, v4};
    }
    
     void draw() override {
        std::vector<Vertex> vertices = getVertices();
        glBegin(GL_QUADS);
        for (const auto& vertex : vertices) {
            glVertex2f(vertex.first, vertex.second);
        }
        glEnd();
    }
};

#endif // RECTANGLE_H

