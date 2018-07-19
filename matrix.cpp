#include "matrix.h"
#include <exception>

 Matrix::Matrix(std::vector<std::vector<int>>&& rhs) : matrix_(rhs)
 {
     if( isEmpty()) throw std::exception();

    int size = matrix_[0].size();

    for(auto &x : matrix_)
    {
        if(size != x.size())
        {
            throw std::exception();
        }
    }

 }


Matrix::Matrix(int x, int y)
{

    matrix_.resize(x);
    for(auto& i : matrix_)
    {
       i.resize(y);
    }

}

int Matrix::getValue(int x, int y)

{
    if(x >= matrix_.size() || y >= matrix_[0].size())
    {
        throw std::exception();
    }
    return matrix_[x][y];
}
Matrix Matrix::operator+ (const Matrix& m2)
{

    if (!equalSize(m2))
    {
        throw std::exception();
    }

     Matrix m3(matrix_.size(),matrix_[0].size());

    for (int i=0;i<matrix_.size();i++)
    {
        for (int j=0;j<matrix_[0].size();j++) // ??
        {
            m3.matrix_[i][j]=matrix_[i][j]+m2.matrix_[i][j];
        }
    }
    return m3;
}

Matrix Matrix::operator* (const int scalar)
{

    if(isEmpty())
    {
        throw std::exception();
    }

    Matrix m3(matrix_.size(),matrix_[0].size());

   for (int i=0;i<matrix_.size();i++)
   {
       for (int j=0;j<matrix_[0].size();j++) // ??
       {
           m3.matrix_[i][j] = matrix_[i][j] * scalar;
       }
   }
   return m3;
}

bool Matrix::equalSize(Matrix m_new)
{
    if(m_new.isEmpty() ||  isEmpty()) throw std::exception();
    if((matrix_.size()==m_new.matrix_.size())
            && (matrix_[0].size()==m_new.matrix_[0].size()))
    {
        return true;
    }
    else  return false;
}

bool Matrix::isEmpty()
{
     if(matrix_.empty())
     {
         return true;
     }
     else
     {
         return false;
     }
}


std::pair<int,int>  Matrix::getSize() const


{
    return std::make_pair( matrix_.size(), matrix_[0].size());
}
Matrix operator* (const int a, const Matrix& m7)
{
     Matrix m3(m7.getSize().first, m7.getSize().second);

    for (int i=0;i<m7.getSize().first;i++)
    {
        for (int j=0;j<m7.getSize().second;j++) // ??
        {
            m3.matrix_[i][j] = m7.matrix_[i][j] * a;
        }
    }
    return m3;
}
