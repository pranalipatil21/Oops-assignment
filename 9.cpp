// Write a C++ program to implement the matrix ADT using a class. The operations supported by this ADT
are:
/*a) Reading a matrix.
b) Addition of matrices.
c) Printing a matrix.
d) Subtraction of matrices.
e) Multiplication of matrices*/



#include <iostream>
using namespace std;

class Matrix
{
  int mat[2][2];
  int res[2][2];

public:
    void readMatrix() {
        cout << "Enter the elements of the matrix row by row:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> mat[i][j];
            }
        }
    }

    Matrix operator+(Matrix x) {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.mat[i][j] = mat[i][j] + x.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix x) {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.mat[i][j] = mat[i][j] - x.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix x) {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.mat[i][j] += mat[i][k] * x.mat[k][j];
                }
            }
        }
        return result;
    }

    void printMatrix() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int choice;
    Matrix matrix1;
    Matrix matrix2;

    do {
        cout << "\nMenu:\n";
        cout << "1. Read Matrix 1\n";
        cout << "2. Read Matrix 2\n";
        cout << "3. Add Matrices\n";
        cout << "4. Subtract Matrices\n";
        cout << "5. Multiply Matrices\n";
        cout << "6. Print Matrix 1\n";
        cout << "7. Print Matrix 2\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                matrix1.readMatrix();
                break;
            case 2:
                matrix2.readMatrix();
                break;
            case 3: {
                Matrix sum = matrix1 + matrix2;
                sum.printMatrix();
                break;
            }
            case 4: {
                Matrix difference = matrix1 - matrix2;
                difference.printMatrix();
                break;
            }
            case 5: {
                Matrix product = matrix1 * matrix2;
                product.printMatrix();
                break;
            }
            case 6:
                matrix1.printMatrix();
                break;
            case 7:
                matrix2.printMatrix();
                break;
            case 8:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
