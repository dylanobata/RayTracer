#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3
{
public:
    // attributes
    double e[3];
    
    // methods
    Vec3() : e{0,0,0} {}
    Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    Vec3& operator+=(const Vec3 &vec)
    {
        e[0] += vec.e[0];
        e[1] += vec.e[1];
        e[2] += vec.e[2];
        return *this;
    }
    
    Vec3& operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    Vec3& operator/=(const double t)
    {
        return *this *= 1/t;
    }

    double length() const 
    {
        return sqrt(length_squared());
    }

    double length_squared() const 
    {
        return e[0] * e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// type aliases for vec3

using point3 = Vec3; // 3D point
using color = Vec3; // RGB color

// Vec3 utility functions

inline std::ostream& operator <<(std::ostream &out, const Vec3 &vec)
{
    return out << vec.e[0] << ' '<< vec.e[1] << ' ' << vec.e[2];
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}


inline Vec3 operator*(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vec3 operator*(double t, const Vec3 &vec)
{
    return Vec3(t*vec.e[0], t*vec.e[1], t*vec.e[2]);
}

inline Vec3 operator*(const Vec3 &vec, double t)
{
    return t*vec;
}

inline Vec3 operator/(Vec3 vec, double t)
{
    return (1/t) * vec;

}

inline double dot(const Vec3 &u, const Vec3 &v)
{
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v)
{
    return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vec3 unit_vector(Vec3 v)
{
    return v / v.length();
}
