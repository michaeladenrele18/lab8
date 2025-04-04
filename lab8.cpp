#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

using Matrix = vector<vector<int>>;

// Function to print a matrix
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

// Function to read matrices from a file
bool readMatrices(const string& filename, Matrix& A, Matrix& B, int& N) {
    ifstream file(filename);
    if (!file) return false;

    file >> N;
    A.resize(N, vector<int>(N));
    B.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> A[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> B[i][j];

    return true;
}

// Function to add two matrices
Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix result(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

// Function to get the sum of diagonals
int sumDiagonals(const Matrix& A) {
    int N = A.size(), sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i][i]; // Main diagonal
        sum += A[i][N - 1 - i]; // Secondary diagonal
    }
    return sum;
}

// Function to swap two rows
void swapRows(Matrix& A, int r1, int r2) {
    if (r1 < A.size() && r2 < A.size())
        swap(A[r1], A[r2]);
}

// Function to swap two columns
void swapColumns(Matrix& A, int c1, int c2) {
    if (c1 < A.size() && c2 < A.size())
        for (auto& row : A)
            swap(row[c1], row[c2]);
}

// Function to update a matrix element
void updateMatrix(Matrix& A, int r, int c, int val) {
    if (r < A.size() && c < A.size())
        A[r][c] = val;
}

int main() {
    Matrix A, B;
    int N;
    string filename;

    cout << "Enter filename: ";
    cin >> filename;

    if (!readMatrices(filename, A, B, N)) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    cout << "\nMatrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);

    cout << "\nMatrix A + B:\n";
    printMatrix(addMatrices(A, B));

    cout << "\nMatrix A * B:\n";
    printMatrix(multiplyMatrices(A, B));

    cout << "\nSum of diagonals of Matrix A: " << sumDiagonals(A) << endl;

    cout << "\nSwapping row 0 and 1 in Matrix A:\n";
    swapRows(A, 0, 1);
    printMatrix(A);

    cout << "\nSwapping column 0 and 1 in Matrix A:\n";
    swapColumns(A, 0, 1);
    printMatrix(A);

    cout << "\nUpdating element at (0,0) in Matrix A to 99:\n";
    updateMatrix(A, 0, 0, 99);
    printMatrix(A);

    return 0;
}
