#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    
    cout << "Введите строку из нулей и единиц: ";
    cin >> input; // Считываем строку без пробелов

    // Проверяем, что строка содержит только '0' и '1'
    for (char c : input)
    {
        if (c != '0' && c != '1')
        {
            cout << "Ошибка: строка должна содержать только нули и единицы!" << endl;
            return 1;
        }
    }
    
    string result;
    
    // Используем int вместо size_t
    for (int i = 0; i < (int)input.length(); i++)
    {
        if (i + 2 < (int)input.length() && 
            input[i] == '0' && 
            input[i + 1] == '0' && 
            input[i + 2] == '0')
        {
            i += 2; // Пропускаем три нуля
        }
        else
        {
            result += input[i];
        }
    }
    
    cout << "Исходная строка: " << input << endl;
    cout << "Результат: " << result << endl;
    
    return 0;
}
