#include "sky/math.hpp"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace {

bool near(double left, double right) {
    return std::abs(left - right) < 1e-12;
}

int fail(const char* message) {
    std::cerr << message << '\n';
    return 1;
}

} // namespace

int main() {
    sky::math::Matrix left(2, 2);
    left.at(0, 0) = 1.0;
    left.at(0, 1) = 2.0;
    left.at(1, 0) = 3.0;
    left.at(1, 1) = 4.0;
    if (!near(left.determinant2x2(), -2.0)) return fail("determinant mismatch");

    sky::math::Matrix identity(2, 2);
    identity.at(0, 0) = 1.0;
    identity.at(1, 1) = 1.0;
    const auto product = left.multiply(identity);
    if (!near(product.at(0, 0), 1.0) || !near(product.at(1, 1), 4.0)) return fail("matrix product mismatch");

    if (!near(sky::math::dot_product({1, 2, 3}, {4, 5, 6}), 32.0)) return fail("dot product mismatch");

    bool rejected = false;
    try {
        (void)sky::math::dot_product({1}, {1, 2});
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    if (!rejected) return fail("vector length mismatch was accepted");

    rejected = false;
    try {
        sky::math::Matrix invalid(0, 2);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    if (!rejected) return fail("zero matrix dimension was accepted");

    rejected = false;
    try {
        (void)left.at(2, 0);
    } catch (const std::out_of_range&) {
        rejected = true;
    }
    if (!rejected) return fail("out-of-range matrix access was accepted");

    rejected = false;
    try {
        (void)sky::math::dot_product({std::numeric_limits<double>::infinity()}, {1.0});
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    if (!rejected) return fail("non-finite vector value was accepted");

    std::cout << "Sky Math tests passed\n";
    return 0;
}
