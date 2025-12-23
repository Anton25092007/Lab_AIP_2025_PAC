#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипы функций
double y(const double &x);
double s(const double &x, const double &epsilon, int &n);

int main()
{
    double a = -0.5; 
    double b = 0.5;
    double h;
    double epsilon = pow(10, -4); 
    
 
    
    // Расчет шага
    h = (b - a) / 10;
    
    // Заголовок таблицы
    cout << "\n" << string(60, '-') << endl;
    cout << setw(10) << "x" << setw(15) << "y(x)" << setw(15) << "s(x)" 
         << setw(15) << "n" << setw(15) << "|y-s|" << endl;
    cout << string(60, '-') << endl;
    
    // Вычисление и вывод таблицы
    for (int i = 0; i <= 10; i++)
    {
        double x = a + i * h;
        int n_terms;
        double y_value = y(x);
        double s_value = s(x, epsilon, n_terms);
        double difference = fabs(y_value - s_value);
        
        cout << fixed << setprecision(6);
        cout << setw(10) << x << setw(15) << y_value << setw(15) << s_value
             << setw(15) << n_terms << setw(15) << difference << endl;
    }
    
    cout << string(60, '-') << endl;
    
    return 0;
}

// Функция для вычисления точного значения y(x) = e^x
double y(const double &x)
{
    return exp(x);
}

// Функция для вычисления разложения в ряд s(x) с заданной точностью
double s(const double &x, const double &epsilon, int &n)
{
    double sum = 1.0; // первый член ряда (n=0)
    double term = 1.0; // текущий член ряда
    n = 1; // начинаем с n=1
    
    // Вычисление суммы ряда до достижения заданной точности
    while (fabs(term) > epsilon)
    {
        term = term * x / n; // вычисляем следующий член ряда
        sum += term;
        n++;
        
        // Защита от бесконечного цикла
        if (n > 1000) break;
    }
    
    return sum;
}