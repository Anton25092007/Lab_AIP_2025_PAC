#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    srand(time(0));
    
    const int ROWS = 5;
    const int COLS = 5;
    int arr[ROWS][COLS];
    
    // Заполнение массива случайными числами от -50 до 50
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = (rand() % 101) - 50; // от -50 до 50
        }
    }
    
    // Вывод массива первоначального
    cout << "Массив 5x5 со случайными числами (-50 до 50):" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
        
    }
    cout << "____________________________";

    cout << "\nСуммы столбцов:" << endl;
    for (int j = 0; j < COLS; j++) {
        int sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += arr[i][j];
        }
        sum = sum/ROWS;
        cout << "Столбец " << j + 1 << ": " << sum << endl;
    }
    
    return 0;

    


}