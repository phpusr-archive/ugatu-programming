#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

struct Hot {
    int data;
    Hot* next;
};

Hot* createList(int n);
void printList(Hot* beg);
Hot* processingList(Hot* beg);
Hot* createHot();
Hot* addHot(Hot* beg, Hot* hot, int pos);
Hot* delList(Hot* beg);

#endif // SINGLYLINKEDLIST_H_INCLUDED
