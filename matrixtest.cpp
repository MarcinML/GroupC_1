#include <gmock/gmock.h>
#include "matrix.h"


struct MatrixShould : testing::Test
{

    MatrixShould() : m1({{0,1,2,3}, {4,5,6,7}, {8,9,10,11}})
      ,m4({{1,1,1,1}, {1,1,1,1}, {1,1,1,1}})
    ,m5({{1,1,1}, {1,1,1}, {1,1,1}}){}

    Matrix m1;
    Matrix m2;
    Matrix m4;
    Matrix m5;

};

TEST_F(MatrixShould, ShouldReturnAnInstanceOfMatrix)
{
    Matrix matrix(3,4);
}

TEST_F(MatrixShould, WhenCreatedMatrixShouldContainDefaultValues)
{

    EXPECT_EQ( m1.getValue(1,1), 5);
}


TEST_F(MatrixShould, WhenGetOutOfBoundShouldThrowException)
{

    EXPECT_ANY_THROW( m1.getValue(3,1));
}

TEST_F(MatrixShould, WhenEmptyMatrixShouldThrowException)
{

    EXPECT_ANY_THROW( m2.getValue(0,0));
}


TEST_F(MatrixShould, WhenGivenParameteresAreNotValidShouldReturnException)
{

    EXPECT_ANY_THROW(Matrix m3 ({{0,1,2,3}, {4,5,6,7}, {8,9,10}}));
}
TEST_F(MatrixShould, WhenCallEqualSizeMatrixReturnTrue)
{
    EXPECT_TRUE(m1.equalSize(m4));
}



TEST_F(MatrixShould, WhenCallDiffrentSizeMatrixReturnFalse)
{
    EXPECT_FALSE(m1.equalSize(m5));
}


TEST_F(MatrixShould, WhenAddingMatrixtoMatrixShouldReturnCorrectValue)
{
    Matrix m5({{1,2,3,4}, {5,6,7,8}, {9,10,11,12}});
    Matrix m6 = m1+m4;
    for(int i =0; i<m5.getSize().first; i++)
    {
        for(int j =0; j< m5.getSize().second; j++)
        {
            EXPECT_EQ(m5.getValue(i,j), m6.getValue(i,j));

        }

    }
}

TEST_F(MatrixShould, WhenMultiplyingByScalarShouldReturnCorrectValue)
{
    int scalar = 5;

    Matrix m6 = m5 * 5;

    for(int i =0; i<m5.getSize().first; i++)
    {
        for(int j =0; j< m5.getSize().second; j++)
        {
            EXPECT_EQ(m6.getValue(i, j), 5);

        }
    }
}


TEST_F(MatrixShould, WhenMultiplyingScalarByMatrixShouldReturnCorrectValue)
{
    int scalar = 5;

    Matrix m6 = 5 * m5;

    for(int i =0; i<m5.getSize().first; i++)
    {
        for(int j =0; j< m5.getSize().second; j++)
        {
            EXPECT_EQ(m6.getValue(i, j), 5);

        }
    }
}
