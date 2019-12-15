//
// Created by а on 15.12.2019.
//

#include "matrix_tests.h"
#include "../matrix.h"
#include <math.h>

void testMatrixCreation() {
    struct SquareMatrix m = initMatrix(5);

    if (m.matrix == NULL) {
        printf("testMatrixCreation: FAILED. Memory is not allocated. \n");
    } else if (m.size != 5) {
        printf("testMatrixCreation: FAILED. Size is incorrect. \n");
    } else {
        printf("testMatrixCreation: PASSED. \n");
    }
}

void testGetColumn() {
    struct SquareMatrix m = initMatrix(3);

    int counter = 0;
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            m.matrix[i][j] = counter;
            ++counter;
        }
    }

    struct Vector expected = initVector(m.size);
    expected.vector[0] = 2;
    expected.vector[1] = 5;
    expected.vector[2] = 8;

    struct Vector result = getColumn(m, 1);

    double epsilon = 10e-6;
    for (int i = 0; i < expected.size; ++i) {
        if (fabs(expected.vector[i] - result.vector[i]) < epsilon) {
            printf("testGetColumn: FAILED. At index %d result %lf != expected %lf",
                   i, result.vector[i], expected.vector[i]);
            return;
        }
    }
    printf("testGetColumn: PASSED.");
}

void testGetRow() {
    struct SquareMatrix m = initMatrix(3);

    int counter = 0;
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            m.matrix[i][j] = counter;
            ++counter;
        }
    }

    struct Vector expected = initVector(m.size);
    expected.vector[0] = 4;
    expected.vector[1] = 5;
    expected.vector[2] = 6;

    struct Vector result = getRow(m, 1);

    double epsilon = 10e-6;
    for (int i = 0; i < expected.size; ++i) {
        if (fabs(expected.vector[i] - result.vector[i]) < epsilon) {
            printf("testGetRow: FAILED. At index %d result %lf != expected %lf",
                   i, result.vector[i], expected.vector[i]);
            return;
        }
    }
    printf("testGetRow: PASSED.");
}

void matrixTestSuite() {
    for (int i = 0; i < 40; ++i) putchar('-');
    printf("\nMatrix tests:\n\n");
    testMatrixCreation();
    testGetRow();
    testGetColumn();
}