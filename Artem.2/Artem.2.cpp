#include <iostream>

//Ввести / вывести одномерный массив натуральных чисел размера n.
//Найти в массиве количество пар соседних элементов, 
//у которых количество цифр одинаковое.

using namespace std;

bool NumberPair(int x, int y) {
    int temp_x = 0;
    int temp_y = 0;
    while (x) {
        temp_x++;
        x /= 10;
    }
    while (y) {
        temp_y++;
        y /= 10;
    }
    if (temp_y == temp_x) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter lenght mass: ";
    cin >> n;
    cout << endl;
    int* mass{ new int[n] };
    cout << "Enter mass: ";
    for (int i = 0; i < n; i++) {
        cin >> mass[i];
    }
    cout << "Mass:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << mass[i] << endl;
    }
    int counter = 0;
    for (int i = 0; i < (n - 1); i++) {
        if (NumberPair(mass[i], mass[i + 1]))
            counter++;

    }
    cout << "Count number part = " << counter << endl;
}