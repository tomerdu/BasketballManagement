#pragma once

#include "Player.h"

using namespace std;

class Guard : public Player
{
public:
	/*Constructors & Distructors*/
	Guard();
	Guard(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize);
	Guard(const Guard& guard);
	virtual ~Guard();

	/*Operators*/
	Guard& operator=(const Guard& guard);
	bool operator<(Guard& guard);
	bool operator>(Guard& guard);

private:

};

