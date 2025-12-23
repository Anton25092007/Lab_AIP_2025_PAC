#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int N, M;

    
    cout << "Введите количество строк N: ";

        // Проверка ввода длины массива N
    while (true) {
        cout << "Введите длину массива: ";
        cin >> N;
        
        if (cin.fail()) {
            cout << "Ошибка: введите целое число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (N <= 0) {
            cout << "Ошибка: длина должна быть положительной!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    cout << "Введите количество столбцов M: ";
        while (true) {
        cout << "Введите длину массива: ";
        cin >> M;
        
        if (cin.fail()) {
            cout << "Ошибка: введите целое число!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (M <= 0) {
            cout << "Ошибка: длина должна быть положительной!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    
    int matrix[N][M];
    srand(time(0));
    
    // Заполнение матрицы случайными числами от -50 до 50
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 101 - 50; // числа от -50 до 50
        }
    }
    
    // Вывод матрицы
    cout << "\nСгенерированная матрица " << N << "x" << M << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Поиск особых элементов
    cout << "\nЭлементы, которые являются максимальными в своем столбце ";
    cout << "и минимальными в своей строке:" << endl;
    
    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int current = matrix[i][j];
            bool isMaxInColumn = true;
            bool isMinInRow = true;
            
            // Проверка максимума в столбце
            for (int k = 0; k < N; k++) {
                if (matrix[k][j] > current) {
                    isMaxInColumn = false;
                    break;
                }
            }
            
            // Проверка минимума в строке
            for (int k = 0; k < M; k++) {
                if (matrix[i][k] < current) {
                    isMinInRow = false;
                    break;
                }
            }
            
            if (isMaxInColumn && isMinInRow) {
                cout << "Элемент " << current << " на позиции [" << i << "][" << j << "]" << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "Таких элементов не найдено" << endl;
    }
    
    return 0;
}