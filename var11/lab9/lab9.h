#ifndef LAB9_H_INCLUDED
#define LAB9_H_INCLUDED

struct DVD {
    char name[100];
    char director[100];
    float duration;
    float price;
};

void printStructure(int num, DVD* struc);
DVD* getDVDList(int count, char* name);

#endif // LAB9_H_INCLUDED
