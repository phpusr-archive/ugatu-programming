//var10
//(Одномерный массив)Удалить все элементы с нечетными индексами
//(Двумерный массив)Добавить К столбцов в начало матрицы

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

int* form_mas(int size);
int** form_mas_x2(int str, int stl);
void input_mas(int* mas, int size);
void input_mas_x2(int** mas, int str, int stl);
void print_mas(int* mas, int size);
void print_mas_x2(int** mas, int str, int stl);
int* deleteEl(int* mas, int* size);
int** addStl(int** mas, int str, int* stl, int k);

/** Программа запускается отсюда */
int main(int argc, char *argv[]) {

    cout << "Var 10 Lab 5" << endl;

    int k;
    int* mas;
    int** mas2;
    const int SIZE = 10;
    int size=0, str=0, stl=0;
    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Udelenie elementov"<<endl;
        cout<<"2. Print array"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            case 1: //Выделение памяти и заполнение массива, удаление всех элементов с нечетными индексами
                size = SIZE;
                mas = form_mas(size);
                input_mas(mas,size);
                print_mas(mas, size);

                deleteEl(mas, &size);
                print_mas(mas, size);

                break;
            case 2: //Выделение памяти и заполнение массива, добавление К столбцов в начало матрицы
                int k;
                cout<<"Enter k: ";
                cin>>k;

                str = SIZE; stl = SIZE;
                mas2 = form_mas_x2(str, stl + k);
                input_mas_x2(mas2, str, stl);
                print_mas_x2(mas2, str, stl);


                mas2 = addStl(mas2, str, &stl, k);
                print_mas_x2(mas2, str, stl);
                break;
        }
    } while (k!=6);//выход

}

/** Удалить все элементы с нечетными индексами */
int* deleteEl(int* mas, int* size) {
    cout<<">>Udalenit nechetnih elementov"<<endl;

    int count = round((float)*size / 2);

    for(int i=0; i<count; i++) {
        mas[i] = mas[i*2+1];
    }

    *size = count;
    return mas;
}

/** Удаление строки по ее номеру в двумерном массиве */
int** addStl(int** mas, int str, int* stl, int k) {
    cout<<">>Dobavlenie K stolbcov v nachalo matrix"<<endl;

    if (str == 0 || stl == 0) {
        cout<<">>Array is empty!"<<endl;
        return mas;
    }

    *stl += k;

    for(int i=0; i<str; i++) {

        for(int j=*stl-1; j>=0; j--) {
            mas[i][j] = mas[i][j-k];
        }

        for(int j=0; j<k; j++) {
            mas[i][j] = j+1;
        }
    }

    return mas;
}

/** Формирование одномерного массива */
int* form_mas(int size) {
    cout<<">>Formed array\n";
    int* a = new int[size];
    return a;
}

/** Формирование двумерного массива */
int** form_mas_x2(int str, int stl) {
    cout<<">>Formed array x2\n";
    int** a = new int*[str];

    for(int i=0;i<str;i++) {
        a[i] = new int[stl];
    }
    return a;
}

/** Формирование данных для одномерного массива */
void input_mas(int* mas, int size) {
    cout<<">>Input array\n";

    srand(time(0));
    for(int i=0;i<size;i++) {
        mas[i] = rand()%10;
    }
}

/** Формирование двумерного массива */
void input_mas_x2(int** mas, int str, int stl) {
    cout<<">>Input array x2\n";

    srand(time(0));
    for(int i=0;i<str;i++) {
        for (int j=0;j<stl;j++){
            mas[i][j] = rand() % 100;
        }
    }
}

/** Распечатка одномерного массива */
void print_mas(int* mas, int size) {
    cout<<">>Print array\n";

    for (int i=0;i<size;i++) {
        cout<<mas[i]<<", ";
    }
    cout<<endl;
}

/** Распечатка двумерного массива */
void print_mas_x2(int** mas, int str, int stl) {
    cout<<">>Print array x2\n";

    for (int i=0;i<str;i++) {
        for (int j=0;j<stl;j++) {
            cout<<mas[i][j]<<", ";
        }
        cout<<"\n";
    }
}

