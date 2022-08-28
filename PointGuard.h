#pragma once

#include "Guard.h"

class PointGuard : public Guard
{
public:
	/*Constructors & Distructors*/
	PointGuard();
	PointGuard(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize);
	PointGuard(const PointGuard& point);
	~PointGuard();

	/*Operators*/
	PointGuard& operator=(const PointGuard& point);
	bool operator<(PointGuard& point);
	bool operator>(PointGuard& point);

	/*Setters*/
	void setAssistsScoreRatio(const float ratio);

	/*Getters*/
	float getAssistsScoreRatio() const;

	/*Methods*/
	void assist();
	void printMe() const;

private:
	/*Members*/
	float m_assistsScoreRatio;

	/*Methods*/
	void updateAssistsScoreRatio();
	void checkAssistScoreRatio() const;
	void updateScore();
};

ostream& operator<<(ostream& out, const PointGuard& point);
istream& operator>>(istream& in, PointGuard& point);

