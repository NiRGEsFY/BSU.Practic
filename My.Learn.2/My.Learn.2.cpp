#include <iostream>
#include "windows.h"
#include <iomanip>
#include <time.h>

/*
•	не создавать для хранения цифр числа массив;
•	не задавать числа как символьный массив;
•	не использовать объекты класса string;
•	не использовать стандартные функции.
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

using namespace std;

void FillMassRandomNumber(int* mass, int massLenght);
void SortMass(int* mass, int massLenght);
void WriteMass(int* mass, int massLenght);
void FillMassConsole(int* mass, int massLenght);
void AddNumberInMass(int* mass, int massLenght);

int main()
{
	cout << "Введите длинну массива\n";
	int massLenght = 0;
	cin >> massLenght;
	int flag = 1;
	int* mass{ new int[(massLenght + 1)] };
	while (flag) {
		cout << "Меню:\n" << "0 - Выход;\n1 - Заполнить массив с консоли\n2 - Заполнить массив случайными числами\n3 - Отсортировать\n4 - Вывести массив\n5 - Добавить число в массив\n6 - Отчистить консоль\n";

		cin >> flag;
		switch (flag)
		{
		case 0:
			break;
		case 1:
			FillMassConsole(mass, massLenght);
			break;
		case 2:
			FillMassRandomNumber(mass, massLenght);
			break;
		case 3:
			SortMass(mass, massLenght);
			break;
		case 4:
			WriteMass(mass, massLenght);
			break;
		case 5:
			++massLenght;
			AddNumberInMass(mass, massLenght);
			break;
		case 6:
			system("cls");
			break;
		}
	}

}
void AddNumberInMass(int* mass, int massLenght) {
	cout << "Введите число которое хотите добавить: ";
	int input = 0;
	cin >> input;
	mass[(massLenght - 1)] = input;
	for (int i = 0; i < massLenght; i++) {
		if (mass[i] > input) {
			for (int j = massLenght; j > i; j--) {
				mass[j] = mass[j - 1];
			}
			mass[i] = input;
			break;
		}
	}

}
void FillMassConsole(int* mass, int massLenght) {
	cout << "Введите числа через пробел\n";
	int input = 0;
	for (int i = 0; i < massLenght; i++) {
		cin >> input;
		mass[i] = input;
	}
}
void FillMassRandomNumber(int* mass, int massLenght) {
	srand(time(NULL));
	for (int i = 0; i < massLenght; i++) {
		mass[i] = rand();
	}
}
void SortMass(int* mass, int massLenght) {
	int k = massLenght;
	bool testWork = true;
	int buffer = 0;
	while (testWork) {
		testWork = false;
		for (int j = 0; j < (k - 1); j++) {
			if (mass[j] > mass[j + 1]) {
				buffer = mass[j + 1];
				mass[j + 1] = mass[j];
				mass[j] = buffer;
				testWork = true;
			}
		}
		--k;
	}
}
void WriteMass(int* mass, int massLenght) {
	for (int i = 0; i < massLenght; i++) {
		cout << setw(10u) << mass[i];
	}
	cout << "\n";
};