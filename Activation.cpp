#include "Activation.h"
#include <cmath>

#define ZERO_DIVISION_MSG "Error: zero division"
#define WRONG_DIMS_MSG "Error: wrong matrix dims"

/**
 * The constructor for Activation class
 * @param actType- an ActivationType object, which is indicator of activation function
 */
Activation::Activation(ActivationType actType) : act(actType)
{}

/**
 * A getter function for the actType of the Activation object
 * @return the actType of the Activation object
 */
ActivationType Activation::getActivationType() const
{
    return act;
}

/**
 * This function is a parenthesis operator for Activation object- applies activation
 * function on input
 * @param m- the Matrix object input
 * @return the result matrix after applying activation function
 */
Matrix Activation::operator()(const Matrix &m)
{
    if (m.getCols() != 1)
    {
        std::cerr << WRONG_DIMS_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix result(m);
    int N = m.getRows() * m.getCols();

    //in case the type is Relu
    if (getActivationType() == Relu)
    {
        for (
                int i = 0; i < N; i++)
        {
            if (m[i] < 0)
            {
                result[i] = 0;
            }
            else
            {
                result[i] = m[i];
            }
        }
    }

        //in case the type is Softmax
    else if (getActivationType() == Softmax)
    {
        float norm = 0;
        for (
                int i = 0; i < N; i++)
        {
            result[i] = std::exp(m[i]);
            norm += result[i];
        }
        if (norm == 0)
        {
            std::cerr << ZERO_DIVISION_MSG << std::endl;
            exit(EXIT_FAILURE);
        }
        result = ((float) (1.f / norm)) * result;
    }
    return result;
}

