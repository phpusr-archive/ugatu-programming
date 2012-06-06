#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED


struct Dub {
    char* data;
    Dub* prev;
    Dub* next;
};

Dub* createListDouble(int n);
void printListDouble(Dub* beg);
Dub* createDub(char* data);
Dub* processingListDouble(Dub* beg, Dub* dub);
Dub* delListDouble(Dub* beg);

#endif // DOUBLELINKEDLIST_H_INCLUDED
