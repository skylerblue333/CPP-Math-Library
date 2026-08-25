#include "sky_math.hpp"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

namespace {
int failures = 0;

void expect(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << '\n';
        ++failures;
    }
}

template <typename Exception, typename Callable>
void expect_throws(Callable callable, const char* message) {
    try {
        callable();
        expect(false, message);
    } catch (const Exception&) {
    } catch (...) {
        expect(false, message);
    }
}
}  // namespace

int main() {
    using sky::math::Matrix;

    Matrix matrix(2, 2);
    matrix.at(0, 0) = 1.0;
    matrix.at(0, 1) = 2.0;
    matrix.at(1, 0) = 3.0;
    matrix.at(1, 1) = 4.0;
    expect(matrix.determinant2x2() == -2.0, "2x2 determinant");

    Matrix identity(2, 2);
    identity.at(0, 0) = 1.0;
    identity.at(1, 1) = 1.0;
    const Matrix product = matrix.multiply(identity);
    expect(product.at(1, 0) == 3.0 && product.at(1, 1) == 4.0, "matrix multiply identity");

    expect(sky::math::dot_product({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}) == 32.0,
           "dot product");
    expect_throws<std::invalid_argument>([] { Matrix invalid(0, 2); }, "zero matrix dimension");
    expect_throws<std::out_of_range>([&] { (void)matrix.at(2, 0); }, "matrix index bounds");
    expect_throws<std::invalid_argument>([] { (void)sky::math::dot_product({1.0}, {1.0, 2.0}); },
                                         "vector length mismatch");
    expect_throws<std::invalid_argument>([] {
        (void)sky::math::dot_product({std::numeric_limits<double>::infinity()}, {1.0});
    }, "non-finite vector input");

    if (failures != 0) {
        return 1;
    }
    std::cout << "Sky Math contract tests passed\n";
    return 0;
}
