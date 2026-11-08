#include "matrix.hpp"

#include <cassert>
#include <vector>

int main()
{
    Matrix a(3,4);
    const Matrix& b = a;
    a(1,2) = 42.0f;

    assert(a.rows() == 3);
    assert(a.cols() == 4);
    assert(b(1,2) == 42.0f);

    Matrix A(1,2);
    Matrix B(2,3);
    std::vector<float> x = {1,2};
    A(0, 0) = 1; A(0, 1) = 1;
    B(0, 0) = 1; B(0, 1) = 1; B(0, 2) = 1;
    B(1, 0) = 1; B(1, 1) = 1; B(1, 2) = 1;

    Matrix C = matmul(A, B);
    assert(C.rows() == 1);
    assert(C.cols() == 3);
    assert(C(0,0) == 2.0f);
    assert(C(0,1) == 2.0f);
    assert(C(0,2) == 2.0f);

    std::vector<float> y = GEMV(A, x);
    assert(y.size() == 1);
    assert(y[0] == 3.0f);

    return 0;
}
