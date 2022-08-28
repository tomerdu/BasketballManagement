#include <iostream>
#include <string>
#include "Guard.h"

Guard::Guard()
{
}

Guard::Guard(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	: Player(name, shirtnum, height, age, shoeSize)
{
}

Guard::Guard(const Guard& guard)
	: Player(guard)
{
}

Guard::~Guard()
{
}

Guard& Guard::operator=(const Guard& guard)
{
	Player::operator=(guard);
	return *this;
}

bool Guard::operator<(Guard& guard)
{
	return Player::operator<(guard);
}

bool Guard::operator>(Guard& guard)
{
	return Player::operator>(guard);
}
