#include <iostream>
#include <vector>
#include <cassert>
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
        if (cols != other.rows) throw std::invalid_argument("Incompatible");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.at(i,j) += at(i,k) * other.at(k,j);
        return result;
    }
    double determinant2x2() const { return at(0,0)*at(1,1) - at(0,1)*at(1,0); }
};

double dot_product(const std::vector<double>& a, const std::vector<double>& b) {
    double r = 0.0;
    for (size_t i = 0; i < a.size(); ++i) r += a[i] * b[i];
    return r;
}

int main() {
    Matrix a(2,2);
    a.at(0,0)=1; a.at(0,1)=2; a.at(1,0)=3; a.at(1,1)=4;
    assert(a.determinant2x2() == -2.0);
    
    Matrix b(2,2);
    b.at(0,0)=1; b.at(1,1)=1;
    Matrix c = a.multiply(b);
    assert(c.at(0,0) == 1.0);
    
    assert(dot_product({1,2,3}, {4,5,6}) == 32.0);
    
    std::cout << "All math library tests passed!\n";
    return 0;
}
