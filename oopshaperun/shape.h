#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <utility> // for std::pair
#include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

typedef std::pair<float, float> Vertex; // (x, y) coordinates

class Shape {
public:
    virtual ~Shape() {}

    // Function to rotate the shape
    virtual void rotate(float angle) = 0;

    // Function to translate the shape
    virtual void translate(float dx, float dy) = 0;

    // Function to scale the shape
    virtual void scale(float factor) = 0;

    // Function to return the list of vertices
    virtual std::vector<Vertex> getVertices() const = 0;
    
    virtual void draw() = 0; // Draw function
};

#endif // SHAPE_H

