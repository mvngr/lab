#include <iostream>
#include <string>

using namespace std;
void getDim(string m, int & row, int & col) { //определяет размеры
    // в эту функцию передаются указатели на память
    // в следствии чего я изменяю col и row, не возвращая ничего
    row = 0; col = 0;

    for (int i = 0; i < m.size(); i++){
        switch (m[i]) {
        case ';': row++; break;
        case ',': col++; break;
        default: break;
        }
    }
    row++; //на одно значение меньше (в конце нет ";")
    col /= row; //находим строки
    col++;
    return;
}

void printData(string s) {
    int row, col;
    getDim(s, row, col);
    cout << '\n' << row << ',' << col << "\n\n";

    int firstPoint = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ';') {
            cout << s.substr(firstPoint, i - firstPoint) << '\n';
            firstPoint = i+1;
        }
    }
    cout << s.substr(firstPoint, s.size() - firstPoint) << '\n';
    return;
}

void editString(string & str, string from, string to) {

    while (str.find(from) != -1) {
    size_t t = str.find(from);
    str = str.substr(0,t) + to + str.substr(t+from.size(), str.size());
    }
    return;
}

void notLogical(string & s) {
    editString(s,"!0","1");
    editString(s,"!1","0");
    return;
}

void orLogical(string & s) {
    editString(s,"0||0","0");
    editString(s,"0||1","1");
    editString(s,"1||0","1");
    editString(s,"1||1","1");
    return;
}

void andLogical(string & s) {
    editString(s,"0&&0","0");
    editString(s,"0&&1","0");
    editString(s,"1&&0","0");
    editString(s,"1&&1","1");
    return;
}

void changeAB(string &s, int a, int b) {
    editString(s,"a", to_string(a));
    editString(s,"b", to_string(b));
    return;
}

void getSimple(string &s) {
    notLogical(s);
    andLogical(s);
    orLogical(s);
    return;
}

void input(string s, int a, int b) {
    changeAB(s,a,b);
    cout << s << " = ";
    getSimple(s);
    cout << s << endl;
    return;
}

void fn(string s) {
    int a, b;
    int & lFirst = a,
        & lSecond = b; //ссылка на букву, по которой будет первый и второй цикл соответственно

    if (s.find('a')!=-1) {
        a = 1;
        lFirst = a;
        lSecond = b;
    }
    else {
        a = -1;
        lFirst = b;
        lSecond = a;
    }
    s.find('b')!=-1?b=1:b=-1;

    if(lFirst == lSecond == -1) //там нет букв, следовательно мы выводим поданный результат
        return;

    for (int i = 0; i <= lFirst; i++) {
        if(lSecond==-1)
        input(s, i, -1);
        for (int j = 0; j <= lSecond; j++)
            input(s,i,j);
    }

}

void headerPrint(string s) {

    int st;
    cout << "header code:\n";
    while(s.find(") {") != -1) {
        size_t t = s.find(") {");
        for(int i = t; i != 0; i--)
            if (s[i] == '\n') {
                st = i;
                break;
            }
        cout << s.substr(st, t - st + 1);
        s[t] = '.';
    }
}

void coursePrint(string s) {

    int finish;
    cout << "\n\ncourse code:\n\n";

    while(s.find(") {") != -1) {
        size_t t = s.find(") {");
        for(int i = t; i < s.size() - 1; i++)
            if (s[i] == '}' && s[i+1] == '\n') {
                finish = i;
                break;
            }
        cout << s.substr(t+4, finish - t - 5) << "\n\n";
        s[t] = '.';
    }
}

void splitHC(string s) {

    headerPrint(s);
    coursePrint(s);

    return;
}

void divide(int n) {
    //todo
}

int main() {

    string m;
    int n;

    //#3
    //cin >> m;
    //printData(m);
    //m.clear();
    //#4
    //cin >> m;
    //fn(m);
    //m.clear();
    //#5
    //m = "#include <iostream>\ndouble sum (double a, double b) {\nreturn a + b;\n}\nint main () {\ncout << sum (3, 2) << endl;\nreturn 0;\n}\n";
    //splitHC(m);
    //#6
    //cin >> n;
    //divide(n);

    return 0;
}
