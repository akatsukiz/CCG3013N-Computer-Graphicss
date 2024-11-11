#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
private:
    Vertex v1, v2, v3;

public:
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
        : v1(x1, y1), v2(x2, y2), v3(x3, y3) {}

    void rotate(float angle) override {
        float radians = angle * M_PI / 180.0;
        // Rotate around the origin
        v1 = {v1.first * cos(radians) - v1.second * sin(radians),
              v1.first * sin(radians) + v1.second * cos(radians)};
        v2 = {v2.first * cos(radians) - v2.second * sin(radians),
              v2.first * sin(radians) + v2.second * cos(radians)};
        v3 = {v3.first * cos(radians) - v3.second * sin(radians),
              v3.first * sin(radians) + v3.second * cos(radians)};
    }

    void translate(float dx, float dy) override {
        v1.first += dx;
        v1.second += dy;
        v2.first += dx;
        v2.second += dy;
        v3.first += dx;
        v3.second += dy;
    }

    void scale(float factor) override {
        v1.first *= factor;
        v1.second *= factor;
        v2.first *= factor;
        v2.second *= factor;
        v3.first *= factor;
    }

    std::vector<Vertex> getVertices() const override {
        return {v1, v2, v3};
    }
    
    void draw() override {
        glBegin(GL_TRIANGLES);
        glVertex2f(v1.first, v1.second);
        glVertex2f(v2.first, v2.second);
        glVertex2f(v3.first, v3.second);
        glEnd();
    }
};

#endif // TRIANGLE_H

