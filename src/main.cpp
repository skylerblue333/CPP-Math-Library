#include "sky/math.hpp"

#include <iostream>
#include <vector>

int main() {
    sky::math::Matrix left(2, 2);
    left.at(0, 0) = 1.0;
    left.at(0, 1) = 2.0;
    left.at(1, 0) = 3.0;
    left.at(1, 1) = 4.0;

    sky::math::Matrix right(2, 2);
    right.at(0, 0) = 5.0;
    right.at(0, 1) = 6.0;
    right.at(1, 0) = 7.0;
    right.at(1, 1) = 8.0;

    const auto product = left.multiply(right);
    const auto dot = sky::math::dot_product({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0});

    std::cout << "sky-math product00=" << product.at(0, 0)
              << " determinant=" << left.determinant2x2()
              << " dot=" << dot << '\n';
    return 0;
}
