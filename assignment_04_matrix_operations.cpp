// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int source[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[j][i] = source[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];

    int rows, cols;

    // Part A: Transpose a matrix
    cout << "Part A - Transpose a Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    readMatrix(matrixA, rows, cols);
    transposeMatrix(matrixA, result, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);
    cout << endl;

    // Part B: Add two matrices
    cout << "Part B - Add Two Matrices" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    cout << "Enter values for Matrix A:" << endl;
    readMatrix(matrixA, rows, cols);
    cout << "Enter values for Matrix B:" << endl;
    readMatrix(matrixB, rows, cols);

    addMatrices(matrixA, matrixB, result, rows, cols);

    cout << "\nMatrix A:" << endl;
    printMatrix(matrixA, rows, cols);
    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, rows, cols);
    cout << "\nSum Matrix:" << endl;
    printMatrix(result, rows, cols);
    cout << endl;

    // Part C: Multiply two matrices
    int rowsA, colsA, rowsB, colsB;
    cout << "Part C - Multiply Two Matrices" << endl;
    cout << "Enter number of rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for Matrix A: ";
    cin >> colsA;
    cout << "Enter number of rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB;

    if (rowsA <= 0 || rowsA > 10 || colsA <= 0 || colsA > 10 || rowsB <= 0 || rowsB > 10 || colsB <= 0 || colsB > 10)
    {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    if (colsA != rowsB)
    {
        cout << "Error: Number of columns in Matrix A must equal number of rows in Matrix B." << endl;
        return 0;
    }

    cout << "Enter values for Matrix A:" << endl;
    readMatrix(matrixA, rowsA, colsA);
    cout << "Enter values for Matrix B:" << endl;
    readMatrix(matrixB, rowsB, colsB);

    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);

    cout << "\nMatrix A:" << endl;
    printMatrix(matrixA, rowsA, colsA);
    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, rowsB, colsB);
    cout << "\nProduct Matrix:" << endl;
    printMatrix(result, rowsA, colsB);

    return 0;
}

