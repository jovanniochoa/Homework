#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_SIZE = 21;
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName);
void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size);
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size);
int squareright()
{
    int square[MAX_SIZE][MAX_SIZE];
    string inputFileName;
    cout << "Enter the filename :";
    cin >> inputFileName;
    int size = readSquare(square, inputFileName);
    displaySquare(square, size);
    bool b = validateSquare(square, size);
    if (b) {
        cout << "Valid magic square" << endl;
    }
    else {
        cout << "Invalid magic square" << endl;
    }
    return 0;
}
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName)
{
    https://defines an input stream for the data file
    ifstream dataIn;
    int size;
    https://Opening the input file
    dataIn.open(inputFileName.c_str());
    https://checking whether the file name is valid or not
    if (dataIn.fail()) {
        cout << "**  File Not Found  **";
        return 0;
    }
    else {
        dataIn >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                dataIn >> square[i][j];
            }
        }
        https://Closing the intput file
        dataIn.close();
    }
    return size;
}
void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size)
{
    cout << "Magic Square" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }
}
https://This function will check whether the square is magic square or not
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size)
{
    int n = 1;
    int flag = 0;
    int val = size * (size * size + 1) / 2;
    /* this block of nested for loop will check
 * whether the square contains the numbers
 * between the range
 */
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (square[i][j] < 1 && square[i][j] > val)
                return false;
        }
    }
    /* this block of nested for loop will check
 * whether the square contains the unique numbers
 * between the range
 */
    for (int i = 0; i < size * size; i++) {
        flag = 0;
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (square[j][k] == n) {
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            return false;
        }
        else {
            n++;
        }
    }
    https:// Creating arrays and declaring variables
    int sumDiag[2], sumCol = 0, sumRow = 0, roww[size], coll[size];
    https:// Calculating the sum of each row
    for (int row = 0; row < size; row++) {
        sumRow = 0;
        for (int col = 0; col < size; col++) {
            sumRow += square[row][col];
            roww[row] = sumRow;
        }
    }
    https:// calculating the Sum of Each column
    for (int col = 0; col < size; col++) {
        sumCol = 0;
        for (int row = 0; row < size; row++) {
            sumCol += square[row][col];
            coll[col] = sumCol;
        }
    }
    sumDiag[0] = 0;
    https:// calculating the Sum of Diagonal0
    for (int row = 0; row < size; row++) {
        sumDiag[0] += square[row][row];
    }
    sumDiag[1] = 0;
    https:// calculating the Sum of Diagonal 1
    for (int row = 0; row < size; row++) {
        sumDiag[1] += square[row][size - 1 - row];
    }
    /* checking whether sum of elements in each row,each column
         * and each diagonal are equal or not
     * If yes, The square array is Magic Square
     * if not, The square array is not Magic Square
     */
    bool boolean = true;
    int sum = roww[0];
    for (int i = 1; i < size; i++) {
        boolean = boolean && (sum == roww[i]);
    }
    for (int i = 0; i < size; i++) {
        boolean = boolean && (sum == coll[i]);
    }
    for (int i = 0; i < 2; i++) {
        boolean = boolean && (sum == sumDiag[i]);
    }
    if (boolean) {
        return true;
    }
    else {
        return false;
    }
}

