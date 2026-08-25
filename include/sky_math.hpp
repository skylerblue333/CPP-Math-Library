#pragma once

#include <cstddef>
#include <vector>

namespace sky::math {

constexpr std::size_t kMaxDimension = 256;

class Matrix {
public:
    Matrix(std::size_t rows, std::size_t cols);

    [[nodiscard]] std::size_t rows() const noexcept;
    [[nodiscard]] std::size_t cols() const noexcept;
    double& at(std::size_t row, std::size_t col);
    const double& at(std::size_t row, std::size_t col) const;
    [[nodiscard]] Matrix multiply(const Matrix& other) const;
    [[nodiscard]] double determinant2x2() const;

private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;
};

[[nodiscard]] double dot_product(const std::vector<double>& left,
                                 const std::vector<double>& right);

}  // namespace sky::math
