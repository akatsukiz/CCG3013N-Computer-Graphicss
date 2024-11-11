#ifndef DOT_H
#define DOT_H

#include "shape.h"

class Dot : public Shape {
private:
    Vertex position; // Only 1 vertex for a dot

public:
    Dot(float x, float y) : position(x, y) {}

    void rotate(float angle) override {
        // No effect on a single point
    }

    void translate(float dx, float dy) override {
        position.first += dx;
        position.second += dy;
    }

    void scale(float factor) override {
        // Scaling does not affect a dot in this case
    }

    std::vector<Vertex> getVertices() const override {
        return { position };
    }
};

#endif // DOT_H

