#ifndef WOOD_H_INCLUDED
#define WOOD_H_INCLUDED


struct Wood {
    int data;
    Wood* left;
    Wood* right;
};

Wood* createIdealWood(int count);
void printWood(Wood* wood);
void processingWood(Wood* wood);
Wood* convertIdealWoodToSearchWood(Wood* wood);

#endif // WOOD_H_INCLUDED
