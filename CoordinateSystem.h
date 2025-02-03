#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "Vec3.h"

constexpr double DEG_TO_RAD = M_PI / 180.0f;

class CoordinateSystem {
private:
    void constructFromRotation(double xDeg, double yDeg, double zDeg);

public:
    Vec3 origin, xAxis, yAxis, zAxis;

    CoordinateSystem(const Vec3& origin, const Vec3& xAxis, const Vec3& yAxis, const Vec3& zAxis) :
        origin(origin),
        xAxis(xAxis),
        yAxis(yAxis),
        zAxis(zAxis)
    {}

    CoordinateSystem(const Vec3& origin, const double xDeg, const double yDeg, const double zDeg) :
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

    void print() const {
        origin.print();
        xAxis.print();
        yAxis.print();
        zAxis.print();
    }
};

#endif //COORDINATESYSTEM_H