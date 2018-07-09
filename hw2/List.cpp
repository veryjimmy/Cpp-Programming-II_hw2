#include "Box.h"
#include "List.h"

//建構Package
Package::Package(Box* pNewBox):pBox(pNewBox), pNext(0)
{
}
//retrieve the box pointer
Box* Package::getBox() const
{
	return pBox;
}
//獲取下一個 package 的 address
Package* Package::getNext() const
{
	return pNext;
}
//加入package到list的最後面
void Package::setNext(Package* pPackage)
{
	pNext = pPackage;
}
//////////////////////////////////////////////////
//建構TruckLoad
TruckLoad::TruckLoad(Box* pBox, int count)
{
	pHead = pTail = pCurrent = 0;
	if ((count>0) && (pBox!=0))
	for (int i = 0; i < count; i++)
		addBox(pBox + i);
}
//retrieve the first box
//列表中第一個package的address儲存在pHead中
//所以把地址存在pCurrent 再用getBox函數得到box的address
Box* TruckLoad::getFirstBox()
{
	pCurrent = pHead;
	return pCurrent->getBox();
}
//retrieve the next box
Box* TruckLoad::getNextBox()
{
	if (pCurrent)
		pCurrent = pCurrent->getNext();
	else
		pCurrent = pHead;
	return pCurrent ? pCurrent->getBox() : 0;
}
//加入box到list
void TruckLoad::addBox(Box* pBox)
{
	Package* pPackage = new Package(pBox);
	if (pHead)
		pTail->setNext(pPackage);
	else
		pHead = pPackage;
	pTail = pPackage;
}