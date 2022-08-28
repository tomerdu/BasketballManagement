#include <iostream>
#include <string>

#include "SmallForward.h"



SmallForward::SmallForward()
{
}

SmallForward::SmallForward(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	: Forward(name, shirtnum, 0, age, shoeSize)
{
	setHeight(height);
}

SmallForward::SmallForward(const SmallForward& small)
{
	*this = small;
}

SmallForward::~SmallForward()
{
}

SmallForward& SmallForward::operator=(const SmallForward& small)
{
	Player::operator=(small);
	return *this;
}

bool SmallForward::operator<(SmallForward& small)
{
	return Player::operator<(small);
}

bool SmallForward::operator>(SmallForward& small)
{
	return Player::operator>(small);
}

void SmallForward::setHeight(const float& height)
{
	Player::setHeight(height);
	checkHeight();
}

void SmallForward::checkHeight()
{
	if (m_height > 1.95)
		cout << m_name << " is not at the required height" << endl;
}

ostream& operator<<(ostream& out, const SmallForward& small)
{
	small.printMe();
	out << endl;
	return cout;
}

istream& operator>>(istream& in, SmallForward& small)
{
	small.scanToMe();
	return in;
}
