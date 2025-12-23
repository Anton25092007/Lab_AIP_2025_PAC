#include <iostream>
using namespace std;

int main() {
    double yards;  
    double meters; 

    cout << "Введите расстояние в ярдах: ";
    cin >> yards;

    meters = yards * 0.9144; 

    cout << yards << " ярд(ов) = " << meters << " метр(ов)" << endl;

    return 0;
}