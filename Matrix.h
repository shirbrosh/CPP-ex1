// Matrix.h
#include <iostream>
#include <string>

#ifndef MATRIX_H
#define MATRIX_H


/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;

} MatrixDims;

/**
 * A Matrix object class
 */
class Matrix
{
public:

    /**
    * The constructor for Matrix class
    * @param rows- the value for "rows" field in the matrix's matDim field
    * @param cols- the value for "cols" field in the matrix's matDim field
    */
    Matrix(int rows, int cols);

    /**
    * The default constructor for Matrix class- inserts the value 1 for rows&cols
    */
    Matrix();

    /**
     * The copy constructor for Matrix class
     * @param m- the Matrix object to copy from
     */
    Matrix(const Matrix &m);

    /**
     * The destructor for Matrix class
     */
    ~Matrix();

    /**
     * A getter function for the Matrix object rows length
     * @return- the Matrix object rows length
     */
    int getRows() const;

    /**
     * A getter function for the Matrix object cols length
     * @return- the Matrix object cols length
     */
    int getCols() const;

    /**
     * This function converts the matrix's dims into a column vector
     * @return- a reference for the Matrix object
     */
    Matrix &vectorize();

    /**
     * This function prints the matrix's elements
     */
    void plainPrint() const;

    /**
     * This function is an assignment operator for Matrix object
     * @param m- the matrix to assignment
     * @return a reference for Matrix object after being assigned with the given matrix
     */
    Matrix &operator=(const Matrix &m);

    /**
     * This function is a matrix multiplication operator for Matrix object
     * @param m- the matrix to multiply our current matrix
     * @return the matrix after being multiply by matrix b
     */
    Matrix operator*(const Matrix &m) const;

    /**
     * This function is a scalar multiplication on the right operator for Matrix object
     * @param b- the scalar to multiply our current matrix
     * @return the matrix after being multiply by the scalar b
     */
    Matrix operator*(const float b) const;

    /**
     * This function is a scalar multiplication on the left operator for Matrix object
     * @param b- the scalar to multiply the matrix
     * @param m- the matrix to multiply
     * @return the matrix after being multiply by the scalar b
     */
    friend Matrix operator*(const float b, const Matrix &m);

    /**
     * This function is a matrix addition operator for Matrix object
     * @param b- the matrix to add
     * @return the result matrix for adding b
     */
    Matrix operator+(const Matrix &b) const;

    /**
     * This function is a matrix addition accumulation operator for Matrix object
     * @param b- the matrix to add
     * @return the result matrix for adding b
     */
    void operator+=(const Matrix &b);

    /**
     * This function is a parenthesis indexing operator for Matrix object
     * @param i- the row index to return
     * @param j- the column index to return
     * @return- the index in the matrix matching the row-i and the column-j
     */
    float &operator()(const int i, const int j) const;

    /**
     * This function is a brackets indexing operator for Matrix object
     * @param i- the index in the matrix to return
     * @return the i'th element in the matrix
     */
    float &operator[](const int i) const;

    /**
     * This function is an input stream operator for Matrix object- fills a matrix with the given stream
     * @param f- the stream
     * @param m- the matrix to fill
     * @return the stream
     */
    friend std::istream &operator>>(std::istream &f, Matrix &m);

    /**
     * This function is an output stream operator for Matrix object- export of the matrix
     * @param f- the stream
     * @param m- the matrix to export
     * @return the stream
     */
    friend std::ostream &operator<<(std::ostream &f, Matrix &m);

private:
    int row, col;
    float *matrix;

};


#endif //MATRIX_H
