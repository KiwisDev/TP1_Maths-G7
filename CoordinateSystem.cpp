#include "CoordinateSystem.h"

void CoordinateSystem::constructFromRotation(double xDeg, double yDeg, double zDeg) {
    double xRad = xDeg * DEG_TO_RAD;
    double yRad = yDeg * DEG_TO_RAD;
    double zRad = zDeg * DEG_TO_RAD;

    double rotX[3][3] = {
        {1, 0, 0},
        {0, cos(xRad), -sin(xRad)},
        {0, sin(xRad), cos(xRad)}
    };

    double rotY[3][3] = {
        {cos(yRad), 0, sin(yRad)},
        {0, 1, 0},
        {-sin(yRad), 0, cos(yRad)}
    };

    double rotZ[3][3] = {
        {cos(zRad), -sin(zRad), 0},
        {sin(zRad), cos(zRad), 0},
        {0, 0, 1}
    };

    this->xAxis = this->xAxis.transform(rotZ).transform(rotY).transform(rotX);
    this->yAxis = this->yAxis.transform(rotZ).transform(rotY).transform(rotX);
    this->zAxis = this->zAxis.transform(rotZ).transform(rotY).transform(rotX);
}