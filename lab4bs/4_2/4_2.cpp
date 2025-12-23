#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int len;
    
    // Проверка ввода длины массива
    while (true) {
        cout << "Введите длину массива: ";
        cin >> len;
        
        if (cin.fail()) {
            cout << "Ошибка: введите целое число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (len <= 0) {
            cout << "Ошибка: длина должна быть положительной!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    vector<double> nums(len);
    cout << "Введите элементы массива: " << endl;

    // Проверка ввода элементов массива
    for (int i = 0; i < len; i++) {
        cout << "Элемент " << i + 1 << ": ";
        while (!(cin >> nums[i])) {
            cout << "Ошибка: введите число! Попробуйте снова: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Вывод массива
    cout << "Первоначальный массив: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i];
        if (i < len - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    // Поиск max и min
    double max_val = nums[0];
    double min_val = nums[0];
    int max_pos = 0;
    int min_pos = 0;

    for (int i = 1; i < len; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
            max_pos = i;
        }
        if (nums[i] < min_val) {
            min_val = nums[i];
            min_pos = i;
        }
    }



    // Сумма
    double s = 0;

    // Суммируем элементы между min_pos и max_pos НЕ ВКЛЮЧАЯ ГРАНИЦЫ
    if (max_pos > min_pos) {
        // Сумма от min_pos+1 до max_pos-1
        for (int i = min_pos + 1; i < max_pos; i++) {
            s += nums[i];
        }
    } else if (min_pos > max_pos) {
        // Сумма от max_pos+1 до min_pos-1
        for (int i = max_pos + 1; i < min_pos; i++) {
            s += nums[i];
        }
    }
    // Если позиции совпадают или разница 1 - сумма будет 0

    cout << "Сумма элементов между ними (не включая границы): " << s << endl;

    return 0;
}