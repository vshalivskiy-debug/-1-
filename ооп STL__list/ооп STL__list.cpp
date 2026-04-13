#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

int main() {

    // Встановлення кодування Windows-1251
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout << "Введіть натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка! n повинно бути натуральним числом." << endl;
        return 0;
    }

    list<double> numbers;

    cout << "Введіть " << n << " дійсних чисел:" << endl;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        numbers.push_back(x);
    }

    // Перевірка: чи є хоча б один елемент < -3
    bool hasLessThanMinus3 = false;

    for (double x : numbers) {
        if (x < -3) {
            hasLessThanMinus3 = true;
            break;
        }
    }

    if (hasLessThanMinus3) {
        // Якщо є елемент < -3 → всі від’ємні замінити їх квадратами
        for (auto it = numbers.begin(); it != numbers.end(); ++it) {
            if (*it < 0) {
                *it = (*it) * (*it);
            }
        }
    }
    else {
        // Інакше → всі елементи помножити на 0.1
        for (auto it = numbers.begin(); it != numbers.end(); ++it) {
            *it = (*it) * 0.1;
        }
    }

    // Вивід у зворотному порядку
    cout << "Результат у зворотному порядку:" << endl;

    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        cout << *rit << " ";
    }

    cout << endl;

    return 0;
}