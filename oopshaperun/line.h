#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape {
private:
    Vertex start, end;

public:
    Line(float x1, float y1, float x2, float y2) : start(x1, y1), end(x2, y2) {}

    void rotate(float angle) override {
        float radians = angle * M_PI / 180.0;
        // Rotate around the origin
        start = {start.first * cos(radians) - start.second * sin(radians),
                 start.first * sin(radians) + start.second * cos(radians)};
        end = {end.first * cos(radians) - end.second * sin(radians),
               end.first * sin(radians) + end.second * cos(radians)};
    }

    void translate(float dx, float dy) override {
        start.first += dx;
        start.second += dy;
        end.first += dx;
        end.second += dy;
    }

    void scale(float factor) override {
        start.first *= factor;
        start.second *= factor;
        end.first *= factor;
        end.second *= factor;
    }

    std::vector<Vertex> getVertices() const override {
        return {start, end};
    }
    
    void draw() override {
        glBegin(GL_LINES);
        glVertex2f(start.first, start.second);
        glVertex2f(end.first, end.second);
        glEnd();
    }
};

#endif // LINE_H

