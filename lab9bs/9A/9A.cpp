#include <iostream>
#include <fstream>
#include <cmath>   // для fabs
using namespace std;

int main() {
    const int N = 10;
    double numbers[N] = {12.5, -15.3, 7.8, 9.1, -22.4, 5.0, 18.6, -3.7, 11.2, -30.5};

    //открыть файл
    ofstream binOut("numbers.bin", ios::binary);
    if (!binOut) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return 1; //проверка
    }
    binOut.write(reinterpret_cast<char*>(numbers), sizeof(numbers)); //запись массива в файл
    binOut.close();

    // --- Чтение из бинарного файла ---
    ifstream binIn("numbers.bin", ios::binary);
    if (!binIn) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return 1;
    }
    double readNumbers[N];
    binIn.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers));
    binIn.close();

    // Вычисление среднего 
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += readNumbers[i];
    }
    double average = sum / N;

    // Проверка условия 
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (readNumbers[i] < 0 && fabs(readNumbers[i]) > average) {
            found = true;
            break;
        }
    }

    // --- Вывод результата ---
    ofstream txtOut("result.txt");
    if (!txtOut) {
        cerr << "Ошибка открытия текстового файла!" << endl;
        return 1;
    }

    cout << "Среднее значение: " << average << endl;
    txtOut << "Среднее значение: " << average << endl;

    if (found) {
        cout << "Есть отрицательные числа, модуль которых больше среднего." << endl;
        txtOut << "Есть отрицательные числа, модуль которых больше среднего." << endl;
    } else {
        cout << "Таких отрицательных чисел нет." << endl;
        txtOut << "Таких отрицательных чисел нет." << endl;
    }

    txtOut.close();
    return 0;
}
