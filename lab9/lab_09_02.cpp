#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <cmath> 
#include <fstream> 
#include <iomanip>
#include <vector>

using namespace std;

void getDim(string m, int & row, int & col) { //определяет размеры
    // в эту функцию передаются указатели на память
    // в следствии чего я изменяю col и row, не возвращая ничего
 row= 0; col = 0;

 for (int i= 0; i < m.size(); i++){
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

 int firstPoint= 0;
 for(int i= 0; i < s.size(); i++) {
 if(s[i]== ';') {
            cout << s.substr(firstPoint, i - firstPoint) << '\n';
 firstPoint= i+1;
        }
    }
    cout << s.substr(firstPoint, s.size() - firstPoint) << '\n';
    return;
}

void editString(string & str, string from, string to) {

 while (str.find(from) != -1) {
 size_t t= str.find(from);
 str= str.substr(0,t) + to + str.substr(t+from.size(), str.size());
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

string specificToStringAB(int num) {
 if (num==1) return "1";
    else return "0";
}

void changeAB(string &s, int a, int b) {
    editString(s,"a", specificToStringAB(a));
    editString(s,"b", specificToStringAB(b));
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
 cout << s << "= ";
    getSimple(s);
    cout << s << endl;
    return;
}

void fn(string s) {
    int a, b;
 int & lFirst= a,
 & lSecond= b; //ссылка на букву, по которой будет первый и второй цикл соответственно

 if (s.find('a')!=-1) {
 a= 1;
 lFirst= a;
 lSecond= b;
    }
    else {
 a= -1;
 lFirst= b;
 lSecond= a;
    }
 s.find('b')!=-1?b=1:b=-1;

 if(lFirst== lSecond == -1) //там нет букв, следовательно мы выводим поданный результат
        return;

 for (int i= 0; i <= lFirst; i++) {
 if(lSecond==-1)
        input(s, i, -1);
 for (int j= 0; j <= lSecond; j++)
            input(s,i,j);
    }

}

void headerPrint(string s) {

    int st;
 cout << "header code:\n";
 while(s.find(") {") != -1) {
 size_t t= s.find(") {");
 for(int i= t; i != 0; i--)
 if (s[i]== '\n') {
 st= i;
                break;
            }
        cout << s.substr(st, t - st + 1);
 s[t]= '.';
    }
}

void coursePrint(string s) {

    int finish;
 cout << "\n\ncourse code:\n\n";

 while(s.find(") {") != -1) {
 size_t t= s.find(") {");
 for(int i= t; i < s.size() - 1; i++)
 if (s[i]== '}' && s[i+1] == '\n') {
 finish= i;
                break;
            }
        cout << s.substr(t+4, finish - t - 5) << "\n\n";
 s[t]= '.';
    }
}

void splitHC(string s) {

    headerPrint(s);
    coursePrint(s);

    return;
}

void divide(int n) {
 int res= 0;
 for(int i= 1; i <= 1000; i++) {
 i%n==0?res++:false; //false для того, чтобы он ничего не делал. Можно написать true, ничего не изменится
    }
    cout << '\n' << res << endl;
}

vector<vector<int> > badMatrix() {
    vector<vector<int> > a;
    return a;
}

vector<vector<double> > readMatrix (char * link) {
 ifstream fileIn(link, ios::in);
	int n, m;
	char c;
	fileIn >> m >> c >> n;
	vector<vector<double> > arr (m);
 for (int i= 0; i < m; i++) {
		arr[i].resize(n);
 for (int j= 0; j < n; j++) {
			fileIn >> arr[i][j];
		}
	}
	return arr;
}

double sum (double a, double b) {
	return a + b;
}

void fn_or() {
 for (bool x= 0; x < 1; x++) {
 for (bool y= 0; y < 1; y++) {
			cout << (x || y) << "\n";
		}
	}
}

void fn_and() {
 for (bool x= 0; x < 1; x++) {
 for (bool y= 0; y < 1; y++) {
			cout << (x && y) << "\n";
		}
	}
}

vector<vector<double> > multiplyByMatrix(vector<vector<double> > matrix1, vector<vector<double> > matrix2) {
 int m1= matrix1.size(),
 n1= matrix1[0].size(),
 m2= matrix2.size(),
 n2= matrix2[0].size();
 if (n1 != m2) 
		printf("\nmultiply err\n\n");
	vector<vector<double> > arr;
	arr.resize(m1);
 for (int i= 0; i < m1; i++) {
		arr[i].resize(n2);
 for (int j= 0; j < n2; j++) {
 double sum= 0.0;
 for (int k= 0; k < n1; k++) {
 sum += matrix1[i][k] * matrix2[k][j];
			}
 arr[i][j]= sum;
		}
	}
	return arr;
}

void saveMatrix(vector<vector<double> > arr, char * link) {
 ofstream fileOut(link, ios::out);
	fileOut << arr.size() << ',' << arr[0].size() << "\n";
 for (int i= 0; i < arr.size(); i++) {
 for (int j= 0; j < arr[0].size(); j++) {
			fileOut << arr[i][j];
			if (j < arr[0].size() - 1) {
				fileOut << ',';
			}
		}
		fileOut << "\n";
	}
}

int main() {

    string m;
    int n;
    setlocale(LC_ALL, "rus");

    //#3
    cin >> m;
    printData(m);
    m.clear();
    //#4
    cin >> m;
    fn(m);
    m.clear();
    //#5
    m= "#include <iostream>\ndouble sum (double a, double b) {\nreturn a + b;\n}\nint main () {\ncout << sum (3, 2) << endl;\nreturn 0;\n}\n";
    splitHC(m);
    //#6
    cin >> n;
    divide(n);
    //#7
    saveMatrix(multiplyByMatrix(readMatrix("matrix1.txt"), readMatrix("matrix2.txt")), "matrix3.txt");


    return 0;
}
