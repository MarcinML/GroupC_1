#pragma once
#include <vector>


class Matrix
{
  std::vector<std::vector<int>> matrix_;


public:
    Matrix() = default;
    Matrix(int x, int y);
    Matrix(std::vector<std::vector<int>>&& rhs);
    int getValue(int, int);
    Matrix operator+ (const Matrix& m2);
    Matrix operator* (const int scalar);
    //bool operator== (const Matrix& m2);
    bool equalSize(Matrix m_new);
    bool isEmpty();
    std::pair<int,int>  getSize() const;
    friend Matrix operator* (const int, const Matrix&);

};

//friend Matrix operator* (const int, const Matrix&);
