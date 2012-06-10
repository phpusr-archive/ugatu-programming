//var4
//(Одномерный массив)Удалить элемент равный среднему арифметическому элементов массива
//(Двумерный массив)Добавить столбец в конец матрицы

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int* form_mas(int size);
int** form_mas_x2(int str, int stl);
void input_mas(int* mas, int size);
void input_mas_x2(int** mas, int str, int stl);
void print_mas(int* mas, int size);
void print_mas_x2(int** mas, int str, int stl);




int* del_mas(int* mas, int* size) {
    cout<<"Delete from array\n";        
    
    int* a = new int[*size];
    
    if (*size == 0) {
        cout<<"Formed array!";
        return a;
    }
    
    //Поиск среднеорифметического числа
    int sum = 0;
    for (int i=0;i<*size;i++) {
        sum += mas[i];
    }
    int avg = sum / *size;    
    cout<<"Average: "<<avg<<"\n";
    
    //Копирование числе не равных avg в новый массив
    int count = 0;
    for (int i=0;i<*size;i++) {
        if (mas[i] != avg) {            
            a[count] = mas[i];
            count++;
        } else {
            cout<<"Delete " << i+1 << " element\n";
        }
    }
    *size = count;
    
    return a;
}

int** add_mas(int** mas, int str, int* stl) {
    cout<<">>Add to array";
    
    int** a = new int*[str];
    
    for(int i=0;i<str;i++) {
        a[i] = new int[*stl + 1];
        for(int j=0;j<*stl;j++) {
            a[i][j] = mas[i][j];
        }
    }        
    
    for(int i=0;i<str;i++) {
        a[i][*stl] = 0;
    }
    
    *stl += 1;
    
    return a;    
}

int main(int argc, char *argv[]) {
    int k;
    int* mas;
    int** mas2;
    int SIZE = 10;
    int size=0, str=0, stl=0;
    do {
        cout<<"\n=======================\n";
        cout<<"1. Formed arrays\n";
        cout<<"2. Print array\n";
        cout<<"3. Print array x2\n";
        cout<<"4. Delete from array\n";
        cout<<"5. Add to array\n";
        cout<<"6. Exit\n";
        cout<<"=======================\n";        
        cin>>k;
        switch (k) {
            case 1:
                size = SIZE; 
                mas = form_mas(size);
                input_mas(mas,size);
                
                str = SIZE; stl = size;
                mas2 = form_mas_x2(str, stl);
                input_mas_x2(mas2, str, stl); 
                break;//выделение памяти и заполнение
            case 2: print_mas(mas, size); break;//печать
            case 3: print_mas_x2(mas2, str, stl); break;//печать
            case 4: mas = del_mas(mas, &size);break;//удаление
            case 5: mas2 = add_mas(mas2, str, &stl);break;//добавление
        }
    } while (k!=6);//выход

}

int* form_mas(int size) {
    cout<<">>Formed array\n";
    int* a = new int[size];    
    return a;
}

int** form_mas_x2(int str, int stl) {
    cout<<">>Formed array x2\n";
    int** a = new int*[str];    
    
    for(int i=0;i<str;i++) {
        a[i] = new int[stl];
    }
    return a;
}

void input_mas(int* mas, int size) {
    cout<<">>Input array\n";
    
    srand(time(0));
    for(int i=0;i<size;i++) {
        mas[i] = rand()%10;
    }
}

void input_mas_x2(int** mas, int str, int stl) {
    cout<<">>Input array x2\n";
    
    srand(time(0));
    for(int i=0;i<str;i++) {        
        for (int j=0;j<stl;j++){            
            mas[i][j] = rand()%100;
        }
    }
}

void print_mas(int* mas, int size) {
    cout<<">>Print array\n";
    
    for (int i=0;i<size;i++) {
        cout<<mas[i]<<", ";
    }
}

void print_mas_x2(int** mas, int str, int stl) {
    cout<<"Print array x2\n";
    
    for (int i=0;i<str;i++) {
        for (int j=0;j<stl;j++) {
            cout<<mas[i][j]<<", ";
        }
        cout<<"\n";
    }
}

