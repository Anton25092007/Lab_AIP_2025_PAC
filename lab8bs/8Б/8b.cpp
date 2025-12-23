#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
};

int main() {
    int n;
    cout << "Введите количество товаров: ";
    cin >> n;

    Product* products = new Product[n];

    // ввод данных
    for (int i = 0; i < n; i++) {
        cout << "\nТовар " << i + 1 << ":\n";
        cout << " Наименование: ";
        cin >> products[i].name;
        cout << " Количество: ";
        cin >> products[i].quantity;
        cout << " Цена: ";
        cin >> products[i].price;
    }

    // сортировка по имени
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (products[j].name > products[j + 1].name) {
                // меняем местами
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    // вывод товаров с количеством >10 и <100
    cout << "\nТовары, количество которых больше 10 и меньше 100:\n";
    for (int i = 0; i < n; i++) {
        if (products[i].quantity > 10 && products[i].quantity < 100) {
            cout << "Наименование: " << products[i].name
                 << ", Количество: " << products[i].quantity
                 << ", Цена: " << products[i].price << endl;
        }
    }

    delete[] products;
    return 0;
}
