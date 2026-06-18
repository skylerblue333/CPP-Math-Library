#include <iostream>
#include "src/vec3.h"

int main() {
    Vec3 a(1.0f, 2.0f, 3.0f);
    Vec3 b(4.0f, 5.0f, 6.0f);
    
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a dot b = " << a.dot(b) << "\n";
    std::cout << "a cross b = " << a.cross(b) << "\n";
    std::cout << "a normalized = " << a.normalize() << "\n";
    std::cout << "|a| = " << a.length() << "\n";
    
    return 0;
}
