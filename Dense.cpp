#include "Dense.h"

/**
 * The constructor for Dense class
 * @param w- the weight Matrix
 * @param b- the bais Matrix
 * @param act- the ActivationType for this dense
 */
Dense::Dense(const Matrix &w, const Matrix &b, ActivationType act) : w(w), b(b),
                                                                     activation(Activation(act))
{}

/**
 * A getter function for the wights Matrix of the Dense object
 * @return- the wights Matrix of the Dense object
 */
Matrix Dense::getWeights() const
{
    return w;
}

/**
 * A getter function for the Bais Matrix of the Dense object
 * @return- the Bais Matrix of the Dense object
 */
Matrix Dense::getBais() const
{
    return b;
}


/**
 * A getter function for the Activation object of the Dense object
 * @return- the Activation object of the Dense object
 */
Activation Dense::getActivation() const
{
    return activation;
}

/**
 * This function is a a parenthesis operator for Dense object- applies the layer on input and
 * returns output matrix
 * @param x- the input Matrix
 * @return the output Matrix for applying the layer on x
 */
Matrix Dense::operator()(const Matrix &x) const
{
    Matrix forAction = (getWeights() * x) + getBais();
    return getActivation()(forAction);
}



