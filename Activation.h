//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

/**
 * A Activation object class
 */
class Activation
{
public:
    /**
     * The constructor for Activation class
     * @param actType- an ActivationType object, which is indicator of activation function
     */
    Activation(ActivationType actType);

    /**
     * A getter function for the actType of the Activation object
     * @return the actType of the Activation object
     */
    ActivationType getActivationType() const;

    /**
     * This function is a parenthesis operator for Activation object- applies activation
     * function on input
     * @param m- the Matrix object input
     * @return the result matrix after applying activation function
     */
    Matrix operator()(const Matrix &m);

private:
    ActivationType act;
};

#endif //ACTIVATION_H
