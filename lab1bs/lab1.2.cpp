#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double x, y, z, s;


    x = 3.981 * pow(10, -2);  
    y = -1.625 * pow(10, 3);  
    //z = 0.512;
    cout << "Введите z: ";
    cin >> z;



  
    s = pow(2, -x) * sqrt(x + pow(fabs(y), 0.25)) * pow(exp(x - 1 / sin(z)), 1.0 / 3.0);

    cout << "s = " << s << endl;

    return 0;
}
