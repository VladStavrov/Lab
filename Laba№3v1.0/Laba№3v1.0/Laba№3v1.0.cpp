
#include <iostream>
#include<conio.h>
using namespace std;
struct Stack {
    int info;
    Stack* next;
};

void ViewStack(Stack* begin);

void DeletinAllStack(Stack*& begin);


    
void SortStackInfo(Stack* begin);  
void Individ(Stack*& begin);
Stack* PreStack(Stack*& begin, Stack* adress);
void OutStack(Stack*& begin);
void SortStackAdress(Stack*& begin);
void SortStackAdress2(Stack*& begin);
void AddStack(Stack*& begin);
void ViewStackEND(Stack* begin);
void Sort_p(Stack** p);
int main()
{
    
    Stack* begin=0;
    setlocale(LC_ALL, "rus");
    char value;
    do {
        cout << "\t1.Создать новый список(старый удалится)\n\t2.Добавить элементы\n\t3.Просмтотреть список\n" <<
            "\t4.Просмотреть список с конца\n\t5.Сортировать по\n\t6.Сортировать\n\t0.Индивидуальное задание\n\tПробел - удалить все и завершить программу(default)\n\t";

        cout << "\tОжидание ввода ..." << endl;
        value = _getch();
        cout << value << endl;
        if (value != '1' && value != '2' && begin == 0) {
            cout << "Пусто" << endl;
            continue;
        }
        switch (value)
        {

        case '1':case'2': {
            if (value == '1') {
                DeletinAllStack(begin);

            }
            cout << "Введите количество элементов" << endl;
            int n;
            while (1) {

                cin >> n;
                if (n < 1) {
                    cout << "Введите корректное значени" << endl;
                }
                else break;

            }
            for (int i = 0; i < n; i++)
            AddStack(begin);

            break;
             
        }
        case'3': {
            ViewStack(begin);
            continue;

        }
        case'4': {
            ViewStackEND(begin);
            continue;

        }
        case'5': {
            ViewStack(begin);
            SortStackAdress(begin);
            cout << "Резльтат после сортировки:" << endl;
            ViewStack(begin);
            continue;
        }

        
        case'0': {
            cout << "Было:" << endl;
            ViewStack(begin);
            Individ(begin);
            cout << "Стало:" << endl;
            ViewStack(begin);
            continue;
        }
        default: {

            value = 0;
            DeletinAllStack(begin);
            break;
        }
        }

    } while (value);
   
}

void ViewStack(Stack* begin) {

    if (!begin) {
        cout << "Пусто" << endl;
    }
    while (begin) {

        cout << begin->info << "  ";

        begin = begin->next;
    }
    cout << endl;



}
void ViewStackEND(Stack* begin) {

    if (!begin) {
        return;
    }
    
        ViewStackEND(begin->next);
        cout << begin->info << "  ";

        
    
    



}
void DeletinAllStack(Stack*& begin) {
    if (!begin) {
        cout << "Пусто" << endl;
    }
    Stack* t;
    while (begin) {
        t = begin;
        begin = begin->next;
        delete t;
    }

}
void SortStackInfo(Stack* begin) {



    if (!begin) {
        cout << "Пусто" << endl;
    }
    int k;
    Stack* t = begin;
    Stack* t1 = t;
    do {
        k = 0;
        for (t1 = t; t1->next; t1 = t1->next) {

            if (t1->info > t1->next->info) {//a=a+b; b=a-b; a=a-b;
                t1->info += t1->next->info;
                t1->next->info = t1->info - t1->next->info;
                t1->info -= t1->next->info;
                k = 3;
            }


        }


    } while (k);
    cout << "Стеки отсортированы\n";


}

void OutStack(Stack*& beginOfDelete,Stack *&begin, Stack*& preStack) {

    if (beginOfDelete == begin) {
        OutStack(begin);

        return;
    }
    preStack = PreStack(begin, beginOfDelete);
    if (!beginOfDelete->next) {
        preStack->next = 0;


    }
    else {
        preStack->next = beginOfDelete->next;

    }
    delete beginOfDelete;

}

void Individ(Stack*& begin) {

    
    Stack* t, * max = begin, * preStack;
    t = begin;
    int kol = 0;
    int ch = begin->info;

    for (t; t; t = t->next) {

        if (t->info >= max->info) {
            if (t->info == ch) {
                kol++;
            }
            else kol = 1;
            max = t;
            ch = max->info;
        }

    }
    cout << "max = " << max->info << endl;
    cout << "kol = " << kol << "  " << ch << endl;


    for (int i = 0; i < kol; i++) {
         
        for (t=begin; t; t = t->next) {

            if (t->info ==ch) {
                OutStack(t, begin, preStack);
                break;
            }

        }


   }


}
Stack* PreStack(Stack*& begin, Stack* adress) {
    if (!begin) {
        cout << "Пусто" << endl;
    }
    Stack* t = begin;
    for (t; t->next; t = t->next) {
        if (t->next == adress) {
            return t;
        }


    }

    return 0;


}
void OutStack(Stack*& begin) {
    if (!begin) {
        cout << "Пусто" << endl;
    }
    Stack* t = begin;

    begin = begin->next;
    delete t;


}
void SortStackAdress(Stack*& begin) {



    if (!begin) {
        cout << "Пусто" << endl;
    }

    Stack* t = begin, * t1, * r, * h, * z;

    Stack* t3 = new Stack;
    t1 = begin;
    t3->next = begin;
    h = t3;


    int k;
    do {
        k = 0;


        for (t3 = h; t3->next->next; t3 = t3->next) {

            if (t3->next->info < t3->next->next->info) {//a=a+b; b=a-b; a=a-b;
                z = t3->next->next;
                t3->next->next = z->next;
                z->next = t3->next;
                t3->next = z;

                k = 3;
            }


        }


    } while (k);
    t3 = h;
    Stack* n = h->next;
    begin = n;
    delete t3;
    cout << "Стеки отсортированы\n";


}
void SortStackAdress2(Stack*& begin) {



    if (!begin) {
        cout << "Пусто" << endl;
    }

    Stack* t = begin, * t1, * r, * h, * z, * s;

    Stack* t3 = new Stack;
    t1 = begin;
    t3 = begin;
    h = t3;
    int pup;

    int k, m;
    do {
        k = 0;
        m = 1;
        s = h;
        r = t3;
        for (t3 = h; t3->next; t3 = t3->next) {
            pup = 0;
            if (t3->info < t3->next->info) {//a=a+b; b=a-b; a=a-b;
                if (t3 == h) {
                    pup = 1;

                }
                else {
                    if (m != 1)
                        s = s->next;

                }
                m++;
                z = t3->next;
                t3->next = z->next;
                z->next = t3;
                t3 = z;

                if (pup) {
                    h = t3;
                }
                else
                    s->next = t3;
                k = 3;
            }


        }


    } while (k);
    t3 = h;
    Stack* n = h->next;
    begin = n;
    delete t3;
    cout << "Стеки отсортированы\n";
    ViewStack(begin);
    ViewStack(begin);

}
void AddStack(Stack*& begin) {
    Stack* t = new Stack;
    t->next = begin;
    begin = t;
    cout << "Введите информацию" << endl;
    cin >> t->info;

}
void Sort_p(Stack** p) {

    Stack* t = NULL, * t1, * r;

    if ((*p)->next->next == NULL) return;

    do {

        for (t1 = *p; t1->next->next != t; t1 = t1->next)

            if (t1->next->info > t1->next->next->info) {

                r = t1->next->next;

                t1->next->next = r->next;

                r->next = t1->next;

                t1->next = r;

            }

        t = t1->next;

    } while ((*p)->next->next != t);

}