#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "Vec3.h"

constexpr double DEG_TO_RAD = M_PI / 180.0f;

class CoordinateSystem {
private:
    void constructFromRotation(double xDeg, double yDeg, double zDeg);

public:
    Vec3 origin, xAxis, yAxis, zAxis;

    CoordinateSystem(const Vec3& origin = Vec3(0, 0, 0), const Vec3& xAxis = Vec3(1, 0, 0), const Vec3& yAxis = Vec3(0, 1, 0), const Vec3& zAxis = Vec3(0, 0, 1)) :
        origin(origin),
        xAxis(xAxis),
        yAxis(yAxis),
        zAxis(zAxis)
    {}

    CoordinateSystem(const Vec3& origin = Vec3(0, 0, 0), const double xDeg = 0.0, const double yDeg = 0.0, const double zDeg = 0.0) :
        origin(origin),
        xAxis(1, 0, 0),
        yAxis(0, 1, 0),
        zAxis(0, 0, 1)
    {
        constructFromRotation(xDeg, yDeg, zDeg);
    }

    Vec3 getUniversalPosition(const Vec3& pos) const {
        return origin + (xAxis * pos.x) + (yAxis * pos.y) + (zAxis * pos.z);
    }

    bool isLinearlyIndependent() const {
        const double determinant =
        xAxis.x * (yAxis.y * zAxis.z - yAxis.z * zAxis.y)
        - xAxis.y * (yAxis.x * zAxis.z - yAxis.z * zAxis.x)
        + xAxis.z * (yAxis.x * zAxis.y - yAxis.y * zAxis.x);

        return std::abs(determinant) >= 1e-9;
    }

    void print() const {
        origin.print();
        xAxis.print();
        yAxis.print();
        zAxis.print();
    }
};

#endif //COORDINATESYSTEM_H