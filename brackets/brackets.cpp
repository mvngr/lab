#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lastInpOpenPos = -1;

struct BList {
    char bracket;
    BList *Next,*Head;
};
void Add(int x, BList *&MyList) {
    BList *temp = new BList;
    temp->bracket = x;
    temp->Next = MyList->Head;
    MyList->Head = temp;

    return;
}
void DelTop(BList *&MyList) {
    BList *temp = MyList->Head->Next;
    //cout << "Del " << MyList->Head->bracket << ' ';
    delete MyList->Head;
    MyList->Head = temp;

    return;
}
void Print(BList *MyList) {
    BList *temp = MyList->Head;
    while (temp != NULL) {
        cout<<temp->bracket<<" ";
        temp = temp->Next;
    }

    return;
}
void ClearAllList(BList *MyList) {
    while (MyList->Head != NULL)
        DelTop(MyList);
    delete MyList->Head;
    delete MyList;

    return;
}

bool Equivalence(char a, char b) {
    if ((a == '(' && b == ')') ||
            (a == '[' && b == ']') ||
            (a == '{' && b == '}'))
        return true;
    else return false;
}
bool Work(char c, BList *&MyList, int pos) {
    switch (c) {
    case ')':
    case '}':
    case ']':
        if (MyList->Head != NULL) {
            if (Equivalence(MyList->Head->bracket, c))
                DelTop(MyList);
        }
        else {
            Add(c, MyList);
            return false;
        }
        break;
    case '(':
    case '{':
    case '[':
        lastInpOpenPos = pos;
        Add(c, MyList); break;
    default: break;
    }

    return true;
}
void Errors(int pos, string str, bool before) {
    cout << "==============" << endl;
    if (!before)
        cout << "---> Error in " << pos+1 << " char!" << endl;
    else
        cout << "---> Error in front of this char or in this position: " << pos+1 << endl;

    cout << str.substr(0,pos) << "  " << str[pos] << "  " << str.substr(pos+1, str.size()-1) << endl;
    /*
     * Мини баг:
     * Из-за того, что я ленивый и не завел какой-либо вектор,
     * Чтобы хранить данные о последней позиции каждого типа скобок
     * У нас в ошибке будет выдавать неправильную позицию в таком примере, как:
     * (([]  ---> out: ((  [  ], хотя тут дело во второй круглой скобке
     *                     ^
     * Поэтому использую костыль с bool before
     */
    int m = 0;
    while (m != pos+2) {
        m++;
        cout << ' ';
    }
    cout << '^' << endl;
    cout << "==============" << endl;

    return;
}

int main() {

    string a;
    BList *solution = new BList;

    solution -> Head = NULL;

    cin >> a;

    for(int i = 0; i < a.size(); i++)
        if (!Work(a[i], solution, i)) {
            Errors(i, a, false);
            return 1;
        }
    if (solution->Head != NULL)
        Errors(lastInpOpenPos, a, true);
    else
        cout << "All right!";

    ClearAllList(solution);

    return 0;
}
