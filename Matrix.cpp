#include <fstream>
#include <string>
#include "Matrix.h"
#include <cstring>

#define NULL_MSG "Error: could not create matrix"
#define WRONG_DIMS_MSG "Error: wrong matrix dims"
#define WRONG_FILE_MSG "Error: file problem"
#define SPACE " "
#define DEFAULT_SIZE 1


/**
 * The constructor for Matrix class
 * @param rows- the value for "rows" field in the matrix's matDim field
 * @param cols- the value for "cols" field in the matrix's matDim field
 */
Matrix::Matrix(int rows, int cols) : row(rows), col(cols)
{
    if (row <= 0 || col <= 0)
    {
        std::cerr << WRONG_DIMS_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    matrix = new(std::nothrow) float[row * col]();
    if (matrix == nullptr)
    {
        std::cerr << NULL_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * The default constructor for Matrix class- inserts the value 1 for rows&cols
 */
Matrix::Matrix() : Matrix(DEFAULT_SIZE, DEFAULT_SIZE)
{
}

/**
 * The copy constructor for Matrix class
 * @param m- the Matrix object to copy from
 */
Matrix::Matrix(const Matrix &m)
{
    row = m.getRows();
    col = m.getCols();
    matrix = new(std::nothrow) float[row * col]();
    if (matrix == nullptr)
    {
        std::cerr << NULL_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    for (
            int i = 0; i < row * col; i++)
    {
        matrix[i] = m.matrix[i];
    }
}

/**
 * The destructor for Matrix class
 */
Matrix::~Matrix()
{
    if (matrix == nullptr)
    {
        std::cerr << NULL_MSG << std::endl;
    }
    delete[]matrix;
}

/**
 * A getter function for the Matrix object rows length
 * @return- the Matrix object rows length
 */
int Matrix::getRows() const
{
    return row;
}

/**
 * A getter function for the Matrix object cols length
 * @return- the Matrix object cols length
 */
int Matrix::getCols() const
{
    return col;
}

/**
 * This function converts the matrix's dims into a column vector
 * @return- a reference for the Matrix object
 */
Matrix &Matrix::vectorize()
{
    row = row * col;
    col = DEFAULT_SIZE;
    return *this;
}

/**
 * This function prints the matrix's elements
 */
void Matrix::plainPrint() const
{
    for (
            int i = 0; i < row * col; i++)
    {
        std::cout << (*this)[i] << SPACE;
        if ((i + 1) % getCols() == 0)
        {
            std::cout << std::endl;
        }
    }
}

/**
 * This function is an assignment operator for Matrix object
 * @param m- the matrix to assignment
 * @return a reference for Matrix object after being assigned with the given matrix
 */
Matrix &Matrix::operator=(const Matrix &m)
{
    if (this == &m)
    {
        return *this;
    }
    delete[]matrix;
    row = m.getRows();
    col = m.getCols();
    matrix = new(std::nothrow) float[row * col];
    if (matrix == nullptr)
    {
        std::cerr << NULL_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    for (
            int i = 0; i < row * col; i++)
    {
        matrix[i] = m[i];
    }
    return *this;
}

/**
 * This function is a matrix multiplication operator for Matrix object
 * @param m- the matrix to multiply our current matrix
 * @return the matrix after being multiply by matrix b
 */
Matrix Matrix::operator*(const Matrix &m) const
{
    if (getCols() != m.getRows())
    {
        std::cerr << WRONG_DIMS_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix result(getRows(), m.getCols());
    for (
            int i = 0; i < getRows(); i++)
    {
        for (
                int j = 0; j < m.getCols(); j++)
        {
            for (
                    int k = 0; k < getCols(); k++)
            {
                result(i, j) +=
                        ((*this)(i, k) * m(k, j));
            }
        }
    }
    return result;
}

/**
 * This function is a scalar multiplication on the right operator for Matrix object
 * @param b- the scalar to multiply our current matrix
 * @return the matrix after being multiply by the scalar b
 */
Matrix Matrix::operator*(const float b) const
{
    Matrix result(*this);
    for (
            int i = 0; i < row * col; i++)
    {
        result[i] = b * (*this)[i];
    }
    return result;
}

/**
 * This function is a scalar multiplication on the left operator for Matrix object
 * @param b- the scalar to multiply the matrix
 * @param m- the matrix to multiply
 * @return the matrix after being multiply by the scalar b
 */
Matrix operator*(const float b, const Matrix &m)
{
    return m * b;
}

/**
 * This function is a matrix addition operator for Matrix object
 * @param b- the matrix to add
 * @return the result matrix for adding b
 */
Matrix Matrix::operator+(const Matrix &b) const
{
    if (getRows() != b.getRows() || getCols() != b.getCols())
    {
        std::cerr << WRONG_DIMS_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix result = Matrix(row, col);
    for (
            int i = 0; i < b.getRows() * b.getCols(); i++)
    {
        result[i] = (*this)[i] + b[i];
    }
    return result;
}

/**
 * This function is a matrix addition accumulation operator for Matrix object
 * @param b- the matrix to add
 * @return the result matrix for adding b
 */
void Matrix::operator+=(const Matrix &b)
{
    (*this) = (*this) + b;
}

/**
 * This function is a parenthesis indexing operator for Matrix object
 * @param i- the row index to return
 * @param j- the column index to return
 * @return- the index in the matrix matching the row-i and the column-j
 */
float &Matrix::operator()(const int i, const int j) const
{
    if (i >= getRows() || j >= getCols() || i < 0 || j < 0)
    {
        std::cerr << WRONG_DIMS_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix[i * getCols() + j];
}

/**
 * This function is a brackets indexing operator for Matrix object
 * @param i- the index in the matrix to return
 * @return the i'th element in the matrix
 */
float &Matrix::operator[](const int i) const
{
    if (i >= getRows() * getCols() || i < 0)
    {
        std::cerr << WRONG_DIMS_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix[i];
}


/**
 * This function is an input stream operator for Matrix object- fills a matrix with the given stream
 * @param f- the stream
 * @param m- the matrix to fill
 * @return the stream
 */
std::istream &operator>>(std::istream &f, Matrix &m)
{
    long unsigned int mat_len = m.getRows() * m.getCols();
    if (!f.good())
    {
        std::cerr << WRONG_FILE_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    //find the file length:
    long unsigned int begin = f.tellg();
    f.seekg(0, std::ios::end);
    long unsigned int end = f.tellg();
    long unsigned int f_len = end - begin;

    //check if the length is valid
    if (f_len / sizeof(float) != mat_len)
    {
        std::cerr << WRONG_FILE_MSG << std::endl;
        exit(EXIT_FAILURE);
    }

    f.seekg(0, std::ios::beg);
    f.read((char *) m.matrix, sizeof(float) * mat_len);
    return f;
}

/**
 * This function is an output stream operator for Matrix object- export of the matrix
 * @param f- the stream
 * @param m- the matrix to export
 * @return the stream
 */
std::ostream &operator<<(std::ostream &f, Matrix &m)
{
    for (
            int i = 0; i < m.getRows() * m.getCols(); i++)
    {
        if (m[i] <= 0.1f)
        {
            f << "  ";
        }
        else
        {
            f << "**";
        }
        if ((i + 1) % m.getCols() == 0)
        {
            f << std::endl;
        }
    }
    return f;
}
