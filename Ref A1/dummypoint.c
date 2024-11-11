#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};

struct Point find_outer_tangents(struct Point center_small, double radius_small,
                                 struct Point center_large, double radius_large)
{
    struct Point point4; // Assume second tangent point (x4, y4)

    // Calculate distance and check for outer tangent possibility
    double d = sqrt(pow(center_large.x - center_small.x, 2) +
                    pow(center_large.y - center_small.y, 2));
    double sum_radii = radius_small + radius_large;
    if (d <= sum_radii)
    {
        printf("Outer tangent is not possible.\n");
        return point4; // Return empty point struct
    }

    // Calculate direction vector
    double dx = (center_large.x - center_small.x) / d;
    double dy = (center_large.y - center_small.y) / d;

    // Calculate distance from small circle to tangent point on large circle
    double leg_a = sqrt(d * d - radius_small * radius_small);

    // Calculate tangent point coordinates on large circle
    double x3 = center_small.x + leg_a * dx;
    double y3 = center_small.y + leg_a * dy;

    // Calculate tangent line equation (point-slope form)
    double slope = (y3 - center_small.y) / (x3 - center_small.x);

    // Find intersection points with large circle equation
    double a = pow(radius_large, 2) - pow(center_large.x, 2) - pow(center_large.y, 2);
    double b = 2 * slope * (center_large.x - x3) + 2 * (center_large.y - y3);
    double c = pow(x3, 2) + pow(y3, 2) - 2 * center_small.x * x3 - 2 * center_small.y * y3 + pow(center_small.x, 2) + pow(center_small.y, 2) - pow(radius_small, 2);

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
    {
        printf("No tangent points found.\n");
        return point4; // Return empty point struct
    }

    // Calculate two intersection points (use only valid point above small circle)
    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);
    double y1 = slope * (x1 - x3) + y3;
    double y2 = slope * (x2 - x3) + y3;

    // Choose correct intersection point (above small circle)
    if (y1 > center_small.y)
    {
        point4.x = x1;
        point4.y = y1;
    }
    else
    {
        point4.x = x2;
        point4.y = y2;
    }

    return point4;
}

int main()
{
    struct Point center_small = {0, 250};
    double radius_small = 20;
    struct Point center_large = {0, 0};
    double radius_large = 50;

    struct Point point4 = find_outer_tangents(center_small, radius_small, center_large, radius_large);

    if (point4.x == 0 && point4.y == 0)
    {
        // Handle no tangent points case
    }
    else
    {
        printf("Second tangent point (x4, y4): (%.2lf, %.2lf)\n", point4.x, point4.y);
    }

    return 0;
}