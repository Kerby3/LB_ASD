#include <iostream> //библиотека для работы с поточным вводом/выводом
#include <stack> //библиотека для работы со стеком
using namespace std; //используем именное пространство std, чтобы короче писать команды cout, endl и cin

bool check_brackets(string expression) { //функция проверки скобок
    stack<char> brackets; //стек для хранения скобок
    for (char c : expression) { //посимвольное чтение строки expression
        if (c == '[' || c == '(' || c == '{') { //если символ '[', '(', '{', то добавить символ в стек
            brackets.push(c); //то добавить символ в стек
            continue; //переход к следующему символу
        }
        if (brackets.empty()) //проверка на пустую строку
            return false;
        if (c == ']' && brackets.top() != '[') //если закрывающая скобка [ не равна последней открывающейся скобке,
            return false; //вернуть ложь
        if (c == ')' && brackets.top() != '(') //если закрывающая скобка ( не равна последней открывающейся скобке,
            return false; //вернуть ложь
        if (c == '}' && brackets.top() != '{') //если закрывающая скобка { не равна последней открывающейся скобке,
            return false; //вернуть ложь

        brackets.pop(); //удаляем последний добавившийся элемент
    }

    return brackets.empty(); //возвращает значение функции brackets.empty(), если стек пустой, вернется 1, если нет, вернется 0
}

bool checkString(string str) { //функция, проверяющая наличие посторонних символов в строке
    bool flag = false; //грязный флаг, с помощью него будем сигнализировать о наличии посторонних символов
    for (int i = 0; i < size(str); i++) { //проходимся по строке
        if (str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']' && str[i] != '{' && str[i] != '}') { //если есть что-то кроме скобок
        
            flag = true; //делаем флаг истинным
            break; //выходим из цикла
        }
    }
    return flag; //возвращаем флаг
}

int main() {
    setlocale(LC_ALL, "Russian"); //поддержка русского языка в консоли
    string str = ""; //строка, в которой будем хранить ввод
    cout << "Введите последовательность открывающихся и закрывающихся скобок:" << endl; // приглашение на ввод
    cin >> str; // ввод строки
    if (checkString(str)) { //вызов функции проверки на наличие посторонних символов в строке
        cout << "Некорректный ввод" << endl; // вывод сообщения, если строка не прошла проверку
        return 0; //завершить программу
    }
    bool result = check_brackets(str); // здесь хранится результат работы функции проверки на скобки
    if (result == 0) { // если результат 0
        cout << "Строка не существует" << endl; // то это значит, что строка проверку не прошла
    } else { // иначе
        cout << "Строка существует" << endl; // строка проверку прошла
    }
}