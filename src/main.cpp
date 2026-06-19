#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<double>> data;
    
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<double>(c, 0.0)) {}
    
    double& at(int r, int c) { return data[r][c]; }
    const double& at(int r, int c) const { return data[r][c]; }
    
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) throw std::invalid_argument("Incompatible dimensions");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.at(i, j) += at(i, k) * other.at(k, j);
        return result;
    }
    
    double determinant2x2() const {
        if (rows != 2 || cols != 2) throw std::invalid_argument("Only 2x2 supported");
        return at(0,0) * at(1,1) - at(0,1) * at(1,0);
    }
    
    void print() const {
        for (const auto& row : data) {
            for (double v : row) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

double dot_product(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vectors must be same size");
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) result += a[i] * b[i];
    return result;
}

int main() {
    Matrix a(2, 2), b(2, 2);
    a.at(0,0) = 1; a.at(0,1) = 2; a.at(1,0) = 3; a.at(1,1) = 4;
    b.at(0,0) = 5; b.at(0,1) = 6; b.at(1,0) = 7; b.at(1,1) = 8;
    
    Matrix c = a.multiply(b);
    std::cout << "Matrix product:\n";
    c.print();
    
    std::cout << "Determinant of A: " << a.determinant2x2() << "\n";
    
    std::vector<double> v1 = {1.0, 2.0, 3.0};
    std::vector<double> v2 = {4.0, 5.0, 6.0};
    std::cout << "Dot product: " << dot_product(v1, v2) << "\n";
    return 0;
}
