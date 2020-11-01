#ifndef CPP_EX1_DENSE_H
#define CPP_EX1_DENSE_H

#include "Activation.h"

/**
 * A Dense object class
 */
class Dense
{
public:
    /**
     * The constructor for Dense class
     * @param w- the weight Matrix
     * @param b- the bais Matrix
     * @param act- the ActivationType for this dense
     */
    Dense(const Matrix &w, const Matrix &b, ActivationType act);

    /**
     * A getter function for the wights Matrix of the Dense object
     * @return- the wights Matrix of the Dense object
     */
    Matrix getWeights() const;

    /**
     * A getter function for the Bais Matrix of the Dense object
     * @return- the Bais Matrix of the Dense object
     */
    Matrix getBais() const;

    /**
     * A getter function for the Activation object of the Dense object
     * @return- the Activation object of the Dense object
     */
    Activation getActivation() const;

    /**
     * This function is a a parenthesis operator for Dense object- applies the layer on input and
     * returns output matrix
     * @param x- the input Matrix
     * @return the output Matrix for applying the layer on x
     */
    Matrix operator()(const Matrix &x) const;

private:
    Matrix w;
    Matrix b;
    Activation activation;
};


#endif //CPP_EX1_DENSE_H
