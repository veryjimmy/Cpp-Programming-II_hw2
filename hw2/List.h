#ifndef LIST_H
#define LIST_H
#include "Box.h" 

class Package
{
public:
	Package(Box* pNewBox); //constructor
	Box* getBox() const; //retrieve the box pointer
	Package* getNext() const; //get next package address
	void setNext(Package* pPackage); //add package to end of list

private:
	Box* pBox; //pointer to the box
	Package* pNext; // pointer to the next package
};

class TruckLoad
{
public:
	TruckLoad(Box* pBox = 0, int count = 1);

	Box* getFirstBox(); //retrieve the first box
	Box* getNextBox(); //retrieve the next box
	void addBox(Box* pBox); //add a new box th the list

private:
	Package* pHead; //first in the list
	Package* pTail; //last in the list
	Package* pCurrent; //last retrieved from the list
};

#endif
