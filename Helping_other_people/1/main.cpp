#include <iostream>
#include <string>
#include <time.h>

using namespace std;
struct User{
    string name; //имя
    string surname; //фамилия
    string middlename; //отчество
    string adress; //адрес
    int DD; //дата (день)
    int MM; //дата (месяц)
    int YYYY; //дата (год)
    double averageMark; //средняя оценка
};
const int namesCounter = 7;
const string names[] = {"Петя", "Вася", "Вова", "Саша", "Олег", "Дима", "Миша"};
const int surnamesCounter = 7;
const string surnames[] = {"Волков", "Смолин", "Куницын", "Недалеков", "Серпин", "Марев", "Конютин"};
const int middlenamesCounter = 7;
const string middlenames[] = {"Александрович", "Алексеевич", "Яковлевич", "Андреевич", "Сергеевич", "Олегович", "Дмитриевич"};
const int adressesCounter = 5;
const string adresses[] = {"ул. Пушкина д. 6", "ул. Колотушкина д.1", "пр-т. Декабристов д. 12", "ул. Баха д. 1", "пр-д. Безрукова д.5"};
int main()
{
    int usersCount = 0; //количество записей
    User *arr; //массив с динамическим выделением памяти (для создания N кол-ва записей, где N вводится с клавиатуры)
    cout << "Введите количество автоматически генерируемых записей: " << endl;
    cin >> usersCount;
    arr = new User[usersCount]; //создаем массив для переменных
    int cuc = usersCount - 1; //cuc - CopyUsersCount копия количества пользователей. Сократил для читабельности кода. usersCount - 1 = костыль, я знаю
    srand (time(NULL)); //для создания рандомных записей используем функцию генерации рандомных чисел
    while(cuc >= 0){
        User newUser;
        newUser.name = names[rand()%namesCounter]; //rand()%namesCounter больше или равна нулю, но меньше namesCounter. names[..] - какая-то из этих записей
        newUser.surname = surnames[rand()%surnamesCounter];
        newUser.middlename = middlenames[rand()%middlenamesCounter];
        newUser.adress = adresses[rand()%adressesCounter];
        newUser.DD = rand()%31 + 1; //не будем заморачиваться с разными вариантами дат, и так код большой получился
        newUser.MM = rand()%12 + 1; //+1 нужно для того, чтобы у нас не было 0 дата нулевого месяца, а тоолько была 1 дата 1 месяца
        newUser.YYYY = rand()%100 + 1900; //делаем адекватную дату по тем же принципам
        newUser.averageMark = (double)(rand()%5)+(double)(rand()%100)/100 + 1; //double нужно для того, чтобы в последствии при делении мы могли бы получить нецелое число

        arr[cuc] = newUser; //записываем с конца в начало, а какая разница? Как хочу, так и делаю :P
        cuc--;
    }

    cout << "Все пользователи:" << endl;
    cuc = usersCount - 1;
    while (cuc >= 0) {
        cout << arr[cuc].surname << " " << arr[cuc].name << " " << arr[cuc].middlename << ", " << arr[cuc].adress
             << ", " << arr[cuc].DD << "." << arr[cuc].MM << "." << arr[cuc].YYYY << ", " << arr[cuc].averageMark << endl;
        cuc--;
    }

    // #1
    cuc = usersCount - 1;
    while(cuc >= 0){
        //дабы не было лишних функций не буду выносить печать одного пользовалеля как отдельную f
        if(arr[cuc].YYYY == 1981)
            cout << arr[cuc].surname << " " << arr[cuc].name << " " << arr[cuc].middlename << ", " << arr[cuc].adress
                 << ", " << arr[cuc].DD << "." << arr[cuc].MM << "." << arr[cuc].YYYY << ", " << arr[cuc].averageMark << endl;
        cuc--;
    }

    // #2
    cuc = usersCount - 1;
    double max = -1, min = 6; //макс и мин значения оценок. Такие изначальные значения мы завели, чтобы наша программа точно что-то, да записала бы
    int maxInd, minInd; //индексы их владельцев в массиве arr
    while(cuc >= 0){
        if(arr[cuc].averageMark > max){
            max = arr[cuc].averageMark;
            maxInd = cuc;
        }
        if(arr[cuc].averageMark < min){
            min = arr[cuc].averageMark;
            minInd = cuc;
        }
        cuc--;
    }
    cout << "Наибольший результат у: " << arr[maxInd].surname << " " << arr[maxInd].name << " " << arr[maxInd].middlename << endl;
    cout << "Наименьший результат у: " << arr[minInd].surname << " " << arr[minInd].name << " " << arr[minInd].middlename << endl;

    // #3
    cuc = usersCount - 1;
    while(cuc >= 0){
        if(arr[cuc].averageMark == 4.4)
            cout << arr[cuc].surname << " " << arr[cuc].name << " " << arr[cuc].middlename << ", " << arr[cuc].adress
                 << ", " << arr[cuc].DD << "." << arr[cuc].MM << "." << arr[cuc].YYYY << ", " << arr[cuc].averageMark << endl;
        cuc--;
    }

    return 0;
}
