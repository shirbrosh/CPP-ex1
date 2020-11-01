#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Dense.h"
#include "Digit.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784},
                                  {64,  128},
                                  {20,  64},
                                  {10,  20}};
const MatrixDims biasDims[] = {{128, 1},
                               {64,  1},
                               {20,  1},
                               {10,  1}};

/**
 * A MlpNetwork object class
 */
class MlpNetwork
{
public:
    /**
     * The constructor for MlpNetwork class
     * @param weights- the weight Matrix
     * @param biases- the biases Matrix
     */
    MlpNetwork(Matrix *weights, Matrix *biases);

    /**
     * This function is a a parenthesis operator for MlpNetwork object- applies the entire network on
     * the input and returns a digit struct
     * @param img- the input Matrix
     * @return digit struct with the digit in the input img
     */
    Digit operator()(const Matrix &img);

private:
    Dense dense1;
    Dense dense2;
    Dense dense3;
    Dense dense4;

};

#endif // MLPNETWORK_H
