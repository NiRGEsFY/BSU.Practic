#include <iostream>

using namespace std;

/*
*	не использовать  массив для  чисел;
*	не создавать массив для хранения цифр числа;
*	не задавать число как символьный массив;
*	не использовать объекты класса string;
*	не использовать стандартные функции;
*	не использовать функцию pow() (ни свою, ни стандартную).
*	Задание 15
*/


/*
В заданной последовательности натуральных чисел найти наибольшее число среди чисел,
сумма цифр которых простое число.
Дополнительный массив не использовать.
*/

static int maxNumber;
static int input = 1;

int SummNumbersInNumber(int number) {
	int output = 0;
	while (number) {
		output += number % 10;
		number /= 10;
	}
	return output;
}
bool PrimeNumber(int input) {
	for (int i = 2; i <= input / 2; i++) {
		if ((input % i) == 0) {
			return false;
		}
	}
	return true;
}
void MaxNumber(int input) {
	int output = 0;
	int buffer = 0;
	if ((input > maxNumber) && PrimeNumber(SummNumbersInNumber(input))) {
		maxNumber = input;
	}
}

int main()
{
	while (input) {
		if (input == -1) {
			break;
		}
		cin >> input;
		MaxNumber(input);
	}
	if (maxNumber) {
		cout << maxNumber;
	}
	else {
		cout << "Нет простых чисел";
	}
	cin >> maxNumber;
}