#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

/*
•	не создавать для хранения цифр числа массив;
•	 не задавать число как символьный массив;
•	не использовать объекты класса string;
•	не использовать стандартные функции.
*/

/*
В двумерном массиве размера (n,m) удалить строки, все элементы
которых равны нулю. Оставшиеся строки массива расположить в порядке убывания
максимальных элементов в строках. Можно создать дополнительный одномерный массив
массив максимальных элементов в строках.
*/

void FillArrayConsole(int** array, int rowArray, int columnArray);
void FillArrayRandDigit(int** array, int rowArray, int columnArray);
void OutputArray(int** array, int rowArray, int columnArray);
void EditElementInArray(int** array, int rowArray, int columnArray);
int RemoveNullRow(int** array, int rowArray, int columnArray);
int RemoveRow(int** array, int rowArray, int columnArray);
void RemoveRow(int** array, int rowArray, int columnArray, int numberRow);
int RemoveColumn(int** array, int rowArray, int columnArray);
void FillRowNull(int** array, int rowArray, int columnArray);
void FillColumnNull(int** array, int rowArray, int columnArray);
void SwapRow(int** array, int rowArray, int columnArray, int numberRow);
void SordRow(int** array, int rowArray, int columnArray);

int main()
{
    int columnArray = 0;
    cout << "Введите количество столбцов\n";
    cin >> columnArray;

    int rowArray = 0;
    cout << "Введите количество строк\n";
    cin >> rowArray;

    int** array{ new int* [rowArray] {} };
    for (int i = 0; i < rowArray; i++) {
        array[i] = new int[columnArray] {};
    }
    bool exit = false;
    while (!exit) {
        int input;
        system("cls");
        cout << "Меню:" << endl;
        cout << "1 - Ввести матрицу через консоль\n"
            << "2 - Ввести матрицу рандомно\n"
            << "3 - Вывести матрицу\n"
            << "4 - Редактировать один элемент матрицы\n"
            << "5 - Удалить нулевые строки\n"
            << "6 - Отсортировать строки массива\n"
            << "7 - Удалить строку массива\n"
            << "8 - Удалить столбец массива\n"
            << "9 - Заполнить строку нулями\n"
            << "10 - Заполнить столбцы нулями\n"
            << "0 - Выход\n";
        cin >> input;
        switch (input)
        {
        case 1:
            FillArrayConsole(array, rowArray, columnArray);
            break;
        case 2:
            FillArrayRandDigit(array, rowArray, columnArray);
            break;
        case 3:
            while (!exit) {
                system("cls");
                OutputArray(array, rowArray, columnArray);
                cout << "Введите Y для выхода" << endl;
                char input;
                cin >> input;
                if (input == 'Y')
                    exit = true;
            }
            exit = false;
            break;
        case 4:
            EditElementInArray(array, rowArray, columnArray);
            break;
        case 5:
            rowArray = RemoveNullRow(array, rowArray, columnArray);
            break;
        case 6:
            SordRow(array, rowArray, columnArray);
            break;
        case 7:
            rowArray = RemoveRow(array, rowArray, columnArray);
            break;
        case 8:
            columnArray = RemoveColumn(array, rowArray, columnArray);
            break;
        case 9:
            FillRowNull(array, rowArray, columnArray);
            break;
        case 10:
            FillColumnNull(array, rowArray, columnArray);
            break;
        case 0:
            input = 0;
            exit = true;
            break;
        }
    }
}
void SordRow(int** array, int rowArray, int columnArray) {
    system("cls");
    cout << "Матрица:" << endl;
    OutputArray(array, rowArray, columnArray);
    char inputExit = 'C';
    cout << "Введите C для продолжения" << endl;
    cout << "Введите E для выхода" << endl;
    cin >> inputExit;
    if (inputExit == 'E') {
        return;
    }
    int maxDigitInTopArray = 0;
    int maxDigitInUnderArray = 0;
    for (int k = (rowArray - 1); k >= 0; k--) {
        for (int i = (rowArray - 1); i >= 0; i--) {
            for (int j = 0; j < columnArray; j++) {
                if (array[i][j] > maxDigitInTopArray) {
                    maxDigitInTopArray = array[i][j];
                }
            }
            if (maxDigitInTopArray < maxDigitInUnderArray && i != (rowArray - 1)) {
                SwapRow(array, rowArray, columnArray, i);
                OutputArray(array, rowArray, columnArray);
            }
            maxDigitInUnderArray = maxDigitInTopArray;
            maxDigitInTopArray = 0;
        }
    }
    cout << "Новая матрица:" << endl;
    OutputArray(array, rowArray, columnArray);
    Sleep(15000);
}
void SwapRow(int** array, int rowArray, int columnArray, int numberRow) {
    int buffer = 0;
    for (int i = 0; i < columnArray; i++) {
        buffer = array[numberRow][i];
        array[numberRow][i] = array[numberRow + 1][i];
        array[numberRow + 1][i] = buffer;
    }
}

void FillColumnNull(int** array, int rowArray, int columnArray) {
    system("cls");
    while (true) {
        cout << "Матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        int input;
        cout << "Введите обнуляемый столбец" << endl;
        cout << "Введите -1 для выхода" << endl;
        cin >> input;
        if (input == -1)
            return;
        input--;
        for (int i = 0; i < rowArray; i++) {
            array[i][input] = 0;
        }
        char inputExit;
        cout << "Матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        cout << "Завершить обнуление столбцов? Y/N" << endl;
        cin >> inputExit;
        if (inputExit == 'Y')
            return;
    }
}

void FillRowNull(int** array, int rowArray, int columnArray) {
    system("cls");
    while (true) {
        cout << "Матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        int input;
        cout << "Введите обнуляемую строку" << endl;
        cout << "Введите -1 для выхода" << endl;
        cin >> input;
        if (input == -1)
            return;
        input--;
        for (int i = 0; i < columnArray; i++) {
            array[input][i] = 0;
        }
        char inputExit;
        cout << "Матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        cout << "Завершить обнуление строк? Y/N" << endl;
        cin >> inputExit;
        if (inputExit == 'Y')
            return;
    }
}

int RemoveNullRow(int** array, int rowArray, int columnArray) {
    system("cls");
    cout << "Матрица до удаления строк:" << endl;
    OutputArray(array, rowArray, columnArray);
    int conterRemoveRow = 0;
    for (int i = 0; i < rowArray; i++) {
        int counter = 0;
        for (int j = 0; j < columnArray; j++) {
            if (array[i][j] == 0)
                counter++;
            else
                break;
        }
        if (counter >= columnArray) {
            conterRemoveRow++;
            RemoveRow(array, rowArray, columnArray, i);
            i--;
        }

    }
    cout << "Матрица после удаления строк:" << endl;
    OutputArray(array, (rowArray - conterRemoveRow), columnArray);
    Sleep(15000);
    return rowArray - conterRemoveRow;
}

void RemoveRow(int** array, int rowArray, int columnArray, int numberRow) {
    for (int i = numberRow; i < (rowArray - 1); i++) {
        for (int j = 0; j < columnArray; j++) {
            array[i][j] = array[i + 1][j];
        }
    }
}

int RemoveRow(int** array, int rowArray, int columnArray) {
    system("cls");
    bool exit = false;
    while (!exit) {
        cout << "Матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        int input;
        cout << "Введите удаляемую строку" << endl;
        cout << "Введите -1 для выхода" << endl;
        cin >> input;
        if (input == -1)
            return rowArray;
        input--;
        for (int i = input; i < (rowArray - 1); i++) {
            for (int j = 0; j < columnArray; j++) {
                array[i][j] = array[i + 1][j];
            }
        }
        rowArray--;
        char inputExit;
        OutputArray(array, rowArray, columnArray);
        if (rowArray == 0)
            return 0;
        cout << "Завершить удаление строк? Y/N" << endl;
        cin >> inputExit;
        if (inputExit == 'Y')
            return rowArray;
    }
}
int RemoveColumn(int** array, int rowArray, int columnArray) {
    system("cls");
    bool exit = false;
    while (!exit) {
        cout << "Матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        int input;
        cout << "Введите удаляемый столбец" << endl;
        cout << "Введите -1 для выхода" << endl;
        cin >> input;
        if (input == -1)
            return columnArray;
        input--;
        for (int i = 0; i < rowArray; i++) {
            for (int j = input; j < (columnArray - 1); j++) {
                array[i][j] = array[i][j + 1];
            }
        }
        columnArray--;
        char inputExit;
        OutputArray(array, rowArray, columnArray);
        if (columnArray == 0)
            return 0;
        cout << "Завершить удаление столбцов? Y/N" << endl;
        cin >> inputExit;
        if (inputExit == 'Y')
            return columnArray;
    }
}

void OutputArray(int** array, int rowArray, int columnArray) {
    cout << setw(3) << " ";
    for (int j = 1; j < columnArray + 1; j++) {
        cout << setw(8) << j << "|";
    }
    cout << endl;
    for (int i = 0; i < rowArray; i++) {
        cout << setw(3) << i + 1;
        for (int j = 0; j < columnArray; j++) {
            cout << setw(8) << array[i][j] << "|";
        }
        cout << "\n";
    }
}
void EditElementInArray(int** array, int rowArray, int columnArray) {
    int inputRowArray;
    int inputColumnArray;
    int inputDigit;
    bool exitFromEdit = false;
    while (!exitFromEdit) {
        system("cls");
        OutputArray(array, rowArray, columnArray);
        cout << "Введите столбец" << endl;
        cin >> inputRowArray;
        cout << "Введите строку" << endl;
        cin >> inputColumnArray;
        cout << "Введите новое число" << endl;
        cout << "Введите -1 для выхода" << endl;
        cin >> inputDigit;
        if (inputDigit == -1)
            return;

        array[inputColumnArray - 1][inputRowArray - 1] = inputDigit;
        OutputArray(array, rowArray, columnArray);
        cout << "Завершить редактировать элементов? Y/N" << endl;
        char input;
        cin >> input;
        if (input == 'Y')
            exitFromEdit = true;
    }
}

void FillArrayRandDigit(int** array, int rowArray, int columnArray) {
    system("cls");
    srand(time(NULL));
    int input;
    int divider = 1;
    cout << "Ограничения:\n0 - Безлимитов \n1 - 0-9\n2 - 0-99\n3 - 0-999\n";
    cout << "Введите -1 для выхода" << endl;
    cin >> input;
    if (input == -1)
        return;

    switch (input)
    {
    case 0:
        divider = 0;
        break;
    case 1:
        divider = 10;
        break;
    case 2:
        divider = 100;
        break;
    case 3:
        divider = 1000;
        break;
    default:
        break;
    }
    if (divider <= 0) {
        for (int i = 0; i < rowArray; i++) {
            for (int j = 0; j < columnArray; j++) {
                array[i][j] = rand();
            }
        }
    }
    else {
        for (int i = 0; i < rowArray; i++) {
            for (int j = 0; j < columnArray; j++) {
                array[i][j] = (rand() % divider);
            }
        }
    }
    system("cls");
}
void FillArrayConsole(int** array, int rowArray, int columnArray) {
    bool exitFromInput = false;
    while (!exitFromInput) {
        system("cls");
        cout << "Введите матрицу:" << endl;
        for (int i = 0; i < rowArray; i++) {
            for (int j = 0; j < columnArray; j++) {
                system("cls");
                OutputArray(array, rowArray, columnArray);
                cout << "Строка - " << (i + 1) << endl << "Столбец - " << (j + 1) << endl;
                cout << "Введите -1 для выхода" << endl;
                int input;
                cin >> input;
                if (input == -1)
                    return;
                array[i][j] = input;
            }
        }
        system("cls");
        cout << "Введенная матрица:" << endl;
        OutputArray(array, rowArray, columnArray);
        cout << "Уверенны в правильности введенных данных? Y/N" << endl;
        char input;
        cin >> input;
        if (input == 'Y')
            exitFromInput = true;
    }
}