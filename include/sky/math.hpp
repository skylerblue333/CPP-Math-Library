#pragma once

#include <cmath>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <vector>

namespace sky::math {

class Matrix {
public:
    Matrix(std::size_t rows, std::size_t cols)
        : rows_(rows), cols_(cols), data_(checked_size(rows, cols), 0.0) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("matrix dimensions must be positive");
        }
    }

    [[nodiscard]] std::size_t rows() const noexcept { return rows_; }
    [[nodiscard]] std::size_t cols() const noexcept { return cols_; }

    double& at(std::size_t row, std::size_t col) {
        return data_.at(index(row, col));
    }

    const double& at(std::size_t row, std::size_t col) const {
        return data_.at(index(row, col));
    }

    [[nodiscard]] Matrix multiply(const Matrix& other) const {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("incompatible matrix dimensions");
        }
        Matrix result(rows_, other.cols_);
        for (std::size_t row = 0; row < rows_; ++row) {
            for (std::size_t col = 0; col < other.cols_; ++col) {
                double value = 0.0;
                for (std::size_t k = 0; k < cols_; ++k) {
                    value += at(row, k) * other.at(k, col);
                }
                if (!std::isfinite(value)) {
                    throw std::overflow_error("matrix multiplication produced non-finite value");
                }
                result.at(row, col) = value;
            }
        }
        return result;
    }

    [[nodiscard]] double determinant2x2() const {
        if (rows_ != 2 || cols_ != 2) {
            throw std::invalid_argument("determinant2x2 requires a 2x2 matrix");
        }
        const double value = at(0, 0) * at(1, 1) - at(0, 1) * at(1, 0);
        if (!std::isfinite(value)) {
            throw std::overflow_error("determinant produced non-finite value");
        }
        return value;
    }

private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;

    static std::size_t checked_size(std::size_t rows, std::size_t cols) {
        if (rows != 0 && cols > std::numeric_limits<std::size_t>::max() / rows) {
            throw std::length_error("matrix dimensions overflow addressable size");
        }
        return rows * cols;
    }

    std::size_t index(std::size_t row, std::size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("matrix index out of bounds");
        }
        return row * cols_ + col;
    }
};

inline double dot_product(const std::vector<double>& left, const std::vector<double>& right) {
    if (left.size() != right.size()) {
        throw std::invalid_argument("vectors must have equal length");
    }
    double result = 0.0;
    for (std::size_t index = 0; index < left.size(); ++index) {
        if (!std::isfinite(left[index]) || !std::isfinite(right[index])) {
            throw std::invalid_argument("vectors must contain finite values");
        }
        result += left[index] * right[index];
        if (!std::isfinite(result)) {
            throw std::overflow_error("dot product produced non-finite value");
        }
    }
    return result;
}

} // namespace sky::math
