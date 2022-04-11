#include <iostream>
#include <string>
#include<conio.h>
using namespace std;
struct Tree {
    int info;
    string FIO;
    Tree* left, * right;

} *root;
Tree* List(int info,string FIO) {


    Tree* t = new Tree;

    t->info = info;
    t->FIO=FIO ;
    t->left = t->right = 0;
    return t;


}
void AddList(Tree*& root, int info, string FIO) {
    if (!root) {
        root = List(info,FIO);
        return;
    }

    Tree* t = root, * prev;
 
        

       
        while (t) {
            prev = t;
            if (info == t->info or FIO==t->FIO) {
                cout << "Элемент со значением " << info << " уже есть. Все элементы должны быть уникальными" << endl;
                

                break;
            }
            if (info < t->info) {
                t = t->left;
                t = List(info,FIO);
                prev->left = t;

            }
            if (info > t->info) {
                t = t->right;
                t = List(info,FIO);
                prev->right = t;

            }
        }

    



}///////////////?????????????????????....................???
void CreateList(Tree*&root,int n=1) {
    int info;
    string FIO;
    if (!root&&n!=0) {
        cout << "Введите значения ключа:" << endl;
        cin >> info;
        cout << "Введите фамилию:" << endl;
        cin >> FIO;
       root= List(info,FIO);
       n--;
    }
    if (n==0) {
        return;


    }

        Tree* t=root,*prev=t;
        bool check;
        for (int i = 0; i < n; i++) {
            t = root;
            check = true;
            cout << "Введите значения ключа:" << endl;
            cin >> info;
            cout << "Введите фамилию:" << endl;
            cin >> FIO;
            while (t) {
                prev = t;
                if (info == t->info) {
                    cout << "Элемент со значением " << info << " уже есть. Все элементы должны быть уникальными" << endl;
                    cout << "Введите другое значение элемента" << endl;
                    i--;
                    check= false;
                    break;
                }
                if (info < t->info) {
                    t = t->left;
                    

                }else 
                if (info > t->info) {
                    t = t->right;
                   

                }
            }
            if (check) {
                t = List(info, FIO);
                if (info < prev->info)

                    prev->left = t;

                else
                prev->right = t;
            }
        }
    


}
void DeletingList(Tree*& root, int info) {

    Tree* t=root,*prev=0,*del=root,*del_prev=0;
    while (del&&(del->info!=info)) {

        del_prev = del;
        if (del->info > info) {
            del = del->left;
        }
        else {
            del = del->right;
        }
        if (del == 0) {
            cout << "Ключ не найден" << endl;
            return;
        }

        if (del->right == 0) {
            t - del->left;

        }
        else if (del->left == 0) {
            t = del->right;
        }
        else {

            prev = del;
            t = del->left;
            while (t->right) {
                prev = t;
                t = t->right;

            }

        }
        if (prev == del) {

            t->right = del->right;
        }
        else {

            t->right = del->right;
            prev->right = t->left;
            t->left = prev;
        }
    }
        if (del == root) {
            root = t;
        }
        if (del->info < prev->info) {
            prev->left = t;
        }
        else prev->right = t;
        cout << " delete " << del->info << endl;
        delete del;
        return;
    }
void MyDeletingList(Tree*& root, int info) {
    Tree* t = root, * prev = 0, * del = root, * del_prev = 0;
    while (del && (del->info != info)) {
        del_prev = del;
        if (info < del->info) {
            del = del->left;
        }
        else del = del->right;





    }
    if (!del) {
        cout << "Такого элемента не сущетсвует" << endl;
        return;
    }


    if (del->right == 0) {
        t = del->left;

    }
    else if (del->left == 0) {
        t = del->right;
    }
    else {

        prev = del;
        t = del->left;
        while (t->right) {
            prev = t;
            t = t->right;


        }


        if (prev == del) {
            t->right = del->right;

        }
        else {
            t->right = del->right;
            prev->right = t->left;
            t->left = prev;

        }
    }
    if (del == root) {
        root = t;
    }
    else {

        if (del->info < del_prev->info) {
            del_prev->left = t;
        }
        else {
            del_prev->right = t;
        }
        cout << "Удаляемый эелемент = " << del->info << endl;
        delete del;
    }
}
void View(Tree* t, int level=0) {
    if (t) {
        View(t->right, level + 1);
        
        for (int i = 0; i < level; ++i)
            cout << "    ";
        cout << t->info <<t->FIO<< endl;
        View(t->left, level + 1);
        
    }
}
void maxLevel(Tree* t, int *level) {
    if (t) {

        maxLevel(t->right,  level + 1);
        
        for (int i = 0; i < *level; ++i)
            cout << "    ";
        cout << t->info << t->FIO << endl;
        maxLevel(t->left,level + 1);
    
    }


}
void ViewEND(Tree* t, int level = 0) {

    if (t) {
        View(t->right, level + 1);
        // Вывод узлов правого поддерева
        for (int i = 0; i < level; ++i)
            cout << "    ";
        cout << t->info << t->FIO << endl;
        View(t->left, level + 1);
        // Вывод узлов левого поддерева
    }


}
void Del_All(Tree* t) {
    if (t != NULL) {
        Del_All(t->left);
        Del_All(t->right);
        delete t;
    }
}
void kolList(Tree* t,int &kol) {
    
    if (t != NULL) {
        kol++;
        kolList(t->left,kol);
        kolList(t->right,kol);
    }
    
}
void VMassive(Tree* t, int& kol,int*array1,string* array2) {

    if (t != NULL) {
        kol++;
        array1[kol - 1] = t->info;
        array2[kol - 1] = t->FIO;
        VMassive(t->left, kol, array1, array2);
        VMassive(t->right, kol, array1, array2);
    }

}
Tree* minTree(Tree* root) {

    while (root) {

        root = root->left;

    }
    return root;

}
Tree* maxTree(Tree* root) {

    while (root) {

        root = root->right;

    }
    return root;

}
int minTreeLevel(Tree* root) {
    int level = 0;
    while (root) {
        level++;
        root = root->left;

    }
    return level;

}
int maxTreeLevel(Tree* root) {
    int level = 0;
    while (root) {
        level++;
        root = root->right;

    }
    return level;
}
 int PoickSrednlev(Tree* t, double razn,int check,int level) {
   
    PoickSrednlev(t->left, razn, check, level--);

    PoickSrednlev(t->right, razn, check, level--);
    return 1;
};
 void ObratnPrint(Tree *t)
{
    if (t){        


        ObratnPrint(t->left);

        ObratnPrint(t->right);

        cout << t->info << t->FIO << endl; }
    
}

 void PryamPrint(Tree* t)
 {
     if (t) {


         PryamPrint(t->left);

         PryamPrint(t->right);

         cout << t->info << t->FIO << endl;
     }

 }

 void maxLevel(Tree* t, int& maxlevel, int level = 0)
 {
     if (t == NULL)   // Базовый случай
     {
         return;
     }
     if (level > maxlevel) {
         maxlevel = level;
     }
     maxLevel(t->right, maxlevel, level + 1);   //рекурсивный вызов левого поддерева

     maxLevel(t->left, maxlevel, level + 1);  //рекурсивный вызов правого поддерева
     
 }
void SrednKluch(Tree* t,double &sum) {


    if (t) {

        
            sum+=double(t->info);
            SrednKluch(t->left, sum);

            SrednKluch(t->right, sum);
        

    }
}

void Make_Blns(Tree*& p, int n, int k, int* a,string * array)
{
    if (n == k) {
        p = NULL;
        return;
    }
    else {
        int m = (n + k) / 2;
        p = new Tree;
        p->info = a[m];
        p->FIO = array[m];
        Make_Blns(p->left, n, m, a, array);
        Make_Blns( p->right, m + 1, k, a, array);
    }
}
void PoiskSrednego(Tree* t, int maxlevel,  double sredn, Tree*& klutch,double &raznitca, int level = 1) {
    if (level < maxlevel) {
        if (fabs(t->info - sredn) < raznitca) {
            klutch = t;
            raznitca = fabs(klutch->info - sredn);

        }
        PoiskSrednego(t->left, maxlevel, sredn, klutch, raznitca, level + 1);
        PoiskSrednego(t->right, maxlevel, sredn, klutch, raznitca, level + 1);
    }
}
void sortArray(Tree*&t) {

    int i = 0, j = 0, minIndex, r, size = 0;
    kolList(t, size);
    int* array1 = new int[size];
    string* array2 = new string [size];
    
    string  r2;
    size = 0;
    VMassive( t,size,array1,array2);
    for (i; i < size; i++) {
        minIndex = i;
        for (j = i; j < size ; j++) {
            if (array1[j] < array1[minIndex]) {
                minIndex = j;

            }

        }
        r = array1[i];
        array1[i] = array1[minIndex];
        array1[minIndex] = r;

        r2 = array2[i];
        array2[i] = array2[minIndex];
        array2[minIndex] = r2;
    }
    for (i = 0; i < size; i++) {

        cout << array1[i] << "  ";
  }
    cout << endl;
    Del_All(t);
    t = 0;
    Make_Blns(t , 0, size, array1, array2);



    delete[]array1;
    delete[]array2;
}
void viewKeyList(Tree* t, int key) {

    while (t) {
        if (t->info == key) {
            cout << "key =" << t->info << endl;
            cout << "FIO =" << t->FIO << endl;
            return;
        }
        if (key < t->info) {

            t = t->left;

        }
        else t = t->right;

        
    }
    cout << "Ключ не найден" << endl;


}
//void viewKeyList(Tree* t, int key,int check) {
//    
//    if (t!=0&&check!=1) {
//        if (t->info == key) {
//            cout << "key =" << t->info << endl;
//            cout << "FIO =" << t->FIO << endl;
//            t=0;
//            return;
//        }
//        viewKeyList(t->left, key,check);
//
//        viewKeyList(t->right, key,check);
//
//    }
//
//
//
//}
void VozrastanitVivod(Tree* t) {
    int i = 0, j = 0, minIndex, r, size = 0;
    kolList(t, size);
    int* array1 = new int[size];
    string* array2 = new string[size];

    string  r2;
    size = 0;
    VMassive(t, size, array1, array2);
    for (i; i < size; i++) {
        minIndex = i;
        for (j = i; j < size; j++) {
            if (array1[j] < array1[minIndex]) {
                minIndex = j;

            }

        }
        r = array1[i];
        array1[i] = array1[minIndex];
        array1[minIndex] = r;

        r2 = array2[i];
        array2[i] = array2[minIndex];
        array2[minIndex] = r2;
    }
    for (i = 0; i < size; i++) {

        cout << array1[i] << "  " << array2[i] << endl;
    }
    cout << endl;
   
   


    delete[]array1;
    delete[]array2;
}
void poiskKlutch(Tree* t, int kl)
{
    bool flag = false;
    while (t) {
        if (kl < t->info) {
            t = t->left;
            continue;
        }
        if (kl > t->info) {
            t = t->right;
            continue;
        }
        if (kl == t->info) {

            cout << "По заданному ключу бфла найдена эта информация:\n" << t->FIO << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "Такого ключа найдено не было:\n"<<endl;
    }

}
void indiv(Tree* t) {


    int kol = 0;
    kolList(t, kol);
    double sum = 0;
    SrednKluch(root, sum);
    double sredn = sum / kol;
    
    int levelmin, levelmax;
    levelmin = minTreeLevel(t)-1;
    levelmax = maxTreeLevel(t)-1;

    double raznitca1 = 0;
    Tree* klutch1 = 0;

    if (levelmin > 1) {
        raznitca1 = fabs(t->left->info - sredn);
        klutch1 = t->left;
        PoiskSrednego(t->left, levelmin, sredn, klutch1, raznitca1);

    }
    double raznitca2 = 0;
    Tree* klutch2 = 0;
    if (levelmax > 1) {
        raznitca2 = fabs(t->right->info - sredn);
        klutch2 = t->right;
        PoiskSrednego(t->right, levelmax, sredn, klutch2, raznitca2);

    }
    double raznitca3 = 0;
    Tree* klutch3 = 0;
    if (levelmax && levelmin) {

        raznitca3 = fabs(t->info - sredn);
        klutch3 = t;

    }
    double RAZN;
    Tree* KLUTCH = 0;

    if ((klutch1==0 &&  klutch2==0 && klutch3==0)) {
        cout << "Нет таких ключей!" << endl;
    }
    else {
        if (klutch1 && klutch2 && klutch3) {

             (raznitca1 < raznitca2) ? (RAZN=raznitca1, KLUTCH=klutch1) : (RAZN = raznitca2, KLUTCH = klutch2);
            

           
            if (raznitca3 < RAZN) {
                KLUTCH = klutch3;
            }
        }
        else
            if (klutch1 && klutch2) {
                KLUTCH = (raznitca1 < raznitca2) ? klutch1 : klutch2;
            }
            else
                if (klutch1 && klutch3) {
                    KLUTCH = (raznitca1 < raznitca3) ? klutch1 : klutch3;
                }
                else
                    if (klutch2 && klutch3) {
                        \
                        KLUTCH = (raznitca2 < raznitca3) ? klutch2 : klutch3;
                    }
                    else
                        if (klutch1) {

                            KLUTCH = klutch1;
                        }
                        else
                            if (klutch2) {

                                KLUTCH = klutch2;
                            }
                            else
                                if (klutch3) {

                                    KLUTCH = klutch3;
                                }
        if (KLUTCH != 0) {
            cout << "Среднее значение:" << sredn << endl;
            cout << "KLUTCH " << KLUTCH->info << endl;
        }
        else cout << "Нет таких ключей!" << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");

    root = 0;
    char value;
    do {
        cout << "\t1.Создать новый список(старый удалится)\n\t2.Добавить элементы\n\t3.Просмтотреть дерево\n" <<
            "\t4.Найти информацию по ключу\n\t5.Удалить элемент по ключу\n\t6.Вывод на печать прямым обходом\n\t7.Вывод на печать обратным обходом" <<
            "\n\t8.Вывод в порядке возрастания\n\t9.Сбалансировать дерево\n\t0.Индивидуальное задание\n\tПробел - удалить все и завершить программу(default)\n\t";

        cout << "\tОжидание ввода ..." << endl;
        value = _getch();
        cout << value << endl;
        if (value != '1' && value != '2'&&root==0) {
            cout << "Дерево пустое" << endl;
            continue;
        }
        switch (value)
        {

        case '1':case'2': {
            if (value == '1') {
                Del_All(root);
                root = 0;
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
            CreateList(root, n);

            break;

        }
        case'3': {
            View(root);
            continue;

        }
        case'4': {
            cout << "Введите значение ключа:" << endl;
            int kl;
            cin >> kl;
            viewKeyList(root, kl);
           // poiskKlutch(root,  kl);
            continue;

        }
        case'5': {
            View(root);
            cout << "Введите значение ключа,который вы хотите удалить:" << endl;
            int kl;
            cin >> kl;
            MyDeletingList(root, kl);
            cout << "Резльтат после удаления:" << endl;
            View(root);
            continue;
        }
        case'6': {

            PryamPrint(root);
            continue;
        }
        case'7': {

            ObratnPrint(root);
            continue;
        }
        case'8': {
            VozrastanitVivod(root);
            continue;
        }
        case'9': {
            View(root);
            sortArray(root);
            cout << "Сбалансированное дерево" << endl;
            View(root);
            continue;

        }
        case'0': {
            View(root);
            indiv(root);
            continue;
        }
        default: {

            value = 0;
            Del_All(root);
            break;
            }
        }

    } while (value);

   
    
   
   
    
   

    

}
