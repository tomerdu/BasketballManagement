#pragma once

#include "forward.h"

class PowerForward : public Forward
{
public:
	/*Constructors & Distructors*/
	PowerForward();
	PowerForward(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize);
	PowerForward(const PowerForward& power);
	~PowerForward();
	
	/*Operators*/
	PowerForward& operator=(const PowerForward& power);
	bool operator<(PowerForward& power);
	bool operator>(PowerForward& power);

	/*Setters*/
	void setBlocksScoreRatio(const float ratio);
	
	/*Getters*/
	float getBlocksScoreRatio() const;

	/*Methods*/
	void block();
	void printMe() const;

private:
	/*Members*/
	float m_blocksScoreRatio;
	
	/*Methods*/
	void updateBlocksScoreRatio();
	void checkBlocksScoreRatio();
	void updateScore();
};

ostream& operator<<(ostream& out, const PowerForward& power);
istream& operator>>(istream& in, PowerForward& power);

