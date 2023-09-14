#include <iostream>

//●	не использовать  массив для  чисел;
//●	не создавать массив для хранения цифр числа;
//●	не задавать число как символьный массив;
//●	не использовать объекты класса string;
//●	не использовать стандартные функции; (создавать свои ? ? ? )
//●	не использовать функцию pow() (ни свою, ни стандартную).

/*
* В заданной последовательности
* натуральных чисел найти количество
* чисел, цифры которых образуют
* возрастающую последовательность.
*/

using namespace std;

int main() {
    int count = 0;
    while (true) {
        int input;
        cout << "Enter -1 for exit the program" << endl;
        cout << "Element " << ": ";
        cin >> input;
        if (input < 0) {
            break;
        }
        cout << endl;
        bool isIncreasing = true;
        while (input > 0) {
            if (!(input % 10 >= (input / 10 % 10))) {
                isIncreasing = false;
                break;
            }
            input /= 10;
        }
        if (isIncreasing)
            count++;
    }
    cout << "The number of increasing: " << count << endl;
}