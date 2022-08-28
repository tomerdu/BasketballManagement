#include <iostream>
#include <string>

#include "ShootingGuard.h"



ShootingGuard::ShootingGuard()
	: m_shootThrowRatio(0)
{
}

ShootingGuard::ShootingGuard(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	: Guard(name, shirtnum, height, age, shoeSize), m_shootThrowRatio(0)
{
}

ShootingGuard::ShootingGuard(const ShootingGuard& Shooting)
{
	*this = Shooting;
}

ShootingGuard::~ShootingGuard()
{
}

ShootingGuard& ShootingGuard::operator=(const ShootingGuard& Shooting)
{
	Player::operator=(Shooting);
	updateShootThrowRatio();
	return *this;
}

bool ShootingGuard::operator<(ShootingGuard& Shooting)
{
	return Player::operator<(Shooting);
}

bool ShootingGuard::operator>(ShootingGuard& Shooting)
{
	return Player::operator>(Shooting);
}

void ShootingGuard::setShootThrowRatio()
{
	updateShootThrowRatio();
}

float ShootingGuard::getShootThrowRatio() const
{
	return m_shootThrowRatio;
}

void ShootingGuard::shoot(const PointsEnum& points, const bool& statusSuccess)
{
	Player::shoot(points, statusSuccess);
	updateShootThrowRatio();
}

void ShootingGuard::printMe() const
{
	Player::printMe();
	cout << "Shoot&ThrowRatio. " << getShootThrowRatio() << endl;
	cout << endl;
}

void ShootingGuard::updateShootThrowRatio()
{
	if (m_2PointThrow + m_3PointThrow == 0)
		m_shootThrowRatio = 0;
	else
	{
		m_shootThrowRatio = ((float)(m_2PointShoot + m_3PointShoot) / (float)(m_2PointThrow + m_3PointThrow));
		checkShootThrowRatio();
	}
}

void ShootingGuard::checkShootThrowRatio() const
{
	if (m_shootThrowRatio == 0)
		cout << "The Ratio between shoots & throws of " << m_name << " is 0" << endl;
	else if (m_shootThrowRatio < 0.30)
		cout << "The Ratio between shoots & throws of " << m_name << " is too small!" << endl;
}

ostream& operator<<(ostream& out, const ShootingGuard& Shooting)
{
	Shooting.printMe();
	return out;
}

istream& operator>>(istream& in, ShootingGuard& point)
{
	point.scanToMe();
	point.setShootThrowRatio();
	return in;
}
