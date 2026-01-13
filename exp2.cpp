#include <iostream>
using namespace std;

int main() {
    int r, c, choice;
    int A[10][10], B[10][10], R[10][10];

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter elements of matrix A:\n";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B:\n";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> B[i][j];

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Transpose of A";
        cout << "\n5. Identity Matrix";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:   // Addition
                cout << "Result of Addition:\n";
                for(int i = 0; i < r; i++) {
                    for(int j = 0; j < c; j++) {
                        R[i][j] = A[i][j] + B[i][j];
                        cout << R[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 2:   // Subtraction
                cout << "Result of Subtraction:\n";
                for(int i = 0; i < r; i++) {
                    for(int j = 0; j < c; j++) {
                        R[i][j] = A[i][j] - B[i][j];
                        cout << R[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3:   // Multiplication
                if(r != c) {
                    cout << "Multiplication not possible\n";
                    break;
                }

                cout << "Result of Multiplication:\n";
                for(int i = 0; i < r; i++) {
                    for(int j = 0; j < c; j++) {
                        R[i][j] = 0;
                        for(int k = 0; k < c; k++)
                            R[i][j] += A[i][k] * B[k][j];
                        cout << R[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 4:   // Transpose
                cout << "Transpose of Matrix A:\n";
                for(int i = 0; i < c; i++) {
                    for(int j = 0; j < r; j++)
                        cout << A[j][i] << " ";
                    cout << endl;
                }
                break;

            case 5:   // Identity Matrix
                if(r != c) {
                    cout << "Identity matrix possible only for square matrix\n";
                    break;
                }

                cout << "Identity Matrix:\n";
                for(int i = 0; i < r; i++) {
                    for(int j = 0; j < c; j++) {
                        if(i == j)
                            cout << "1 ";
                        else
                            cout << "0 ";
                    }
                    cout << endl;
                }
                break;

            case 6:
                cout << "Exiting program";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 6);

    return 0;
}
