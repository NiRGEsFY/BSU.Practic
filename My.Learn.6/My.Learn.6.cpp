#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

/*
•	не использовать в определении структуры функции;
•	не использовать объекты класса string;
•	не создавать массив для хранения цифр чисел.
*/
/*
* Определить структуру, содержащую результаты соревнований
* по плаванию: номер заплыва, дистанция, фамилия участника
* и его время. Создать массив структур
* а) Отсортировать массив структур по возрастанию номера заплыва.
* Вывести массив структур в виде таблицы, указать номер заплыва,
* среднее время заплыва и количество участников. Массивы
* по каждому заплыву не создавать.
* б) По запросу получить список (создать массив участников
* указанного заплыва, упорядочив его в алфавитном порядке.
*/

struct olympiadSwimming {
public:
    int numberSwimming;
    char* name;
    int distance;
    int time;
};

void FillArray(olympiadSwimming* array, int lenght);
void OutputArray(olympiadSwimming* array, int lenght);
void SortArray(olympiadSwimming* array, int lenght);
void OutputBranchArray(olympiadSwimming* array, int lenght);
void OutputUserList(olympiadSwimming* array, int lenght);

int main()
{
    cout << "Введите количество заплывов" << endl;
    int lenght;
    cin >> lenght;
    olympiadSwimming* array{ new olympiadSwimming[lenght] };
    for (int i = 0; i < lenght; i++) {
        array[i].name = new char[100] {'N'};
    }
    bool exit = false;
    while (!exit) {
        int input;
        cout << "1 - Ввести заплывы через консоль\n"
            << "2 - Вывести заплывы\n"
            << "3 - Вывести заплывы с сред. знач.\n"
            << "4 - Выполнить сортировку заплывов\n"
            << "5 - Получить список участников заплыва\n"
            << "0 - Выход\n";
        cin >> input;
        if (!input)
            break;
        switch (input)
        {
        case 1:
            FillArray(array, lenght);
            break;
        case 2:
            OutputArray(array, lenght);
            Sleep(5000);
            break;
        case 3:
            OutputBranchArray(array, lenght);
            Sleep(5000);
            break;
        case 4:
            SortArray(array, lenght);
            break;
        case 5:
            OutputUserList(array, lenght);
            Sleep(5000);
            break;
        }
    }
}

void FillArray(olympiadSwimming* array, int lenght) {
    for (int i = 0; i < lenght; i++) {

        OutputArray(array, lenght);
        cout << "Введите номер заплыва" << endl;
        cin >> array[i].numberSwimming;
        cout << "Введите Фамилию и Имя" << endl;
        cout << setw(100) << '|';
        cout << "До отметки" << endl;
        while (cin.get() != '\n'); //Костыль ебаный
        cin.getline(array[i].name, 101);
        cout << "\nВведите Дистанцию, метр" << endl;
        cin >> array[i].distance;
        cout << "Введите Время, сек" << endl;
        cin >> array[i].time;
    }
}
void OutputArray(olympiadSwimming* array, int lenght) {
    cout << "Номер заплыва |   Фамилия   Имя   | Дистанция, метр | Время, сек " << endl;
    for (int i = 0; i < lenght; i++) {
        cout << setw(14) << array[i].numberSwimming << '|';
        cout << setw(19) << array[i].name << '|';
        cout << setw(17) << array[i].distance << '|';
        cout << setw(12) << array[i].time << endl;

    }
}

bool CheckLetter(char first, char second) {
    if (first > 64 & first < 91) {
        first += 32;
    }
    if (second > 64 & second < 91) {
        second += 32;
    }
    if (first > second)
        return true;
    else
        return false;

}

void OutputUserList(olympiadSwimming* array, int lenght) {
    SortArray(array, lenght);
    int counter = 0;
    int input = 0;
    cout << "Введите номер заплыва" << endl;
    cin >> input;
    for (int i = 0; i < lenght; i++) {
        if (array[i].numberSwimming == input) {
            counter++;
        }
        else if (array[i + 1].numberSwimming > input) {
            break;
        }
    }
    char** userList = new char* [counter] {};
    for (int i = 0; i < counter; i++) {
        userList[i] = new char[100] {};
    }
    for (int i = 0; i < lenght; i++) {
        if (array[i].numberSwimming == input) {
            for (int j = 0; j < counter; j++) {
                userList[j] = array[i + j].name;
            }
            break;
        }
    }

    int k = counter;
    int checkerDistance = 0;
    bool testWork = true;
    char* buffer{ new char[100] {} };
    while (testWork) {
        testWork = false;
        for (int j = 0; j < (k - 1); j++) {
            do {
                if (CheckLetter(userList[j][checkerDistance], userList[j + 1][checkerDistance])) {
                    buffer = userList[j + 1];
                    userList[j + 1] = userList[j];
                    userList[j] = buffer;
                    testWork = true;
                }
                checkerDistance++;
            } while ((userList[j][checkerDistance] == userList[j + 1][checkerDistance]) && checkerDistance < k);
            checkerDistance = 0;
        }
        --k;
    }
    for (int i = 0; i < counter; i++) {
        cout << userList[i] << endl;
    }
    delete[] buffer;
    delete[] userList;
}


void OutputBranchArray(olympiadSwimming* array, int lenght) {
    cout << "Номер заплыва |   Фамилия   Имя   | Дистанция, метр | Время, сек " << endl;
    int counter = 0;
    int allTime = 0;
    SortArray(array, lenght);
    for (int i = 0; i < lenght; i++) {
        if (array[i].numberSwimming < array[i + 1].numberSwimming || i == lenght - 1) {
            counter++;
            allTime += array[i].time;
            cout << setw(14) << array[i].numberSwimming << '|';
            cout << setw(19) << array[i].name << '|';
            cout << setw(17) << array[i].distance << '|';
            cout << setw(12) << array[i].time << endl;
            cout << "Номер заплыва - " << array[i].numberSwimming << "  |  ";
            cout << "Кол. участников - " << counter << "  |  ";
            cout << "Ср. время - " << allTime / counter << endl;
            counter = 0;
            allTime = 0;
        }
        else {
            counter++;
            allTime += array[i].time;
            cout << setw(14) << array[i].numberSwimming << '|';
            cout << setw(19) << array[i].name << '|';
            cout << setw(17) << array[i].distance << '|';
            cout << setw(12) << array[i].time << endl;
        }

    }
}
void SortArray(olympiadSwimming* array, int lenght) {
    int k = lenght;
    bool testWork = true;
    olympiadSwimming buffer;
    while (testWork) {
        testWork = false;
        for (int j = 0; j < (k - 1); j++) {
            if (array[j].numberSwimming > array[j + 1].numberSwimming) {
                buffer = array[j + 1];
                array[j + 1] = array[j];
                array[j] = buffer;
                testWork = true;
            }
        }
        --k;
    }
}