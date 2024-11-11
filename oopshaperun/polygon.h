#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class Polygon : public Shape {
private:
    std::vector<Vertex> vertices;

public:
    Polygon(const std::vector<Vertex>& verts) : vertices(verts) {}

    void rotate(float angle) override {
        float radians = angle * M_PI / 180.0;
        for (auto& vertex : vertices) {
            float x_new = vertex.first * cos(radians) - vertex.second * sin(radians);
            float y_new = vertex.first * sin(radians) + vertex.second * cos(radians);
            vertex = {x_new, y_new};
        }
    }

    void translate(float dx, float dy) override {
        for (auto& vertex : vertices) {
            vertex.first += dx;
            vertex.second += dy;
        }
    }

    void scale(float factor) override {
        for (auto& vertex : vertices) {
            vertex.first *= factor;
            vertex.second *= factor;
        }
    }

    std::vector<Vertex> getVertices() const override {
        return vertices;
    }
    
    void draw() override {
        glBegin(GL_POLYGON);
        for (const auto& vertex : vertices) {
            glVertex2f(vertex.first, vertex.second);
        }
        glEnd();
    }
};

#endif // POLYGON_H

