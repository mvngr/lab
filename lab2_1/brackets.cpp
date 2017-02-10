#include <iostream>
#include <string>

using namespace std;

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

bool Work(char c, BList *&MyList) {
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
        Add(c, MyList); break;
    default: break;
    }
    return true;
}

int main() {

    string a;
    BList *solution = new BList;
    solution -> Head = NULL;

    cin >> a;

    for(int i = 0; i < a.size(); i++)
        if (!Work(a[i], solution)) {
            cout << "Error in " << i << "char!" << endl;
        }
    if (solution->Head != NULL)
        cout << "Error in recent char! char: " << solution->Head->bracket << endl; //todo плохо работает
    else
        cout << "All right!";

    Print(solution);

    cout << "\n\n Delete Solution... \n";
    ClearAllList(solution);

    return 0;
}
