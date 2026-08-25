#include "sky_math.hpp"

#include <iostream>
#include <vector>

int main() {
    using sky::math::Matrix;
    Matrix left(2, 2);
    Matrix right(2, 2);
    left.at(0, 0) = 1.0;
    left.at(0, 1) = 2.0;
    left.at(1, 0) = 3.0;
    left.at(1, 1) = 4.0;
    right.at(0, 0) = 5.0;
    right.at(0, 1) = 6.0;
    right.at(1, 0) = 7.0;
    right.at(1, 1) = 8.0;

    const Matrix product = left.multiply(right);
    std::cout << "product_00=" << product.at(0, 0) << '\n';
    std::cout << "determinant=" << left.determinant2x2() << '\n';
    std::cout << "dot=" << sky::math::dot_product({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}) << '\n';
    return 0;
}
