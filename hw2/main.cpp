#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.h"
#include "List.h"

using namespace std;

//�ͦ�1��100���H�����
inline int random(int size)
{
	return 1 + static_cast<int>((size*static_cast<long>(rand())) / (RAND_MAX + 1));
}

Box* maxBox(TruckLoad& Load)
{
	Box* pBox = Load.getFirstBox();
	Box* pNextBox;
	while (pNextBox = Load.getNextBox())
	if (pBox->compareVolume(*pNextBox) < 0)
		pBox = pNextBox;
	return pBox;
}

int main()
{
	const int limit = 100;
	srand((unsigned)time(0));

	//�ϥ�TruckLoad�гy��list
	TruckLoad load1;

	//�bload1�K�[10��box
	for (int i = 0; i < 10; i++)
		load1.addBox(new Box(random(limit), random(limit), random(limit)));
	
	//��X��n�̤j��box
	Box* pBox = maxBox(load1);
	cout << "The largest box in the first list is " << pBox->getLength() << "*" 
		<< pBox->getBreadth() << "*" << pBox->getHeight() << endl;

	const int boxCount = 20;
	Box box2[boxCount];
	for (int i = 0; i < boxCount; i++)
		box2[i] = Box(random(limit), random(limit), random(limit));
	TruckLoad load2(box2, boxCount);
	pBox = maxBox(load2);
	cout << "The largest box in the second list is " << pBox->getLength() << "*" << pBox->getBreadth() << "*" << pBox->getHeight() << endl;

	system("pause");
	return 0;
}

