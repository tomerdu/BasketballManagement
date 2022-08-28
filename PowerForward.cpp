#include <iostream>
#include <string>

#include "powerForward.h"



PowerForward::PowerForward()
	: m_blocksScoreRatio(0)
{
}

PowerForward::PowerForward(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	: Forward(name, shirtnum, height, age, shoeSize), m_blocksScoreRatio(0)
{
}

PowerForward::PowerForward(const PowerForward& power)
{
	*this = power;
}

PowerForward::~PowerForward()
{
}

PowerForward& PowerForward::operator=(const PowerForward& power)
{
	Player::operator=(power);
	m_blocksScoreRatio = power.m_blocksScoreRatio;
	return *this;
}

bool PowerForward::operator<(PowerForward& power)
{
	return Player::operator<(power);
}

bool PowerForward::operator>(PowerForward& power)
{
	return Player::operator>(power);
}

void PowerForward::setBlocksScoreRatio(const float ratio)
{
	m_blocksScoreRatio = ratio;
	checkBlocksScoreRatio();
}

float PowerForward::getBlocksScoreRatio() const
{
	return m_blocksScoreRatio;
}

void PowerForward::block()
{
	Player::block();
	updateBlocksScoreRatio();
}

void PowerForward::printMe() const
{
	Player::printMe();
	cout << "Blocks&ScoreRatio " << getBlocksScoreRatio() << endl;
	cout << endl;
}

void PowerForward::updateBlocksScoreRatio()
{
	if (m_score == 0)
		cout << "Score of " << m_name << " is 0, cannot divide by it." << endl;
	else
	{
		m_blocksScoreRatio = ((float)m_blocks / (float)m_score);
		checkBlocksScoreRatio();
	}
	
}

void PowerForward::checkBlocksScoreRatio()
{
	if (m_blocksScoreRatio == 0)
		cout << "the Ratio between blocks & score of " << m_name << " is 0" << endl;
	else if (m_blocksScoreRatio < 0.25)
		cout << "the Ratio between blocks & score of " << m_name << " is too small!" << endl;
}

void PowerForward::updateScore()
{
	Player::updateScore();
	updateBlocksScoreRatio();
}

ostream& operator<<(ostream& out, const PowerForward& power)
{
	power.printMe();
	return out;
}

istream& operator>>(istream& in, PowerForward& power)
{
	power.scanToMe();
	return in;
}
