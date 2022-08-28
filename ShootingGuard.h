#pragma once

#include "Guard.h"

class ShootingGuard : public Guard
{
public:
	/*Constructors & Distructors*/
	ShootingGuard();
	ShootingGuard(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize);
	ShootingGuard(const ShootingGuard& point);
	~ShootingGuard();

	/*Operators*/
	ShootingGuard& operator=(const ShootingGuard& point);
	bool operator<(ShootingGuard& point);
	bool operator>(ShootingGuard& point);

	/*Setters*/
	void setShootThrowRatio();

	/*Getters*/
	float getShootThrowRatio() const;

	/*Methods*/
	void shoot(const PointsEnum& points, const bool& statusSuccess);
	void printMe() const;

private:
	/*Members*/
	float m_shootThrowRatio;

	/*Methods*/
	void updateShootThrowRatio();
	void checkShootThrowRatio() const;
};

ostream& operator<<(ostream& out, const ShootingGuard& point);
istream& operator>>(istream& in, ShootingGuard& point);

