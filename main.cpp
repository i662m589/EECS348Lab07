#include <fstream>
#include <iostream>
using namespace std;
const int SIZE = 4; // Global variable for matrix size
class Matrix {
    private:
        int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
    public:
// 1. Read values from stdin into a matrix
        void readFromStdin() {
            static int counter = 0;
            ifstream file("matrix-data.txt");
            if (counter == 0) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        file >> data[i][j];
                    }
                }
            }
            //If the counter is at 0, this part of the method will read the first four lines and input those values into the matrix.
            else {
                for (int m = 0; m < SIZE; m++) {
                    file.ignore(65536,'\n');
                }
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        file >> data[i][j];
                    }
                }
            }
            //If the counter is greater than 0, this part of the method will skip the first four lines and read lines 5-8 and input those value into the matrix.
            counter += 1;
            //Everytime the method completes, the counter variable goes up by one. 
        };
// 2. Display a matrix
        void display() const {
            for (int g = 0; g < SIZE; g++) {
                for (int h = 0; h < SIZE; h++) {
                    cout << data[g][h] << " ";
                }
                cout << endl;
            }
            //This method indexes through and prints out the matrix into a format that is easily readable.
        };
// 3. Add two matrices (operator overloading for +)
        Matrix operator+(const Matrix& other) const {
            Matrix temp;
            for (int m = 0; m < SIZE; m++) {
                for (int n = 0; n < SIZE; n++) {
                    temp.data[m][n] = data[m][n] + other.data[m][n];
                }
            }
            return temp;
            //This operator overloading adds the values of each position of two matrices and returns one matrix that is the sum of the two that were inputted.
        };
// 4. Multiply two matrices (operator overloading for *)
        Matrix operator*(const Matrix& other) const {
            Matrix temp;
            for (int r = 0; r < SIZE; r++) {
                for (int s = 0; s < SIZE; s++) {
                    for (int t = 0; t < SIZE; t++) {
                        temp.data[r][s] += data[r][t] * other.data[t][s];
                    }
                }
            }
            return temp;
            //This operator overloading multiplies the values of each position of two matrices and returns one matrix that is the product of the two that were inputted.
        };
// 5. Compute the sum of matrix diagonal elements
        int sumOfDiagonals() const {
            int main_sum = 0;
            int sec_sum = 0;
            for (int x = 0; x < SIZE; x++){
                main_sum += data[x][x];
            }
            for(int i = 0, j = SIZE - 1; i < SIZE; ++i, --j) {
                sec_sum += data[i][j];
            }
            return main_sum + sec_sum;
            //This method finds the indexes of the main diagonals and the secondary diagonals and adds up those indexes to return the sum of the diagonals.
        };
// 6. Swap matrix rows
        void swapRows(int row1, int row2) {
            if (0 <= row1 && row1 < SIZE && 0 <= row2 && row2 < SIZE) {
                for (int u = 0; u < SIZE; u++) {
                    int tmp = data[row1][u];
                    data[row1][u] = data[row2][u];
                    data[row2][u] = tmp;
                }
            } else {
                cout << "Invalid Indices to swap rows" << endl;
            }
            //This method checks the indices and swaps the matrix's rows at those indices if they are valid. If they are invalid, the program will print to the user that they are invalid.
        };
};

int main() {
// Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    //This code runs the readFromStdin method to read the file and input values into Matrix 1.
    cout << "Matrix 1:" << endl;
    mat1.display();
    //This code runs the display method to display matrix 1 to the user.
    Matrix mat2;
    cout << endl << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    //This code uses the readFromStdin method to read the file and input values into Matrix 2.
    cout << "Matrix 2:" << endl;
    mat2.display();
    //This code runs the display method to display matrix 2 to the user.
    Matrix sum = mat1 + mat2;
    cout << endl << "Sum of matrices:" << endl;
    sum.display();
    //This code uses operator overloading of matrices to make a new object that is the sum of matrices' 1 and 2. It then uses the display method to display the new matrix to the user.
    Matrix product = mat1 * mat2;
    cout << endl << "Product of matrices:" << endl;
    product.display();
    //This code uses operator overloading of matrices to make a new object that is the product of matrices' 1 and 2. It then uses the display method to display the new matrix to the user.
    cout << endl << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    //This code utilizes the sumofDiagonals method to find and display an integer to the user that is the sum of the main and secondary diagonals of matrix 1.
    mat1.swapRows(0, 2);
    cout << endl << "Matrix 1 after swapping rows 0 and 2:" << endl;
    mat1.display();
    //This code uses the swapRows method and swaps the first and third rows of matrix 1 before displaying the swapped matrix 1 to the user.
    return 0;
    //This is the return value for the main() function.
}
