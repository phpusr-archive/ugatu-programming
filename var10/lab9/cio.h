#ifndef CIO_H_INCLUDED
#define CIO_H_INCLUDED
#include "lab9.h"

FILE* openFile(char* fileName, char* mode);
void putFile(char* fileName, Inf* list, int count);
void printFile(char* fileName);
void createAndPutFile(char* fileName, int count, char* name);
void deleteElements(char* fileName);
void insertElements(char* fileName);

#endif // CIO_H_INCLUDED
