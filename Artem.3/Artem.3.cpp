#include <iostream>

//В каждой строке двумерного массива 
//размера(n, m), не содержащей отрицательных 
//элементов, найти минимальный элемент.Создать 
//одномерный массив найденных минимальных элементов.

using namespace std;

int main()
{
    int row;
    int column;
    cout << "Enter row matrix: ";
    cin >> row;
    cout << "Enter column matrix: ";
    cin >> column;
    cout << "Enter matrix: " << endl;
    int** matrix{ new int* [row] };
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[column];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
        }
    }
    //int* array{ new int[row] };
    for (int i = 0; i < row; i++) {
        int min = matrix[i][0];
        for (int j = 0; j < column; j++) {
            if (min > matrix[i][j])
                min = matrix[i][j];
        }
        cout << i << ": " << min << endl;
        //array[i] = min;
    }
    /*for (int i = 0; i < row; i++) {
        cout << array[i] << ' ';
    }*/
}