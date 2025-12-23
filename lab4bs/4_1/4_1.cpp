#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Длина массива с проверкой
    int len;
    while (true) {
        cout << "Введите длину массива: ";
        cin >> len;
        
        if (cin.fail() || len <= 0) {
            cout << "Ошибка: введите положительное целое число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Массив
    double nums[len];
    cout << "Введите элементы массива: " << endl;
    
    for (int i = 0; i < len; i++) {
        cout << "Элемент " << i + 1 << ": ";
        while (!(cin >> nums[i])) {
            cout << "Ошибка: введите число! Попробуйте снова: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Первоначальный массив: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i];
        if (i < len - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    // Обработка массива
    for (int i = 0; i < len; i++) {
        if (nums[i] < 0 && i != 0 && i != len - 1) {
            nums[i] = (nums[i - 1] + nums[i + 1]) / 2;
        }
    }

    cout << "Измененный массив: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i];
        if (i < len - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}