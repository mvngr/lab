#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#define PI 3.14159

using namespace std;

void getCosSinTable();
double perimeter(double array[], int len);

int main() {

    char name[30];
    int age, day, month, year;

    cout << "Name:\n";
    cin >> name;
    cout << "Здравствуйте, " << name << "! Сколько Вам лет?\n";
    cin >> age;
    cout << age << " - замечательный возраст, " << name <<
            "!\nПозвольте узнать, когда Ваш День Рождения?\n";
    cin >> day >> month >> year;
    cout <<"Надеюсь, что Вы хорошо отметите свой День Рождения "
        << day << " числа " << month << " месяца\n";

    int a = 10;
    const int b = 3;
    bool t = true, f = false;
    double c = 3.2, d = 4.7;
    char e = 'n', r = 110;
    cout << "bool type" << endl;
    cout << " t AND f = " << (t && f) <<
            ";\n t OR f = " << (t || f) << endl; // endl='\n'
    cout << "int type" << endl;
    cout << " a+b = " << (a+b) <<
            ";\n a/b = " << (a/b) <<
            ";\n (double) a/b = " << ((double) a/b) <<
            ";\n a%b = " << (a%b) << endl;
    cout << " a++ = " << (a++) <<
            ";\n ++a = " << (++a) <<
            ";\n a-- = " << (a--) <<
            ";\n --a = " << (--a) << endl;
    cout << "double type" << endl;
    cout << " c+d = " << (c+d) << ";\n c/d = " << (c/d) <<
            endl;
    cout << " e = " << e << ";\n r = " << r << ";\n" << endl;
    string str;
    string header = "Big news!!";
    string body = "Scientists developed new rules for "
                  "happiness!";
    cout << header + " " + body << endl; // сложение строк
    cout << body.append(" Really?")
         << endl; // сложение строки
    body.push_back('!'); // добавление символа к строке
    cout << body << endl;
    str.assign(body,0,10); // выделение фрагмента строки
    cout << str;
    cout << str.size() << endl; // длина строки
    cout << str.length() << endl << endl; // длина строки
    // Ввод строк с клавиатуры
    string likeWeather, dislikeWeather;
    cout << "Какое у Вас любимое время года?\n";
    cin >> likeWeather;
    cout << "А нелюбимое? После окончания ввода"
            " введите символ ;\n";
    getline(cin, dislikeWeather, ';');
    cout << dislikeWeather << endl;
    cout << "Удалим символ '\\n': " <<
            dislikeWeather.substr(1,
                                  dislikeWeather.length()-1) <<
            endl; // выделение подстроки из строки
    cout << "Любимое время года: " << likeWeather << endl;
    cout << "Нелюбимое время года: " << dislikeWeather << endl;
    // Условия
    double temperature = 25;
    if (temperature > 15) {
        cout << "На улице хорошая погода\n";
    }
    else cout << "На улице прохладно\n";
    // Сокращенная форма условия - тернарный оператор
    (temperature > 15) ? cout << "На улице хорошая погода\n" :
                                 cout << "На улице прохладно\n";
    // Циклы
    cout << "Цикл for: ";
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
    }
    int i = 0;
    cout << "\nЦикл while: ";
    while (i < 10) {
        cout << i << " ";
        i++;
    }
    i = 0;
    cout << "\nЦикл do: ";
    do {
        cout << i << " ";
        i++;
    } while (i < 10);
    cout << endl << endl;
    // Массивы
    cout << "Массив: ";
    int array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = i%2;
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Длина массива: " << sizeof(array)/sizeof(int) <<
            endl << endl;
    //Указатели и функции
    int num = 5;
    int *pNum = &num;
    int **ppNum = &pNum;
    cout << "num = " << num << endl;
    cout << "*pNum = " << *pNum << endl;
    cout << "**ppNum = " << **ppNum << endl;
    cout << "&num = " << &num << endl;
    cout << "pNum = " << pNum << endl;
    cout << "&pNum = " << &pNum << endl;
    cout << "ppNum = " << ppNum << endl;
    double * arr;
    int arrLen = 4;
    arr = (double *) malloc(arrLen * sizeof(double));
    if (arr != NULL) {
        for (int i = 0; i < arrLen; i++) {
            arr[i] = (double) i/3;
        }
    }
    for (int i = 0; i < arrLen; i++) {
        cout << "arr[" << i << "] = " <<
                arr[i] << ", ";
    }
    free(arr);
    arr = NULL;
    cout << endl;
    double triangle[4];
    for (int i = 0; i < 4; i++) {
        triangle[i] = (double) i/3;
    }
    cout << "Perimeter (no pointer) = " <<
            perimeter( triangle,
                       sizeof(triangle)/sizeof(double) ) << endl;
    getCosSinTable();
    // Работа с файлами
    string writeStr = "We want you to know both C and C++";
    string readStr;
    //Открытие/создание файла, file - имя файла
    ofstream file1("example.txt");
    if (file1) {
        // Запись в файл
        file1 << writeStr; // запись строки
        file1.put('!'); // запись символа
        file1.close(); // закрыть файл
    }
    // Открытие файла на добавление
    ofstream file2("example.txt", ios::app);
    if (file2) {
        file2 << "\nHope, you enjoyed our course!";
        file2.close();
    }
    // Открытие файла на чтение
    ifstream file3("example.txt");
    char ch;
    if (file3) {
        file3.get(ch); // чтение символа
        while(!file3.eof()) {
            readStr += ch;
            file3.get(ch); // чтение символа
        }
        cout << readStr << endl;
        file3.close();
    }
    return 0;
}
void getCosSinTable() {
    cout << "angle | sin | cos" << fixed << setprecision(2) <<
            endl;
    cout << "0 | " << sin(0) << " | " << cos(0) <<
            endl;
    cout << "PI/6 | " << sin(PI/6) << " | " << cos(PI/6) <<
            endl;
    cout << "PI/4 | " << sin(PI/4) << " | " << cos(PI/4) <<
            endl;
    cout << "PI/3 | " << sin(PI/3) << " | " << cos(PI/3) <<
            endl;
    cout << "PI/2 | " << sin(PI/2) << " | " << cos(PI/2) <<
            endl;
}
double perimeter(double array[], int len) {
    double result;
    for (int i=0; i < len; i++) {
        result += array[i];
    }
    return result;
}
