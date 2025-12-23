#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Product {
    char name[50];
    int quantity;
    double price;
};

const char* BIN_FILE = "products.bin";
const char* TXT_FILE = "/Users/polonnikovanton/Desktop/Антон/универ/1 курс/АиП/lab9bs/9B/result.txt";
const int MAX = 100;

bool fileCreated = false;
bool dataRead = false;

void createBinaryFile() {
    // Просто проверяем, существует ли файл, или создаем пустой
    fstream file(BIN_FILE, ios::binary | ios::in | ios::out);
    if (!file) {
        // Если файл не существует, создаем пустой
        ofstream fout(BIN_FILE, ios::binary);
        if (fout) {
            fout.close();
            fileCreated = true;
            cout << "Бинарный файл создан." << endl;
        } else {
            cerr << "Ошибка создания бинарного файла!" << endl;
        }
    } else {
        fileCreated = true;
        cout << "Файл уже существует. Можно работать с ним." << endl;
        file.close();
    }
    dataRead = false;
}

void writeData(Product* products, int n) {
    if (!fileCreated) {
        cout << "Файл не создан. Сначала создайте файл." << endl;
        return;
    }

    // Открываем файл для дозаписи (append) в бинарном режиме
    ofstream fout(BIN_FILE, ios::binary | ios::app);
    if (!fout) {
        cerr << "Ошибка записи в файл!" << endl;
        return;
    }

    fout.write(reinterpret_cast<char*>(products), n * sizeof(Product));
    fout.close();

    dataRead = false;
    cout << "Данные успешно добавлены в файл." << endl;
}

void writeDataWithRewrite(Product* products, int n) {
    if (!fileCreated) {
        cout << "Файл не создан. Сначала создайте файл." << endl;
        return;
    }

    // Полная перезапись файла (очистка и запись новых данных)
    ofstream fout(BIN_FILE, ios::binary | ios::trunc);
    if (!fout) {
        cerr << "Ошибка записи в файл!" << endl;
        return;
    }

    fout.write(reinterpret_cast<char*>(products), n * sizeof(Product));
    fout.close();

    dataRead = false;
    cout << "Файл полностью перезаписан новыми данными." << endl;
}

int readData(Product* products) {
    if (!fileCreated) {
        cout << "Файл не создан." << endl;
        return 0;
    }

    ifstream fin(BIN_FILE, ios::binary);
    if (!fin) {
        cerr << "Ошибка чтения файла!" << endl;
        return 0;
    }

    // Определяем размер файла
    fin.seekg(0, ios::end);
    streampos fileSize = fin.tellg();
    fin.seekg(0, ios::beg);

    if (fileSize == 0) {
        cout << "Файл пуст." << endl;
        fin.close();
        return 0;
    }

    // Читаем все данные из файла
    fin.read(reinterpret_cast<char*>(products), fileSize);
    int count = fileSize / sizeof(Product);
    fin.close();

    if (count > MAX) {
        cout << "Внимание: в файле больше " << MAX << " записей. Будут прочитаны первые " << MAX << " записей." << endl;
        count = MAX;
    }

    dataRead = true;
    cout << "Прочитано товаров: " << count << endl;
    return count;
}

void sortByName(Product* products, int n) {
    sort(products, products + n, [](const Product& a, const Product& b) {
        return strcmp(a.name, b.name) < 0;
    });
}

void printToScreen(Product* products, int n) {
    if (!dataRead || n == 0) {
        cout << "Нет данных для вывода." << endl;
        return;
    }

    sortByName(products, n);

    cout << "\nТовары с количеством > 10 и < 100:\n";
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (products[i].quantity > 10 && products[i].quantity < 100) {
            cout << products[i].name << " | "
                 << products[i].quantity << " | "
                 << products[i].price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Подходящих товаров нет." << endl;
    }
}

void printToTextFile(Product* products, int n) {
    if (!dataRead || n == 0) {
        cout << "Нет данных для вывода." << endl;
        return;
    }

    ofstream fout(TXT_FILE);
    if (!fout) {
        cerr << "Ошибка создания текстового файла!" << endl;
        return;
    }

    sortByName(products, n);

    fout << "Товары с количеством > 10 и < 100:\n";
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (products[i].quantity > 10 && products[i].quantity < 100) {
            fout << products[i].name << " | "
                 << products[i].quantity << " | "
                 << products[i].price << endl;
            found = true;
        }
    }

    if (!found) {
        fout << "Подходящих товаров нет." << endl;
    }

    fout.close();
    cout << "Результат записан в файл result.txt" << endl;
}

int main() {
    Product products[MAX];
    int n = 0;
    int totalProductsInFile = 0;
    int choice;

    do {
        cout << "\nМЕНЮ\n";
        cout << "1. Создать/проверить бинарный файл\n";
        cout << "2. Добавить товары в файл (дозапись)\n";
        cout << "3. Перезаписать все товары в файле\n";
        cout << "4. Прочитать товары из файла\n";
        cout << "5. Вывести результат на экран\n";
        cout << "6. Вывести результат в текстовый файл\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createBinaryFile();
                break;

            case 2:
                if (!fileCreated) {
                    cout << "Сначала создайте файл." << endl;
                    break;
                }

                cout << "Введите количество товаров для добавления (<= " << MAX << "): ";
                int addCount;
                cin >> addCount;

                if (addCount <= 0 || addCount > MAX) {
                    cout << "Некорректное количество." << endl;
                    break;
                }

                // Читаем существующие товары
                totalProductsInFile = readData(products);
                
                // Вводим новые товары
                for (int i = 0; i < addCount; i++) {
                    cout << "\nТовар " << i + 1 << endl;
                    cout << "Наименование (без пробелов): ";
                    cin >> products[totalProductsInFile + i].name;
                    cout << "Количество: ";
                    cin >> products[totalProductsInFile + i].quantity;
                    cout << "Цена: ";
                    cin >> products[totalProductsInFile + i].price;
                }

                // Дозаписываем новые товары
                writeData(&products[totalProductsInFile], addCount);
                break;

            case 3:
                if (!fileCreated) {
                    cout << "Сначала создайте файл." << endl;
                    break;
                }

                cout << "Введите количество товаров (<= " << MAX << "): ";
                cin >> n;

                if (n <= 0 || n > MAX) {
                    cout << "Некорректное количество." << endl;
                    n = 0;
                    break;
                }

                for (int i = 0; i < n; i++) {
                    cout << "\nТовар " << i + 1 << endl;
                    cout << "Наименование (без пробелов): ";
                    cin >> products[i].name;
                    cout << "Количество: ";
                    cin >> products[i].quantity;
                    cout << "Цена: ";
                    cin >> products[i].price;
                }

                // Полная перезапись файла
                writeDataWithRewrite(products, n);
                break;

            case 4:
                totalProductsInFile = readData(products);
                n = totalProductsInFile; // Обновляем количество товаров для отображения
                break;

            case 5:
                printToScreen(products, n);
                break;

            case 6:
                printToTextFile(products, n);
                break;

            case 0:
                cout << "Выход из программы." << endl;
                break;

            default:
                cout << "Неверный пункт меню." << endl;
        }
    } while (choice != 0);

    return 0;
}