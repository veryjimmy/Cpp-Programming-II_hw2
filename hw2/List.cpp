#include "Box.h"
#include "List.h"

//�غcPackage
Package::Package(Box* pNewBox):pBox(pNewBox), pNext(0)
{
}
//retrieve the box pointer
Box* Package::getBox() const
{
	return pBox;
}
//����U�@�� package �� address
Package* Package::getNext() const
{
	return pNext;
}
//�[�Jpackage��list���̫᭱
void Package::setNext(Package* pPackage)
{
	pNext = pPackage;
}
//////////////////////////////////////////////////
//�غcTruckLoad
TruckLoad::TruckLoad(Box* pBox, int count)
{
	pHead = pTail = pCurrent = 0;
	if ((count>0) && (pBox!=0))
	for (int i = 0; i < count; i++)
		addBox(pBox + i);
}
//retrieve the first box
//�C���Ĥ@��package��address�x�s�bpHead��
//�ҥH��a�}�s�bpCurrent �A��getBox��Ʊo��box��address
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
//�[�Jbox��list
void TruckLoad::addBox(Box* pBox)
{
	Package* pPackage = new Package(pBox);
	if (pHead)
		pTail->setNext(pPackage);
	else
		pHead = pPackage;
	pTail = pPackage;
}