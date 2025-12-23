#include <iostream>
using namespace std;

int main() {
    double a, b, c, s;
    cin >> a >> b >> c;


    double max = a;
    double min = a;

    if (b > max) max = b;
    if (c > max) max = c;
    
    if (b < min) min = b;
    if (c < min) min = c;

    s = max - min;

    cout << "Разница: " << s << endl;
    return 0;
}