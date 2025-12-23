#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double y(const double &x, const double &n) {
    double sum = 0.0;
    
    // Вычисляем сумму от i=1 до n
    for (int i = 1; i <= n; i++) {
        double term = 15 * pow(x, 2) - 4 * pow(cos(i * x), 3);
        sum += term;
    }
    
    return sum;
}

int main() {
    double a = 0.32;
    double b = 0.8;
    double n = 9;

    double h = (b - a) / 10;
    
    cout << "Таблица значений функции V(x, n)" << endl;
    cout << "n = " << n << ", a = " << a << ", b = " << b << ", h = " << h << endl;
    cout << fixed << setprecision(6);
    cout << "----------------------------------------" << endl;
    cout << "X\t\tY(x, n)" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i <= 10; i++) {
        double x = a + i * h;
        double result = y(x, n);
        cout << x << "\t\t" << result << endl;
    }
    
    return 0;
}