#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    string input;
    cout << "Введите строку: ";
    cin >> input; // Считываем только первое слово

    int count = 0;

    // Перебираем символы напрямую (range-based for)
    for (char c : input)
    {
        if ((unsigned char)c == 224 ||  // 'а'
            (unsigned char)c == 192 ||  // 'А'
            c == 'a' || c == 'A')
        {
            count++;
        }
    }

    cout << "Количество букв 'а' в первом слове: " << count << endl;

    return 0;
}
