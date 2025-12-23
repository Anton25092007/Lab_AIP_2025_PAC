#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Факториал
double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

// Разложение в ряд Тейлора для x^2 * e^(-x)
double taylor_series(double x, int terms = 10) {
    double sum = 0.0;
    for (int n = 0; n < terms; ++n) {
        double term = 0.0;
        if (n >= 2) {
            term = pow(-1, n) * n * (n - 1) * pow(x, n) / factorial(n);
        }
        sum += term;
    }
    return sum;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    int steps = 10;
    double h = (b - a) / steps;

    cout << fixed << setprecision(6);
    cout << " x\t\t y(x)\t\t s(x)\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i <= steps; ++i) {
        double x = a + i * h;
        double y = x * x * exp(-x);
        double s = taylor_series(x);
        cout << x << "\t " << y << "\t " << s << "\n";
    }

    return 0;
}
