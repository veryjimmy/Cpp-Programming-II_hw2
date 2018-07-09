#ifndef BOX_H
#define BOX_H

class Box
{
public:
	Box(double lengthValue = 1.0, double breadthValue = 1.0, double heightValue = 1.0);
	double volume();
	int compareVolume(Box& otherBox);
	double getLength();
	double getBreadth();
	double getHeight();

private:
	double length;
	double breadth;
	double height;
};
#endif
