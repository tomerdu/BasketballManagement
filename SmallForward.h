#pragma once

#include "forward.h"

class SmallForward : public Forward
{
public:
	/*Constructors & Distructors*/
	SmallForward();
	SmallForward(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize);
	SmallForward(const SmallForward& small);
	~SmallForward();

	/*Operators*/
	SmallForward& operator=(const SmallForward& small);
	bool operator<(SmallForward& small);
	bool operator>(SmallForward& small);

	/*Setters*/
	void setHeight(const float& height);
	

	

private:
	/*Methods*/
	void checkHeight();
};

ostream& operator<<(ostream& out, const SmallForward& small);
istream& operator>>(istream& in, SmallForward& small);

