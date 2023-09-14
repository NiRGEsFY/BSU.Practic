#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

/*
•	не использовать объекты класса string;
*/

/*
В двумерном символьном массиве (массив строк)
в каждой строке массива удалить все слова,
у которых первый и последний символы совпадают.
Отсортировать массив строк по количеству удаленных слов.
*/

void OutputArray(char** array, int* removeWord, int rowArray, int lenghtArray);
void InitialArrayFromConsole(char** array, int rowArray, int lenghtArray);
void RemoveWordInArray(char** array, int* removeWord, int rowArray, int lenghtArray);
void SordArray(char** array, int* removeWord, int rowArray, int lenghtArray);

int main()
{
    int rowArray;
    cout << "Введите количество строк массива" << endl;
    cin >> rowArray;

    int lenghtArray;
    cout << "Введите количество столбцов массива" << endl;
    cin >> lenghtArray;

    char** array = new char* [lenghtArray] {};
    for (int i = 0; i < rowArray; i++) {
        array[i] = new char[lenghtArray] {};
    }
    int* removeWord{ new int[rowArray] };
    for (int i = 0; i < rowArray; i++) {
        removeWord[i] = 0;
    }
    bool exit = false;
    while (!exit) {
        int input;
        system("cls");
        cout << "1 - Ввести строки через консоль\n"
            << "2 - Вывести матрицу\n"
            << "3 - Выполнить удаление по заданию\n"
            << "4 - Выполнить сортировку\n"
            << "0 - Выход\n";
        cin >> input;
        if (!input)
            break;

        switch (input)
        {
        case 1:
            InitialArrayFromConsole(array, rowArray, lenghtArray);
            break;
        case 2:
            system("cls");
            OutputArray(array, removeWord, rowArray, lenghtArray);
            while (true) {

                cout << "Введите \'E\' для выхода" << endl;
                char input;
                cin >> input;
                system("cls");
                if (input == 'E')
                    break;
            }
            break;
        case 3:
            RemoveWordInArray(array, removeWord, rowArray, lenghtArray);
            break;
        case 4:
            SordArray(array, removeWord, rowArray, lenghtArray);
            break;
        }
    }
}

void SordArray(char** array, int* removeWord, int rowArray, int lenghtArray) {
    int k = rowArray;
    bool testWork = true;
    int buffer = 0;
    char* bufferArray{ new char[lenghtArray] {} };
    while (testWork) {
        testWork = false;
        for (int j = 0; j < (k - 1); j++) {
            if (removeWord[j] > removeWord[j + 1]) {
                buffer = removeWord[j + 1];
                removeWord[j + 1] = removeWord[j];
                removeWord[j] = buffer;
                bufferArray = array[j + 1];
                array[j + 1] = array[j];
                array[j] = bufferArray;
                testWork = true;
            }
        }
        --k;
    }
}

void RemoveWordInArray(char** array, int* removeWord, int rowArray, int lenghtArray) {
    char firstChar = 0;
    int posFirstChar = 0;
    char lastChar = 0;
    for (int i = 0; i < rowArray; i++) {
        for (int j = 0; j < (lenghtArray + 1); j++) {
            if (!firstChar && (array[i][j] != ' ')) {
                firstChar = array[i][j];
                posFirstChar = j;
            }
            if (firstChar && ((array[i][j] == '\0') || (array[i][j] == ' '))) {
                lastChar = array[i][j - 1];
                if (firstChar == lastChar) {
                    removeWord[i] += 1;
                    for (int k = posFirstChar; k < j; k++) {
                        array[i][k] = ' ';
                    }
                }
                firstChar = 0;
                posFirstChar = 0;
                lastChar = 0;
            }
        }
        firstChar = 0;
        posFirstChar = 0;
        lastChar = 0;
        cout << "\n";
    }
    int counter = 0;
    for (int i = 0; i < rowArray; i++) {
        char* bufferArray{ new char[lenghtArray] {} };
        int k = 0;
        for (int j = 0; j < lenghtArray; j++) {
            if ((array[i][j] == ' ' && array[i][j + 1] == ' '))
                continue;
            else {
                bufferArray[k] = array[i][j];
                k++;
            }
        }
        if (bufferArray[0] == ' ') {
            for (int i = 1; i < lenghtArray; i++) {
                bufferArray[i - 1] = bufferArray[i];
            }
        }
        array[i] = bufferArray;
    }
}
void OutputArray(char** array, int* removeWord, int rowArray, int lenghtArray) {
    for (int i = 0; i < rowArray; i++) {
        cout << removeWord[i] << " - ";
        for (int j = 0; j < lenghtArray; j++) {
            cout << array[i][j];
        }
        cout << "\n";
    }
}
void OutputArray(char** array, int rowArray, int lenghtArray) {
    for (int i = 0; i < rowArray; i++) {
        for (int j = 0; j < lenghtArray; j++) {
            cout << array[i][j];
        }
        cout << "\n";
    }
}
void InitialArrayFromConsole(char** array, int rowArray, int lenghtArray) {
    cin.getline(array[0], (lenghtArray + 1));
    for (int i = 0; i < rowArray; i++) {
        system("cls");
        OutputArray(array, rowArray, lenghtArray);
        cout << "Строка - " << i << endl;
        cout << "До " << lenghtArray << " Символов" << endl;
        cout << setw(lenghtArray) << '|';
        cout << "Примерно до штриха" << endl;
        cin.getline(array[i], (lenghtArray + 1));
        cout << "\n";
    }
    while (true) {
        system("cls");
        cout << "Введите 'E' для выхода" << endl;
        char input;
        cin >> input;
        if (input == 'E')
            break;
    }
}