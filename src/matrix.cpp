#include "matrix.hpp"

#include <stdexcept>

Matrix matmul(const Matrix& A, const Matrix& B) {
    if (A.cols() != B.rows()) {
        throw std::invalid_argument("Wrong dimensions");
    }

    Matrix C(A.rows(), B.cols());
    for (std::size_t i=0; i < A.rows(); i++) {
        for (std::size_t j=0; j<B.cols(); j++) {
            for (std::size_t k=0; k<A.cols(); k++) {
                C(i,j) += A(i,k) * B(k,j);
            }
        }
    }
    return C;
}

std::vector<float> GEMV(const Matrix& A, const std::vector<float>& x) {
    if (A.cols() != x.size()) { throw std::invalid_argument("Wrong dimensions");}

    std::vector<float> y(A.rows(), 0.0f);
    for (std::size_t i = 0; i<A.rows(); i++) {
        for (std::size_t j = 0; j < A.cols(); j++) {
            y[i] += A(i,j) * x[j];
        }
    }

    return y;
}
