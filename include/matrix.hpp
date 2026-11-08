#pragma once

#include <cstddef>
#include <vector>

class Matrix {
    private:
        std::size_t rows_;
        std::size_t cols_;
        std::vector<float> data_;


    public:
        Matrix(std::size_t rows, std::size_t cols) : rows_(rows), cols_(cols), data_(rows * cols, 0.0f) {}

        std::size_t rows() const {
            return rows_;
        }

        std::size_t cols() const {
            return cols_;
        }
        float& operator()(std::size_t i, std::size_t j) {
            return data_[i * cols_ + j];
        }
        const float& operator()(std::size_t i, std::size_t j) const {
            return data_[i * cols_ + j];
        }

};

Matrix matmul(const Matrix& A, const Matrix& B);
std::vector<float> GEMV(const Matrix& A, const std::vector<float>& x);
