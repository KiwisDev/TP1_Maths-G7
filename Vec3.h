#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class Vec3 {
public:
    double x, y, z;

    Vec3(const double x = 0, const double y = 0, const double z = 0) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }

    Vec3 operator-(const Vec3& rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }

    Vec3 operator*(const double rhs) const {
        return {x * rhs, y * rhs, z * rhs};
    }

    /*
     * Retourne la longueur du vecteur
     */
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    /*
     * Retourne le vecteur unitaire du vecteur
     */
    Vec3 normalize() const {
        const double magnitude = length();
        if (magnitude > 0.0) {
            return {x / magnitude, y / magnitude, z / magnitude};
        }
        return {0, 0, 0};
    }

    /*
     * Retourne la distance entre ce vecteur et un autre
     */
    double distance(const Vec3& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }

    /*
     * Retourne le produit sclaire
     */
    double dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    /*
     * Retourne le vecteur transformer avec une matrice de rotation
     */
    Vec3 transform(double matrix[3][3]) const {
        return {
            x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
            x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
            x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]
        };
    }

    /*
     * Affiche le vecteur
     */
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

#endif //VEC3_H