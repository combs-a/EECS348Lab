#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global variables.
const int MAX_SIZE = 100;
const string FILENAME = "matrix_input.txt"; // This name shouldn't change, according to the constraints.

// Functional prototypes.
void readFromInput(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int &size);
void printMatrices(int matrix[MAX_SIZE][MAX_SIZE], int size);
void matrixAdd(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int size);
void matrixMultiply(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int size);
void matrixSub(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int size);

// Functions and their definitions start here.
int main()
{
    // Create variables.
    int size;
    int matrix_a[MAX_SIZE][MAX_SIZE]; // Set to 100 since the max amount of items is 100.
    int matrix_b[MAX_SIZE][MAX_SIZE];

    // Read inputs.
    readFromInput(matrix_a, matrix_b, size);

    // Print initial matrices.
    cout << "Matrix A:" << endl;
    printMatrices(matrix_a, size);

    cout << "Matrix B:" << endl;
    printMatrices(matrix_b, size);

    // Get the sum of the two matrices.
    matrixAdd(matrix_a, matrix_b, size);

    // Get the product of the two matrices.
    matrixMultiply(matrix_a, matrix_b, size);

    // Get the difference of the two matrices.
    matrixSub(matrix_a, matrix_b, size);

    return 0;
}

void readFromInput(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int &size) {
    ifstream matfile(FILENAME);

    if (!matfile) // Error check
    {
        cerr << "Error opening file: " << FILENAME << endl;
        exit(1);
    }

    matfile >> size; // Get the size from the first line of the file.

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matfile >> matrix_a[i][j];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matfile >> matrix_b[i][j];
        }
    }

    matfile.close();
}

void printMatrices(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    // Generalized this function for use with any matrix.
    // This makes the initial print statement (i.e. Matrix A:) have to be done outside the function.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << "\t" ;
        }
        cout << endl;
    }

    cout << endl; // Add extra whitespace at end of matrix.
}

void matrixAdd(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int size)
{
    // Add two given matrices.
    // Start by creating a matrix to print later on.
    int result_matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    cout << "Matrix Sum (A+B):" << endl;
    printMatrices(result_matrix, size);
}

void matrixMultiply(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int size)
{
    // Add two given matrices.
    // Start by creating a matrix to print later on.
    int result_matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result_matrix[i][j] = matrix_a[i][j] * matrix_b[i][j]; // TODO: adjust this; this is normal multiplication and not matrix.
        }
    }

    cout << "Matrix Product (A*B):" << endl;
    printMatrices(result_matrix, size);
}

void matrixSub(int matrix_a[MAX_SIZE][MAX_SIZE], int matrix_b[MAX_SIZE][MAX_SIZE], int size)
{
    // Add two given matrices.
    // Start by creating a matrix to print later on.
    int result_matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result_matrix[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }

    cout << "Matrix Difference (A-B):" << endl;
    printMatrices(result_matrix, size);
}