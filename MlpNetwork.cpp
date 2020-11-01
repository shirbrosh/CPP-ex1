#include "MlpNetwork.h"

/**
 * The constructor for MlpNetwork class
 * @param weights- the weight Matrix
 * @param biases- the biases Matrix
 */
MlpNetwork::MlpNetwork(Matrix *weights, Matrix *biases) : dense1(Dense(weights[0], biases[0],
                                                                       Relu)),
                                                          dense2(Dense(weights[1], biases[1],
                                                                       Relu)),
                                                          dense3(Dense(weights[2],
                                                                       biases[2], Relu)),
                                                          dense4(Dense(weights[3], biases[3],
                                                                       Softmax))
{}

/**
 * This function is a a parenthesis operator for MlpNetwork object- applies the entire network on
 * the input and returns a digit struct
 * @param img- the input Matrix
 * @return digit struct with the digit in the input img
 */
Digit MlpNetwork::operator()(const Matrix &img)
{
    Matrix r4 = dense4(dense3(dense2(dense1(img))));
    unsigned int max_index = 0;
    float max_value = 0;
    for (
            int i = 0; i < r4.getCols() * r4.getRows(); i++)
    {
        if (r4[i] > max_value)
        {
            max_value = r4[i];
            max_index = i;
        }
    }
    return Digit{max_index, max_value};
}

