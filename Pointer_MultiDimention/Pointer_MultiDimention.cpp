#include <iostream>
using namespace std;
const int MATRIX_HEIGHT = 5;
const int MATRIX_WIDTH = 3;

int DimentionSum(const int* data, int count) {
    int s = 0;
    for (int i = 0; i < count; i++) {
        s += *(data + i);
    }
    return s;
}

int main()
{
    int matrix[MATRIX_HEIGHT][MATRIX_WIDTH]
        = {
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {10,11,12},
            {13,14,15}
    };
    int s = 0;
    /*for (int i = 0; i < MATRIX_HEIGHT; i++) {
        for (int j = 0; j < MATRIX_WIDTH; j++) {
            s += matrix[i][j];
        }
    }
    for (int i = 0; i < MATRIX_HEIGHT* MATRIX_WIDTH; i++) {
            s += matrix[0][i];
    }
    */
    s = DimentionSum(&matrix[0][0], MATRIX_HEIGHT * MATRIX_WIDTH);
    cout << s << endl;

    return 0;
}
