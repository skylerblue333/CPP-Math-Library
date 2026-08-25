#include "sky_math.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

namespace sky::math {
namespace {

void require_finite(double value) {
    if (!std::isfinite(value)) {
        throw std::invalid_argument("matrix/vector values must be finite");
    }
}

}  // namespace

Matrix::Matrix(std::size_t rows, std::size_t cols) : rows_(rows), cols_(cols) {
    if (rows == 0 || cols == 0 || rows > kMaxDimension || cols > kMaxDimension) {
        throw std::invalid_argument("matrix dimensions must be between 1 and 256");
    }
    if (rows > std::numeric_limits<std::size_t>::max() / cols) {
        throw std::overflow_error("matrix size overflow");
    }
    data_.assign(rows * cols, 0.0);
}

std::size_t Matrix::rows() const noexcept { return rows_; }
std::size_t Matrix::cols() const noexcept { return cols_; }

double& Matrix::at(std::size_t row, std::size_t col) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("matrix index out of range");
    }
    return data_.at(row * cols_ + col);
}

const double& Matrix::at(std::size_t row, std::size_t col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("matrix index out of range");
    }
    return data_.at(row * cols_ + col);
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("incompatible matrix dimensions");
    }
    Matrix result(rows_, other.cols_);
    for (std::size_t row = 0; row < rows_; ++row) {
        for (std::size_t col = 0; col < other.cols_; ++col) {
            double value = 0.0;
            for (std::size_t inner = 0; inner < cols_; ++inner) {
                require_finite(at(row, inner));
                require_finite(other.at(inner, col));
                value += at(row, inner) * other.at(inner, col);
                require_finite(value);
            }
            result.at(row, col) = value;
        }
    }
    return result;
}

double Matrix::determinant2x2() const {
    if (rows_ != 2 || cols_ != 2) {
        throw std::invalid_argument("determinant2x2 requires a 2x2 matrix");
    }
    for (double value : data_) {
        require_finite(value);
    }
    const double determinant = at(0, 0) * at(1, 1) - at(0, 1) * at(1, 0);
    require_finite(determinant);
    return determinant;
}

double dot_product(const std::vector<double>& left, const std::vector<double>& right) {
    if (left.size() != right.size()) {
        throw std::invalid_argument("vectors must have equal lengths");
    }
    if (left.empty() || left.size() > kMaxDimension) {
        throw std::invalid_argument("vector length must be between 1 and 256");
    }
    double result = 0.0;
    for (std::size_t i = 0; i < left.size(); ++i) {
        require_finite(left[i]);
        require_finite(right[i]);
        result += left[i] * right[i];
        require_finite(result);
    }
    return result;
}

}  // namespace sky::math
