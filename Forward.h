#pragma once

#include "Player.h"

using namespace std;

class Forward : public Player
{
public:
	/*Constructors & Distructors*/
	Forward();
	Forward(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize);
	Forward(const Forward& forward);
	virtual ~Forward();

	/*Operators*/
	Forward& operator=(const Forward& forward);
	bool operator<(Forward& forward);
	bool operator>(Forward& forward);

private:

};

ostream& operator<<(ostream& out, const Forward& forward);
istream& operator>>(istream& in, Forward& forward);

