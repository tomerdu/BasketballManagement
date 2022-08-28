#include <iostream>
#include <string>

#include "PointGuard.h"



PointGuard::PointGuard()
	: m_assistsScoreRatio(0)
{
}

PointGuard::PointGuard(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	: Guard(name, shirtnum, height, age, shoeSize), m_assistsScoreRatio(0)
{
}

PointGuard::PointGuard(const PointGuard& point)
{
	*this = point;
}

PointGuard::~PointGuard()
{
}

PointGuard& PointGuard::operator=(const PointGuard& point)
{
	Player::operator=(point);
	m_assistsScoreRatio = point.m_assistsScoreRatio;
	return *this;
}

bool PointGuard::operator<(PointGuard& point)
{
	return Player::operator<(point);
}

bool PointGuard::operator>(PointGuard& point)
{
	return Player::operator>(point);
}

void PointGuard::setAssistsScoreRatio(const float ratio)
{
	m_assistsScoreRatio = ratio;
	checkAssistScoreRatio();
}

float PointGuard::getAssistsScoreRatio() const
{
	return m_assistsScoreRatio;
}

void PointGuard::assist()
{
	Player::assist();
	updateAssistsScoreRatio();
}

void PointGuard::printMe() const
{
	Player::printMe();
	cout << "AssistsScoreRatio " << getAssistsScoreRatio() << endl;
	cout << endl;
}

void PointGuard::updateAssistsScoreRatio()
{
	if (m_score == 0)
		cout << "Score of " << m_name << " is 0, cannot divide by it." << endl;
	else
	{
		m_assistsScoreRatio = ((float)m_assists / (float)m_score);
		checkAssistScoreRatio();
	}
}

void PointGuard::checkAssistScoreRatio() const
{
	if (m_assistsScoreRatio == 0)
		cout << "The Ratio between Assists & score of " << m_name << " is 0" << endl;
	else if (m_assistsScoreRatio < 0.30)
		cout << "The Ratio between Assists & score of " << m_name << " is too small!" << endl;
	else
		cout << "The new Assists & Score ratio of " << m_name << " is: " << m_assistsScoreRatio << endl;
}

void PointGuard::updateScore()
{
	Player::updateScore();
	updateAssistsScoreRatio();
}

ostream& operator<<(ostream& out, const PointGuard& point)
{
	point.printMe();
	return out;
}

istream& operator>>(istream& in, PointGuard& point)
{
	point.scanToMe();
	return in;
}
