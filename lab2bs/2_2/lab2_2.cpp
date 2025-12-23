#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int choice;
    double x, y;
    
    cout << "Выберите функцию f(x):" << endl;
    cout << "1: sh(x)" << endl;
    cout << "2: x" << endl;
    cout << "3: exp(x)" << endl;
    cout << "Введите номер (1/2/3): ";
    cin >> choice;
    
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    
   
    double f_val;
    string func_name;
    
    switch(choice) {
        case 1:
            f_val = sinh(x);
            func_name = "sh(x)";
            break;
        case 2:
            f_val = x;
            func_name = "x";
            break;
        case 3:
            f_val = exp(x);
            func_name = "exp(x)";
            break;
        default:
            cout << "Неверный выбор" << endl;
            return 1;
    }
    
  
    double xy_abs = abs(x * y);
    double k;
    string branch;
    
    if (xy_abs > 10) {
        k = log(abs(f_val) + abs(y));
        branch = "|xy| > 10";
    } else if (xy_abs < 10) {
        k = exp(f_val + y);
        branch = "|xy| < 10";
    } else { // |xy| == 10
        k = cbrt(abs(f_val)) + y;
        branch = "|xy| = 10";
    }
    
  
    cout << "\nФункция f(x): " << func_name << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "|x*y| = " << xy_abs << endl;
    cout << "Ветвь: " << branch << endl;
    cout << "Результат k = " << k << endl;
    
    return 0;
}