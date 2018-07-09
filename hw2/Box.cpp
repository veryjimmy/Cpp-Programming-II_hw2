#include <iostream>
#include <string>
#include "Box.h"

using namespace std;

Box::Box(double aLength, double aWidth, double aHeight)
{
	length = aLength > 0.0 ? aLength : 1.0;
	breadth = aWidth > 0.0 ? aWidth : 1.0;
	height = aHeight > 0.0 ? aHeight : 1.0;
}

//計算box體積
double Box::volume()
{
	return length*breadth*height;
}


double Box::getLength()
{
	return length;
}
double Box::getBreadth()
{
	return breadth;
}
double Box::getHeight()
{
	return height;
}

//如果vol1大於vol2 回傳1
//如果vol1等於vol2 回傳0
//如果vol1等於vol2 回傳-1
int Box::compareVolume(Box& otherBox)
{
	double vol1 = volume();
	double vol2 = otherBox.volume();
	return vol1 > vol2 ? 1 : (vol1 < vol2 ? -1 : 0);
}