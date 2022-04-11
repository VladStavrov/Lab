
#include<stack>
#include <iostream>
#include<conio.h>
using namespace std;


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

void perevodVPolskZapis(char* In, char* Out) {
    stack<char> aaa;

    
    int i = 0, g = 0;
    char check = 0;
    for (; In[i] != 0; i++) {
        check = 0;
        switch (In[i]) {
        case '(': {
            aaa.push(In[i]);
         
            break;
        }
        case ')': {
            while (check != '(') {
                check = aaa.top();
                aaa.pop();
              
                if (check != '(') {
                    Out[g++] = check;
                }
            }
            break;
        }
        case '-':case '+':case'*':case '/': {
            while ((!aaa.empty()) && ((Prior(aaa.top()) >= (Prior(In[i]))))) {
             
                check = aaa.top();
                aaa.pop();
                Out[g++] = check;
            }
            aaa.push(In[i]);

            break;
        }
        default: {
            Out[g++] = In[i];
            break;

        }
        }



    }
    while (!aaa.empty()) {
        check = aaa.top();
        aaa.pop();
      
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
double raschetPolsZapis(char* Out) {
    double arr[50];
    stack<double> bbb;
    int i;
    double k = 0, z = 0;
    double rez = 0;
  
    VvodChisel(arr, Out);
    for (i = 0; Out[i] != '\0'; i++) {
        if (Out[i] >= 'a' && Out[i] <= 'z') {
            bbb.push(arr[int(Out[i] - 'a')]);
        
            continue;
        }
        k = bbb.top();
        bbb.pop();
     
        z = bbb.top();
        bbb.pop();
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
        bbb.push(rez);
      
    }

    return rez;

}

int main()
{
    setlocale(LC_ALL, "rus");
    char In[81] = "", Out[81] = "", value;

    do {
        cout << "\t1.Ввод и перевод формулы в обратную польскую запись\n\t2.Расчет формулы с помощью обратной польской записи\n\t3.Просмотр исходной формулы\n\t4.Просмотр ОПЗ\n\t5.Выход" << endl;
        value = _getch();
        cout << value << endl;
        switch (value) {
        case '1': {
            cout << "Введите формулу:" << endl;
            cin >> In;
            cout << "Результат перевода в ОПЗ" << endl;
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
        default: {
            value = 0;
        }
        }

    } while (value);



}








