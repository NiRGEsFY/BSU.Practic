#include <iostream>

using namespace std;

/*
•	не использовать объекты класса string;
•	не создавать массив для хранения цифр чисел.
*/

/*
* - Разработать класс для решения поставленной задачи,
* причём члены-данные класса должны быть private;
* - создать объекты, массив объектов (согласно условия задачи);
* - включить в класс конструктор (конструкторы),
* функции достпуа, обработки;
* - исполбзовать в программе внешние, дружественные
* функции для работы с объектами, массивами объектами,
* массивами объектов(согласно условию);
* вывести результат в наглядном и полном виде;
* меню использовать по желанию.
*/

/*
Ввести/вывести одномерный массив целых чисел размера n.
Отсортировать массив по возрастанию элементов методом "пузырька".
Сортировка должна быть эффективной, т.е. без лишних просмотров массива.
Ввести число и вставить его в отсортированный массив,
не нарушая упорядоченности элементов. Дополнительный массив не использовать.
Например, есть массив --- 6 2 5 9 4 1. Сортируем ---- 1 2 4 5 6 9.
Вводим по запросу число ---- 8. Результат ----- 1 2 4 5 6 8 9.
*/

class IntegerArray {
    friend void SortArray(IntegerArray controller);
    int _lenght;
    int* _array;
public:
    IntegerArray() {
        _lenght = 1;
    };
    IntegerArray(int lenght) {
        _lenght = lenght;
        _array = new int[_lenght];
    };
public:
    void Rezise(int newLenght) {
        int lenght = _lenght;
        int* newArray{ new int[newLenght] };
        lenght = lenght < newLenght ? newLenght : lenght;
        for (int i = 0; i < lenght; i++) {
            newArray[i] = _array[i];
        }
        if (newLenght > _lenght) {
            for (int i = newLenght - (newLenght - _lenght); i < newLenght; i++) {
                newArray[i] = 0;
            }
        }
        _lenght = newLenght;
        delete[] _array;
        _array = newArray;
    };
    void FillToConsole() {
        for (int i = 0; i < _lenght; i++) {
            cout << "Enter " << (i + 1) << ": ";
            cin >> _array[i];
        }
    };
    void FillToRandom() {
        srand(time(NULL));
        for (int i = 0; i < _lenght; i++) {
            _array[i] = rand() % 10;
        }
    };
    void FillToRandom(int divider) {
        srand(time(NULL));
        for (int i = 0; i < _lenght; i++) {
            _array[i] = rand() % divider;
        }
    };
    void ToConsole() {
        for (int i = 0; i < _lenght; i++) {
            cout << _array[i] << " ";
        }
        cout << endl;
    };
    void AddNumber(int number) {
        Rezise(_lenght + 1);
        int newPositionNumber;
        for (int i = 0; i < _lenght; i++) {
            newPositionNumber = i;
            if (number < (_array[i])) {
                break;
            }
        }
        for (int i = _lenght - 1; i > newPositionNumber; i--) {
            _array[i] = _array[i - 1];
        }
        _array[newPositionNumber] = number;
    };
    void CompleteTask(IntegerArray controller) {
        FillToRandom();
        cout << "Массив с ранд. числами:" << endl;
        ToConsole();
        SortArray(controller);
        cout << "Отсортированный массив" << endl;
        ToConsole();
        srand(time(NULL));
        AddNumber(rand() % 10);
        cout << "Добавление числа в массив" << endl;
        ToConsole();
    }
};
void SortArray(IntegerArray controller) {
    int k = controller._lenght;
    bool testWork = true;
    int buffer = 0;
    while (testWork) {
        testWork = false;
        for (int j = 0; j < (k - 1); j++) {
            if (controller._array[j] > controller._array[j + 1]) {
                buffer = controller._array[j + 1];
                controller._array[j + 1] = controller._array[j];
                controller._array[j] = buffer;
                testWork = true;
            }
        }
        --k;
    }
}

int main()
{
    int choice = 1;
    IntegerArray array(1);
    while (choice) {
        cout << "Меню:" << endl;
        cout << "1 - Изменить/Ввести размер массива" << endl;
        cout << "2 - Вывести массив" << endl;
        cout << "3 - Заполнить рандомно" << endl;
        cout << "4 - Заполнить с консоли" << endl;
        cout << "5 - Отсортировать массив" << endl;
        cout << "6 - Добавить число в массив" << endl;
        cout << "7 - Выполнить стандартную процедуру процессов" << endl;
        cout << "0 - Выйти и программы" << endl;
        cout << "Введите выбор: ";
        cin >> choice;
        if (!choice) {
            break;
        }
        switch (choice) {
        case 1:
            cout << "Введите размер: ";
            int input;
            cin >> input;
            array.Rezise(input);
            break;
        case 2:
            array.ToConsole();
            break;
        case 3:
            array.FillToRandom();
            break;
        case 4:
            array.FillToConsole();
            break;
        case 5:
            SortArray(array);
            break;
        case 6:
            cout << "Введите число которое хотите добавить: ";
            int n;
            cin >> n;
            array.AddNumber(n);
            break;
        case 7:
            array.CompleteTask(array);
            break;
        }
    }

}