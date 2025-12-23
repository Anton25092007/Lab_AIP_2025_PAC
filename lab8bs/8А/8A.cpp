#include <iostream>
#include <string>
using namespace std;

// Структура для хранения информации о товаре
struct Product {
    string name;     // наименование
    int quantity;    // количество
    double price;    // цена
};

int main() {
    int n;
    cout << "Введите количество товаров: ";
    cin >> n;

    // динамическое выделение памяти под массив товаров
    Product* products = new Product[n];

    // ввод данных
    for (int i = 0; i < n; i++) {
        cout << "\nТовар " << i + 1 << ":\n";
        cout << "Наименование: ";
        cin >> products[i].name;
        cout << "Количество: ";
        cin >> products[i].quantity;
        cout << "Цена: ";
        cin >> products[i].price;
    }

    // вывод товаров с количеством < 10
    cout << "\nТовары, количество которых меньше 10:\n";
    for (int i = 0; i < n; i++) {
        if (products[i].quantity < 10) {
            cout << " Наименование: " << products[i].name
                 << ", Количество: " << products[i].quantity
                 << ", Цена: " << products[i].price << endl;
        }
    }

    // освобождение памяти
    delete[] products;

    return 0;
}
