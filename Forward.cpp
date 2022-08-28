#include <iostream>
#include <string>

#include "Player.h"
#include "Forward.h"

using namespace std;

Forward::Forward()
{
}

Forward::Forward(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	: Player(name, shirtnum, height, age, shoeSize)
{
}

Forward::Forward(const Forward& forward)
	: Player(forward)
{
}

Forward::~Forward()
{
}

Forward& Forward::operator=(const Forward& forward)
{
	Player::operator=(forward);
	return *this;
}

bool Forward::operator<(Forward& forward)
{
	return Player::operator<(forward);
}

bool Forward::operator>(Forward& forward)
{
	return Player::operator>(forward);
}

ostream& operator<<(ostream& out, const Forward& forward)
{
	forward.printMe();
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Forward& forward)
{
	forward.scanToMe();
	return in;
}
