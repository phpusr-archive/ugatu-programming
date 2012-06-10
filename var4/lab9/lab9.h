#ifndef LAB9_H_INCLUDED
#define LAB9_H_INCLUDED

struct People {
    char fio[100];
    char adres[100];
    char phone[100];
    int age;
};

void printStructure(int num, People* struc);
People* getPeopleList(int count, char* name);

#endif // LAB9_H_INCLUDED
