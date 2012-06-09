#ifndef LAB9_H_INCLUDED
#define LAB9_H_INCLUDED

struct Inf {
    char media[100];
    float volume;
    char name[100];
    char author[100];
};

void printStructure(int num, Inf* struc);
Inf* getInfList(int count, char* name);

#endif // LAB9_H_INCLUDED
