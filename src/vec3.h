#pragma once
#include <cmath>
#include <iostream>

struct Vec3 {
    float x, y, z;
    
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    Vec3 operator+(const Vec3& o) const { return {x+o.x, y+o.y, z+o.z}; }
    Vec3 operator-(const Vec3& o) const { return {x-o.x, y-o.y, z-o.z}; }
    Vec3 operator*(float s) const { return {x*s, y*s, z*s}; }
    
    float dot(const Vec3& o) const { return x*o.x + y*o.y + z*o.z; }
    
    Vec3 cross(const Vec3& o) const {
        return {y*o.z - z*o.y, z*o.x - x*o.z, x*o.y - y*o.x};
    }
    
    float length() const { return std::sqrt(x*x + y*y + z*z); }
    
    Vec3 normalize() const {
        float len = length();
        return (len > 0) ? Vec3(x/len, y/len, z/len) : Vec3();
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v) {
        return os << "Vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
    }
};
