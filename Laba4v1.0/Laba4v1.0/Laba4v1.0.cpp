#include<conio.h>
#include <iostream>
using namespace std;

struct Spis1 {

    Spis1* next,*prev;

    int info;
};

typedef void (* add)(Spis1* keyAdress, Spis1*& begin, Spis1*& end);
void addSpis1AfterKeyInfo(Spis1*& keyAdress, Spis1*& begin2, Spis1*& end2, Spis1*& begin, Spis1*& end);
void maxSpis1(Spis1*& keyAdress, Spis1* begin) {
    if (!begin) {
        cout << "Пусто" << endl;
        keyAdress = 0;
    }
    keyAdress = begin;
    while (begin) {

        if (begin->info > keyAdress->info) {
            keyAdress = begin;

        }

        begin = begin->next;
    }

}
void addSpis1BeforeKeyInfo(Spis1*& keyAdress, Spis1*& begin2, Spis1*& end2, Spis1*& begin, Spis1*& end);
void addSpis1END(Spis1*& begin, Spis1*& end);
void addSpis1START(Spis1*& begin, Spis1*& end);
void deleteFirstSpis1(Spis1*& begin, Spis1*& end);
void deleteAllSpis1(Spis1*& begin);
void deleteLastSpis1(Spis1*& begin, Spis1*& end);
void ViewSTARTStack1(Spis1* begin);
void ViewENDStack1(Spis1* end);
void deleteKeyAdress(Spis1 *& keyAdress, Spis1*& begin, Spis1*& end);
Spis1* PoiskKeyIndex(int &keyNumber,  Spis1* begin) {
    if (!begin) {

        return 0;
    }
    int kol = 0;
    for (; begin; begin = begin->next,kol++) {
        if (keyNumber == (kol+1)) {
            return begin;
        }
    }
    
        return 0;
    

}
int PoiskKeyInfo(int keyInfo, Spis1*& keyAdress, Spis1* begin, int numberOfElemnt = -1) {

    
    int kol = 0;
    if (!begin) {
        cout << "Пусто" << endl;
        return kol;

    }
    while (begin) {
        if (begin->info == keyInfo) {
            keyAdress = begin;
            kol++;
            if (kol == numberOfElemnt) {
                return 0;
            }
        }
        begin = begin->next;
    }
    if (!kol)
        return 0;
    return kol;


}
int kolStack1(Spis1* begin) {

    if (!begin) {
       
        return 0;
    }
    int kol = 0;
    for (; begin; begin = begin->next, kol++);
    return kol;



}
void SortStackAdress(Spis1*& begin) {



    if (!begin) {
        cout << "Пусто" << endl;
    }

    Spis1* t = begin, * r1, * r2, * r3, * r4,*h;

    Spis1* t3 = begin;
  
    t3->next = begin;
    h = t3;


    int k;
    do {
        k = 0;


        for (t3 = h; t3->next; t3 = t3->next) {

            if (t3->info < t3->next->info) {//a=a+b; b=a-b; a=a-b;
                
              
                r1 = t3->prev;
                r2 = t3; 
                r3 = t3->next;
                r4 = t3->next->next;
                

                r2->next = r4;
                r2 -> prev = r3;
                r3->next = r2;
                r3 ->prev = r1;
                r1->next = r3;
                r4->prev = r2;

                t3 = r2;

            

                k = 3;
            }


        }


    } while (k);
    
    cout << "Стеки отсортированы\n";


}
void addAfterKeyInfo(Spis1* keyAdress, Spis1*& begin, Spis1*& end);
void addBeforeKeyInfo(Spis1* keyAdress, Spis1*& begin, Spis1*& end);
int main()
{
    char value = 0;
    int kol = 0,n;
    Spis1* begin = 0, * end = 0,*keyAdress=0;
    setlocale(LC_ALL, "rus");
    do {
        cout << "\t1.Создать новый список(старый удалится)\n\t2.Добавить элементы в начало\n\t3.Добавить элементы в конец\n\t4.Просмтотреть список с начала \n" <<
            "\t5.Просмтотреть список с конца\n\t6.Удалить элементы с начала\n\t7.Удалить элементы с конца\n\t8.Добавить элементы после другого элемента" <<
            "\n\t9.Добавить элементы перед другим элементом\n\t0.Удалить найденный элемент\n\tПробел - удалить все и завершить программу(default)\n\t+ Индивидуальное задание\n";

        cout << "\tОжидание ввода ..." << endl;
        
        
        value = _getch();
        cout <<"\t"<< value << endl;
        switch (value)
        {

        case'1': {
            if (begin) {
              
                cout << "Ваш  список:" << endl;
                ViewSTARTStack1(begin);
                cout << "Все данные удалятся, вы Уверены?" << endl;
                cout << "Нажмите пробел, если согласны. Иначе вы будете возвращены в меню" << endl;
                value = _getch();
                if (value == ' ') {
                    deleteAllSpis1(begin);

                }
                else continue;
            }
           
                 

                cout << "Введите количество элементов" << endl;
                
                cin >> n;
                for (int i = 0; i < n; i++) {
                    addSpis1END(begin, end);
                }
                cout << "Ваш список:" << endl;
                ViewSTARTStack1(begin);

            
            break;


        }
        case '2': {

            cout << "Ваш  список:" << endl;
            ViewSTARTStack1(begin);
            cout << "Введите количество элементов, которые вы хотите добавить в начало списка:" << endl
            << "Ожидание ввода ..." << endl;
      
            
            cin >> n;
            for (int i = 0; i < n; i++) {
                addSpis1START(begin, end);
            }
            cout << "Ваш новый список:" << endl;
            ViewSTARTStack1(begin);
            break;
        }
        case '3': {

            cout << "Ваш  список:" << endl;
            ViewSTARTStack1(begin);
            cout << "Введите количество элементов, которые вы хотите добавить в конец списка:" << endl
                << "Ожидание ввода ..." << endl;


            cin >> n;
            for (int i = 0; i < n; i++) {
                addSpis1END(begin, end);
            }
            cout << "Ваш новый список:" << endl;
            ViewSTARTStack1(begin);
        }
        case'4': {

            cout << "Просмотр списка с начала:" << endl;
            ViewSTARTStack1(begin);
            break;
        }
        case'5': {

            cout << "Просмотр списка с конца:" << endl;
            ViewENDStack1(end);
            break;
        }
        case '6': {

            cout << "Ваш  список:" << endl;
            ViewSTARTStack1(begin);
            if (!begin) {
                continue;
            }
            kol = kolStack1(begin);
            cout << "Введите количество элементов, которые вы хотите удалить с начала списка:" << endl;
           
            while (1) {
                cin >> n;
                if (n<0 || n>kol) {
                    cout << "Введите коректное значение" << endl;
                    continue;
                }
                break;
            }
            for (int i = 0; i < n; i++) {
                deleteFirstSpis1(begin,end);

            }
            cout << "Ваш  новый список:" << endl;
            ViewSTARTStack1(begin);
            break;
        }
        case '7': {
           
            cout << "Ваш  список:" << endl;
            ViewSTARTStack1(begin);
            if (!begin) {
                continue;
            }
            kol = kolStack1(begin);
            cout << "Введите количество элементов, которые вы хотите удалить с конца списка:" << endl;

            while (1) {
                cin >> n;
                if (n<0 || n>kol) {
                    cout << "Введите коректное значение" << endl;
                    continue;
                }
                break;
            }
            for (int i = 0; i < n; i++) {
                deleteLastSpis1(begin, end);

            }
            cout << "Ваш  новый список:" << endl;
            ViewSTARTStack1(begin);
            break;
        }
        case '8':case'9': {
            cout << "Ваш  список:" << endl;
            ViewSTARTStack1(begin);
            if (!begin) {
                continue;
            }
            cout << "Выберите способ поиска элемента:\n" <<
                "1.По значению элемента(defafult)\n2.По порядковому номеру элемента\n";
            char value1 = _getch();
            cout << value1 << endl;
            switch (value1)
            {

            case '2': {
                cout << "Введите порядковый номер элемента" << endl;
                cin >> n;
                if (n < 1) {
                    cout << "Порядковый номер элемента введен некоректно" << endl;
                    continue;
                }
                keyAdress = PoiskKeyIndex(n, begin);
                if (!keyAdress) {
                    cout << "Порядковый номер элемента введен некоректно" << endl;
                    continue;
                }


                break;
            }
            default: {
                int kol = 0;
                cout << "Введите значение элемента" << endl;
                cin >> n;
                kol = PoiskKeyInfo(n, keyAdress, begin);
                switch (kol) {

                case 0: {
                    cout << "Такого элемента нет в списке" << endl;
                    continue;

                }
                case 1: {

                    break;
                }
                default: {
                    cout << "Элементов со значением: " << n << " целых " << kol << " штук" << endl;
                    cout << "Ваш  список:" << endl;
                    ViewSTARTStack1(begin);
                    cout << "Выберите порядковый номер элемента от 1 до " << kol << " который вам нужен" << endl;
                    while (1) {
                        int g;
                        cin >> g;
                        if (g<1 || g>kol) {
                            cout << "Введите корректное значение" << endl;
                            continue;
                        }
                        PoiskKeyInfo(n, keyAdress, begin, g);
                        break;
                    }



                    break;
                }
                }


                break; }

            }
            cout << "Введите количество элементов, которые вы хотите добавить..." << endl;
            int l;
            cin >> l;
            add k;
            if (value == '8') {
                k = addAfterKeyInfo;

            }
            else k = addBeforeKeyInfo;
            if (l > 1) {
                Spis1* begin2 = 0, * end2 = 0;
                for (int i = 0; i < l; i++) {
                    addSpis1END(begin2, end2);

                }
                if (k == addBeforeKeyInfo)
                    addSpis1BeforeKeyInfo(keyAdress, begin2, end2, begin, end);
                else  addSpis1AfterKeyInfo(keyAdress, begin2, end2, begin, end);
            }
            else {
                k(keyAdress, begin, end);

            }
            
            cout << "Ваш новый список:" << endl;
            ViewSTARTStack1(begin);
            break;
        }
        case '0': {
            cout << "Ваш  список:" << endl;
            ViewSTARTStack1(begin);
            if (!begin) {
                continue;
            }
            cout << "Выберите способ поиска элемента:\n" <<
                "1.По значению элемента(defafult)\n2.По порядковому номеру элемента\n";
            char value1 = _getch();
            cout << value1 << endl;
            switch (value1)
            {

            case '2': {
                cout << "Введите порядковый номер элемента" << endl;
                cin >> n;
                if (n < 1) {
                    cout << "Порядковый номер элемента введен некоректно" << endl;
                    continue;
                }
                keyAdress = PoiskKeyIndex(n, begin);
                if (!keyAdress) {
                    cout << "Порядковый номер элемента введен некоректно" << endl;
                    continue;
                }

                deleteKeyAdress(keyAdress, begin, end);
                break;
            }
            default: {
                int kol = 0;
                cout << "Введите значение элемента" << endl;
                cin >> n;
                kol = PoiskKeyInfo(n, keyAdress, begin);
                switch (kol) {

                case 0: {
                    cout << "Такого элемента нет в списке" << endl;
                    continue;

                }
                case 1: {
                    deleteKeyAdress(keyAdress, begin, end);
                    break;
                }
                default: {
                    cout << "Элементов со значением: " << n << " целых " << kol << " штук" << endl;
                    cout << "Ваш  список:" << endl;
                    ViewSTARTStack1(begin);
                    cout << "Введите сколько элементов вы хотите удалить из списка" << endl;
                    int p;
                    while (1) {
                        
                        cin >> p;
                        if (p<1 || p>kol) {
                            cout << "Введите корректное значение" << endl;
                            continue;
                        }

                        break;
                    }
                    
                    if (p == kol) {
                        int f = 1;
                        while (p)
                        {
                            
                            PoiskKeyInfo(n, keyAdress, begin, 1);
                            deleteKeyAdress(keyAdress, begin, end);
                          
                            p--;
                        }
                       
                    }
                    else {
                        int* array = new int[p];
                        cout << "Выберите порядковые номера элементов от 1 до " << kol << " который вам нужен" << endl;
                        int q = 0;
                        while (q<p) {

                            cin >> array[q];
                            if (array[q]<1 || array[q]>kol) {
                                cout << "Введите корректное значение" << endl;
                                continue;
                            }
                            q++;
                            
                        }
                        q = 0;
                        
                        while (q<p) {////////////////////////////////////////////////////////////////////PPPPPPPPRRRR

                            int i;

                           
                            for ( i = 0; i < q; i++) {
                                if (array[i] == array[q]) {
                                    
                                    break;
                                }
                            }
                            if (i == q) {
                                PoiskKeyInfo(n, keyAdress, begin, array[q] - q);
                                deleteKeyAdress(keyAdress, begin, end);

                                

                            }
                            q++;
                            
                        }
                        delete[]array;
                    }
                   


                    break;
                }
                }


                break; }

            }
            

            cout << "Ваш новый список:" << endl;
            ViewSTARTStack1(begin);
            break;
        }
        case '+': {
            maxSpis1(keyAdress, begin);
            n = keyAdress->info;
            if (!keyAdress) {
                continue;
            }
            kol = PoiskKeyInfo(keyAdress->info, keyAdress, begin);

            switch (kol) {


            case 1: {
                deleteKeyAdress(keyAdress, begin, end);
                cout << "Элементов с максимальным  значением: " << n << " целых " << kol << " штук" << endl;
                cout << "Ваш  список:" << endl;
                ViewSTARTStack1(begin);
                break;
            }
            default: {
                cout << "Элементов с максимальным  значением: " << keyAdress->info << " целых " << kol << " штук" << endl;
                cout << "Ваш  список:" << endl;
                ViewSTARTStack1(begin);
                cout << "Введите сколько элементов вы хотите удалить из списка" << endl;
                int p;
                while (1) {

                    cin >> p;
                    if (p<1 || p>kol) {
                        cout << "Введите корректное значение" << endl;
                        continue;
                    }

                    break;
                }

                if (p == kol) {
                    int f = 1;
                    while (p)
                    {

                        PoiskKeyInfo(n, keyAdress, begin, 1);
                        deleteKeyAdress(keyAdress, begin, end);

                        p--;
                    }

                }
                else {
                    int* array = new int[p];
                    cout << "Выберите порядковые номера элементов от 1 до " << kol << " который вам нужен" << endl;
                    int q = 0;
                    while (q < p) {

                        cin >> array[q];
                        if (array[q]<1 || array[q]>kol) {
                            cout << "Введите корректное значение" << endl;
                            continue;
                        }
                        q++;

                    }
                    q = 0;

                    while (q < p) {////////////////////////////////////////////////////////////////////PPPPPPPPRRRR

                        int i;


                        for (i = 0; i < q; i++) {
                            if (array[i] == array[q]) {

                                break;
                            }
                        }
                        if (i == q) {
                            PoiskKeyInfo(n, keyAdress, begin, array[q] - q);
                            deleteKeyAdress(keyAdress, begin, end);



                        }
                        q++;

                    }
                    delete[]array;
                }
                cout << "Ваш список" << endl;
                ViewSTARTStack1(begin);
                break; }
            }
            break; }

        default :
            deleteAllSpis1(begin);
            value = 0;
            break;
        }

    } while (value);

}   
void deleteLastSpis1(Spis1*& begin, Spis1*& end) {
    if (!begin) {

        cout << "Пусто" << endl;
        return;
    }

    Spis1* t=end;
    if (begin == end) {
        
        begin = 0;
        end = 0;
    }
    else {


        end = end->prev;
        end->next = 0;
    }

    delete t;

}
void addSpis1END(Spis1*& begin, Spis1*& end) {

    Spis1* t = new Spis1;
    cout << "Vvedite" << endl;
    cin >> t->info;
    t->next = 0;

    if (!end) {
        begin = t;
        t->prev = 0;
    }
    else {
        t->prev = end;
        end->next = t;

    }
    end = t;
}
void addSpis1START(Spis1*& begin, Spis1*& end) {

    Spis1* t = new Spis1;
    cout << "Vvedite" << endl;
    cin >> t->info;
    t->prev = 0;
   
    
   
    if (!end) {
        
    end = t;
    t->next = 0;
    }
    else {
        t->next = begin;
        begin->prev = t;
    }
    begin = t;
}
void deleteAllSpis1(Spis1*& begin) {
    if (!begin) {

        cout << "Пусто" << endl;
        return;
    }
    Spis1* t = begin;
    while (begin) {
        t = begin;
        begin = begin->next;
        delete t;
    }


}
void deleteFirstSpis1(Spis1*& begin, Spis1*& end) {
    if (!begin) {

        cout << "Пусто" << endl;
        return;
    }
  
    Spis1* t = begin;
    if (begin == end) {
        begin = 0;
        end = 0;
    } 
    else {

        begin = begin->next;
        begin->prev = 0;
    }

    delete t;

}
void ViewSTARTStack1(Spis1* begin) {

    if (!begin) {
        cout << "Пусто" << endl;
        return;
    }
    while (begin) {

        cout << begin->info << "  ";

        begin = begin->next;
    }
    cout << endl;



}
void ViewENDStack1(Spis1* end) {

    if (!end) {
        cout << "Пусто" << endl;
        
    } 
    while(end) {
        cout << end->info << "  ";
        end = end->prev;
    }
    cout << endl;
}
void deleteKeyAdress(Spis1*& keyAdress, Spis1*& begin, Spis1*& end) {

    if (!keyAdress) {
        cout << "Key=0!!!" << endl;
        return;
    }
    
    if (!begin) {
        cout << "Пусто" << endl;
        
    }
    else
    if (keyAdress == begin) {

        deleteFirstSpis1(begin, end);
       
    }else
    if (keyAdress == end) {

        deleteLastSpis1(begin, end);
        return;

    }
    else {
        Spis1* t = keyAdress;
        keyAdress->next->prev = keyAdress->prev;
        keyAdress->prev->next = keyAdress->next;
        delete t;
    }
    keyAdress = 0;
    


}

void addSpis1BeforeKeyInfo(Spis1*&keyAdress,Spis1*&begin2, Spis1*&end2, Spis1*& begin, Spis1*& end) {


    if (!keyAdress) {
        cout << "Key=0!!!" << endl;
        return;
    }


    if (keyAdress == begin) {
        end2->next = begin;
        begin->prev = end;
        begin = begin2;
    }
    else {
        

        end2->next = keyAdress;
        begin2->prev = keyAdress->prev;
        keyAdress->prev->next = begin2;
        keyAdress->prev = end2;



    }

}
void addSpis1AfterKeyInfo(Spis1*& keyAdress, Spis1*& begin2, Spis1*& end2, Spis1*& begin, Spis1*& end) {


    if (!keyAdress) {
        cout << "Key=0!!!" << endl;
        return;
    }


    if (keyAdress == end) {
       


        begin2->prev = end;
        end->next = begin2;
        end = end2;
    }
    else {


       

        begin2->prev = keyAdress;
        end2->next = keyAdress->next;
        keyAdress->next->prev = end2;
        keyAdress->next = begin2;

    }

}
void addAfterKeyInfo(Spis1* keyAdress, Spis1*& begin, Spis1*& end) {

    
        if (!keyAdress) {
            cout << "Key=0!!!" << endl;
            return;
        }
        

        if (keyAdress == end) {

            addSpis1END(begin, end);
        }
        else {
            Spis1* t = new Spis1;
            cout << "Введите информацию:" << endl;
            cin >> t->info;
            t->next = keyAdress->next;
            
            t->prev = keyAdress;
            keyAdress->next->prev = t;
            keyAdress->next = t;
        }

}
void addBeforeKeyInfo(Spis1* keyAdress, Spis1*& begin, Spis1*& end) {


    if (!keyAdress) {
        cout << "Key=0!!!" << endl;
        return;
    }


    if (keyAdress ==begin) {

        addSpis1START(begin, end);
    }
    else {
        Spis1* t = new Spis1;
        cout << "Введите информацию:" << endl;
        cin >> t->info;
        t->next = keyAdress;
        t->prev= keyAdress->prev;
        keyAdress->prev->next = t;
        keyAdress->prev = t;




     
    }

}




















//void sortirovkaSpis1(Spis1* begin, Spis1* end) {
//
//    if (!begin) {
//        cout << "Пусто" << endl;
//        return;
//    }
//    Spis1* t,*r1,*r2;
//    int c;
//    do {
//        c = 0;
//        for (t = begin; t->next; t = t-> next) {
//            if (t->info > t->next->info) {
//                r=
//            }
//
//        }
//
//
//
//
//    } while (c);
//
//}