

#include <iostream>
#include<conio.h>
using namespace std;

struct Stack {

    Stack* next;
    char info;
};
struct Stack2 {

    Stack2* next;
    double info;
};

void AddStack(Stack2 *&begin,double info) {
    Stack2* t = new Stack2;
    t->next = begin;
    begin = t;
     t->info=info;

}
int Prior(char info) {

    switch (info)
    {
    case '(':
        return 1;
    case '+':case '-':
        return 2;

    case '/':case '*':
        return 3;

    default:
        return 0;

    }

}
double OutStack(Stack2*& begin, double info) {
    if (!begin) {
        cout << "Пусто" << endl;
    }
    Stack2* t = begin;
    info = begin->info;
    begin = begin->next;
    delete t;
    return info;

}
void AddStack(Stack*& begin, char info) {
    Stack* t = new Stack;
    t->next = begin;
    begin = t;
    t->info = info;

}
char OutStack(Stack*& begin, char info) {
    if (!begin) {
        cout << "Пусто" << endl;
    }
    Stack* t = begin;
    info = begin->info;
    begin = begin->next;
    delete t;
    return info;

}
void perevodVPolskZapis(char* In,char* Out) {
 
    Stack* begin = 0;
    int i = 0,g=0;
    char check = 0;
    for (; In[i] != 0; i++) {
        check = 0;
        switch (In[i]) {
        case '(': {
            AddStack(begin, In[i]);
            break;
        }
        case ')': {
            while (check!= '(') {
                check = OutStack(begin, check);
                if (check != '(') {
                    Out[g++] = check;
                }
            }
            break;
        }
        case '-':case '+':case'*':case '/': {
            while (begin && ((Prior(begin->info) >= (Prior(In[i]))))) {
                check = OutStack(begin, check);
                Out[g++] = check;
            }
            AddStack(begin, In[i]);
            break;
        }
        default: {
            Out[g++] = In[i];
            break;

        }
        }


        
    }
    while (begin) {
        check = OutStack(begin, check);
        Out[g++] = check;
    }
    cout << endl;
    Out[g] = '\0';
    cout << Out << endl;
    

}
void VvodChisel(double* arr, char* Out) {
    for (int i = 0; Out[i] != '\0'; i++) {
        if (Out[i] >= 'a' && Out[i] <= 'z') {
            cout << Out[i] << " = ";
            cin >> arr[int(Out[i] - 'a')];

        }
    }

}
double raschetPolsZapis(char* Out){
    double arr[50];

    int i;
    double k = 0, z = 0;
    double rez = 0;
    Stack2* begin2 = 0;
    VvodChisel(arr, Out);
    for (i = 0; Out[i] != '\0'; i++) {
        if (Out[i] >= 'a' && Out[i] <= 'z') {

            AddStack(begin2, arr[int(Out[i] - 'a')]);
            continue;
        }

        k = OutStack(begin2, k);
        z = OutStack(begin2, z);
        switch (Out[i])
        {
        case '-': {
            rez = z - k;
            break;
        }
        case '+': {
            rez = k + z;
            break;
        }
        case '*': {
            rez = k * z;
            break;
        }
        case '/': {
            rez = z / k;
            break;
        }
        default:
            break;
        }
        AddStack(begin2, rez);
    }

    return rez;

}

int main()
{
    setlocale(LC_ALL, "rus");
    char In[81]="", Out[81]="", value;
    
    do {
        cout << "\t1.Ввод и перевод формулы в обратную польскую запись\n\t2.Расчет формулы с помощью обратной польской записи\n\t3.Просмотр исходной формулы\n\t4.Просмотр ОПЗ\n\t5.Выход" << endl;
        value = _getch();
        cout << value << endl;
        switch(value) {
        case '1': {
            cout << "Введите формулу:" << endl;
            cin >> In;
            cout<<"Результат перевода в ОПЗ"<<endl;
            perevodVPolskZapis(In, Out);
            continue;
        }
        case '2': {
            if (Out[0] == '\0') {
                cout << "Изначальная формула еще не была введена" << endl;

            }
            else {
                cout << "Результат расчетов:" << endl;
                cout << raschetPolsZapis(Out) << endl;
            }
            continue;
        }
        case '3': {
            cout << "Исходная формула" << endl;
            if (In[0] == '\0') {
                cout << "Изначальная формула еще не была введена" << endl;
            }
            else
               
                cout << In << endl;
            continue;
        }
        case '4': {
            cout << "ОПЗ:" << endl;
            if (Out[0] == '\0') {
                cout << "Изначальная формула еще не была введена" << endl;
            }
            else
            
            cout << Out << endl;
            continue;
        }
            default:{
                value = 0;
        }
        }

    } while (value);

    
        
}








