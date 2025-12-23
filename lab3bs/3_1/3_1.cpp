#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;



int main() {
    int a, b, n;
    
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите n: ";
    cin >> n;
    
    if (a >= b) {
        cout << "a должно быть меньше b!" << endl;
        return 1;
    }
    
    double h = (b - a) / 10.0;
    double x = a;
    
    
    cout << fixed << setprecision(4);
    cout << " x\t| y(x)" << endl;
    cout << "----------------" << endl;
    
    while (x <= b) {
        double y = 0.0;
        for (int i = 1; i <= n; i++) {
            y += 2 * pow(tan(i * x), 2) - sqrt(x);
        }



        

        cout << x << "\t| " << y << endl;
        x += h;
    }
    
    return 0;
}