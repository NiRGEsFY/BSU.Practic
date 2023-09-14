#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*
•	выполнить своё Задание_4, используя txt-файлы;
•	ввести данные из консоли, или из текстового документа;
•	результат записать в текстовый файл;
•	для контроля прочитать файл-результата и вывести на экран;
•	использовать в программе функции;
•	вывести результат в наглядном и полном виде;
•	меню использовать по желанию.
*/
/*
* При сортировке использовать минимальное количество оперативной памяти
*/

int Input();
void Menu();
void Sort(int count);
void Withdraw();

struct olympiadSwimming {
public:
	int numberSwimming;
	string name;
	int distance;
	int time;
};

int main()
{
	Menu();
}
void Menu() {
	while (true) {
		int input = 0;
		int couter = 0;
		ifstream couterStream("D://buffer.txt");
		string temp;
		while (getline(couterStream, temp)) {
			couter++;
		}
		cout << "Меню:" << endl;
		cout << "1 - Ввесити заплывы" << endl;
		cout << "2 - Вывести заплывы" << endl;
		cout << "3 - Отсортировать заплывы" << endl;
		cout << "0 - Выход" << endl;
		cin >> input;
		if (!input) {
			break;
		}
		switch (input) {
		case 1:
			couter = Input();
			break;
		case 2:
			Withdraw();
			break;
		case 3:
			Sort(couter);
			break;
		}
	};

};

bool CheckName(string top, string buttom) {
	while (true) {
		if (top[0] > 64 && top[0] < 91) {
			top[0] += 32;
		}
		if (buttom[0] > 64 && buttom[0] < 91) {
			buttom[0] += 32;
		}
		if (top[0] > buttom[0])
			return true;
		else if (top.empty()) {
			return false;
		}
		else if (buttom.empty()) {
			return true;
		}
		else if (top[0] == buttom[0]) {
			top.erase(0, 1);
			buttom.erase(0, 1);
		}
		else
			return false;
	}

}

void Withdraw() {
	cout << setw(5) << "Id" << '|';
	cout << setw(10) << "Name" << '|';
	cout << setw(10) << "Distance" << '|';
	cout << setw(10) << "Time" << '|';
	cout << endl;
	string wayIn = "D://buffer.txt";
	ifstream in(wayIn, ios::binary);
	string input;
	while (getline(in, input)) {
		string buffer[4];
		for (int i = 0; i < 4; i++) {
			while (input[0] != '|') {
				buffer[i] += input[0];
				input.erase(0, 1);
			}
			input.erase(0, 1);
		}
		cout << setw(5) << buffer[0] << '|';
		cout << setw(10) << buffer[1] << '|';
		cout << setw(10) << buffer[2] << '|';
		cout << setw(10) << buffer[3] << '|';
		cout << endl;
	}
	in.close();
}

void Sort(int count) {
	for (int i = 0; i < count; i++) {
		bool firstStart = true;
		string wayOut = "D://output.txt";
		string wayIn = "D://buffer.txt";
		ifstream in(wayIn, ios::binary);
		ofstream out(wayOut, ios::binary);
		olympiadSwimming top;
		olympiadSwimming bufferSwimming;
		olympiadSwimming buttom;
		string input;

		while (getline(in, input)) {
			string buffer[4];
			top = buttom;
			for (int i = 0; i < 4; i++) {
				while (input[0] != '|') {
					buffer[i] += input[0];
					input.erase(0, 1);
				}
				input.erase(0, 1);
			}
			buttom.numberSwimming = stoi(buffer[0]);
			buttom.name = buffer[1];
			buttom.distance = stoi(buffer[2]);
			buttom.time = stoi(buffer[3]);
			if (!firstStart) {
				if (top.numberSwimming > buttom.numberSwimming) {
					bufferSwimming = buttom;
					buttom = top;
					top = bufferSwimming;
				}
				if ((top.numberSwimming == buttom.numberSwimming) && CheckName(top.name, buttom.name)) {
					bufferSwimming = buttom;
					buttom = top;
					top = bufferSwimming;
				}
				out << top.numberSwimming << '|';
				out << top.name << '|';
				out << top.distance << '|';
				out << top.time << '|';
				out << endl;
			}
			firstStart = false;
		}
		out << buttom.numberSwimming << '|';
		out << buttom.name << '|';
		out << buttom.distance << '|';
		out << buttom.time << '|';
		out << endl;
		in.close();
		out.close();
		in.open(wayOut, ios::binary);
		out.open(wayIn, ios::binary);
		while (getline(in, input)) {
			out << input << endl;
		}
		in.close();
		out.close();
		count--;
	}
}

int Input() {
	ofstream work("D://buffer.txt", ios::binary);
	int counter = 0;
	if (work.is_open()) {
		while (true) {
			olympiadSwimming input;
			cout << "Введите 0 для выхода" << endl;
			cout << "Введите номер заплыва" << endl;
			int console;
			cin >> console;
			if (!console) {
				break;
			}
			input.numberSwimming = console;
			cout << "Введите имя" << endl;
			cin.ignore();
			getline(cin, input.name);
			cout << "Введите дистанцию" << endl;
			cin >> input.distance;
			cout << "Введите время" << endl;
			cin >> input.time;
			cout << endl;
			work << input.numberSwimming << '|';
			work << input.name << '|';
			work << input.distance << '|';
			work << input.time << '|';
			work << endl;
			counter++;
		}
	}
	work.close();
	return counter;
};