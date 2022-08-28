#include <iostream>
#include <string>
#include <cstring>

#include "Player.h"

Player::Player() 
	: m_name(""), m_shirtNum(0), m_height(0), m_age(0), m_shoeSize(0),
	m_blocks(0), m_assists(0), m_fouls(0), m_2PointThrow(0), m_2PointShoot(0), m_3PointThrow(0),
	m_3PointShoot(0), m_score(0)
{
}

Player::Player(const string& name, const int& shirtnum, const float& height, const int& age, const int& shoeSize)
	:	m_blocks(0), m_assists(0), m_fouls(0), m_2PointThrow(0), m_2PointShoot(0), 
	m_3PointThrow(0), m_3PointShoot(0), m_score(0) 
{
	setName(name);
	setShirtNum(shirtnum);
	setHeight(height);
	setAge(age);
	setShoeSize(shoeSize);
}

Player::Player(const Player& player)
{
	*this = player;
}

Player::~Player()
{
}

Player& Player::operator=(const Player& player)
{
	if (this != &player)
	{
		m_name = player.m_name;
		m_shirtNum = player.m_shirtNum;
		m_height = player.m_height;
		m_age = player.m_age;
		m_shoeSize = player.m_shoeSize;

		m_blocks = player.m_blocks;
		m_assists = player.m_assists;
		m_fouls = player.m_fouls;
		m_2PointThrow = player.m_2PointThrow;
		m_2PointShoot = player.m_2PointShoot;
		m_3PointThrow = player.m_3PointThrow;
		m_3PointShoot = player.m_3PointShoot;
		m_score = player.m_score;
	}

	return *this;
}

bool Player::operator<(const Player& player)
{
	if (scoreAssistsRatio() < player.scoreAssistsRatio())
		return true;

	return false;
}

bool Player::operator>(const Player& player)
{
	if (scoreAssistsRatio() > player.scoreAssistsRatio())
		return true;

	return false;
}

/*Setters*/
void Player::setName(const string& name)
{
	if (!name.empty())
		m_name = name;
	else
		cout << "No name sent" << endl;
		
	return;
}

void Player::setShirtNum(const int& num)
{
	if (num >= 0)
		m_shirtNum = num;
	else
	{
		cout << "Unvalid number was sent, shirt number became 0" << endl;
		m_shirtNum = 0;
	}
		
	return;
}

void Player::setHeight(const float& height)
{
	if (height >= 0)
		m_height = height;
	else
	{
		cout << "Unvalid height was sent, height became 0;" << endl;
		m_height = 0;
	}
	
	return;
}

void Player::setAge(const int& age)
{
	if (age < 15)
	{
		cout << "The age of " << m_name <<  " is too small for the league, his age beacme 0" << endl;
		m_age = 0;
	}
	else if (age >= 40)
	{
		cout << "The age of " << m_name << " is too big for the league, his age beacme 0" << endl;
		m_age = 0;
	}
	else
		m_age = age;
	
	return;
}

void Player::setShoeSize(const int& size)
{
	if (size >= 0)
		m_shoeSize = size;
	else
	{
		cout << "Unvalid shoes size was sent, shoe size bacame 0" << endl;
		m_shoeSize = 0;
	}
}

void Player::setBlockNum(const int& blocks)
{
	if (blocks >= 0)
		m_blocks = blocks;
	else
	{
		cout << "Unvalid number was sent, number of blocks became 0" << endl;
		m_blocks = 0;
	}

	return;
}

void Player::setAssistNum(const int& assists)
{
	if (assists >= 0)
		m_assists = assists;
	else
	{
		cout << "Unvalid number was sent, number of assists became 0" << endl;
		m_assists = 0;
	}

	return;
}

void Player::setFoulsNum(const int& fouls)
{
	if (fouls >= 0 && fouls <= 5)
		m_fouls = fouls;
	else
	{
		cout << "Unvalid number was sent, number of fouls became 0" << endl;
		m_fouls = 0;
	}

	return;
}

void Player::set2PointThrows(const int& throws)
{
	m_2PointThrow = throws;
	if (throws >= 0)
		m_2PointThrow = throws;
	else
	{
		cout << "Unvalid number was sent, number of throws became 0" << endl;
		m_2PointThrow = 0;
	}

	return;
}

void Player::set3PointThrows(const int& throws)
{
	if (throws >= 0)
		m_3PointThrow = throws;
	else
	{
		cout << "Unvalid number was sent, number of throws became 0" << endl;
		m_3PointThrow = 0;
	}

	return;
}

void Player::set2PointShoots(const int& shoots)
{
	if (shoots < 0)
	{
		cout << "Negative number was sent, number of shoots became 0" << endl;
		m_2PointShoot = 0;
	}
	else if (shoots > m_2PointThrow)
	{
		cout << "Number of shoots cant be bigger than number of throws, number of shoots became 0 " << endl;
		m_2PointShoot = 0;
	}
	else
		m_2PointShoot = shoots;

	return;
}

void Player::set3PointShoots(const int& shoots)
{
	if (shoots < 0)
	{
		cout << "Negative number was sent, number of shoots became 0" << endl;
		m_3PointShoot = 0;
	}
	else if (shoots > m_3PointThrow)
	{
		cout << "Number of shoots cant be bigger than number of throws, number of shoots became 0 " << endl;
		m_3PointShoot = 0;
	}
	else
		m_3PointShoot = shoots;
	return;
}

/*Getters*/
string Player::getName() const
{
	return m_name;
}

int Player::getShirtNum() const
{
	return m_shirtNum;
}

float Player::getHeight() const
{
	return m_height;
}

int Player::getAge() const
{
	return m_age;
}

int Player::getShoeSize() const
{
	return m_shoeSize;
}

int Player::getBlockNum() const
{
	return m_blocks;
}

int Player::getAssistNum() const
{
	return m_assists;
}

int Player::getFoulsNum() const
{
	return m_fouls;
}

int Player::get2PointThrows() const
{
	return m_2PointThrow;
}

int Player::get3PointThrows() const
{
	return m_3PointThrow;
}

int Player::get2PointShoots() const
{
	return m_2PointShoot;
}

int Player::get3PointShoots() const
{
	return m_3PointShoot;
}

int Player::getScore() const
{
	return m_score;
}

/*Methods*/
void Player::foul()
{
	m_fouls++;
	if (m_fouls >= 5)
	{
		cout << m_name <<" reached five fouls - he is out!" << endl;
		cout << m_name <<" number of fouls has been reset" << endl << endl;
		m_fouls = 0;
	}
}

void Player::shoot(const PointsEnum& points,const bool& statusSuccess)
{
	if (PointsEnum::points2 == points)
	{
		m_2PointThrow++;
		if (statusSuccess)
		{
			m_2PointShoot++;
			updateScore();
		}
	}
	else if (PointsEnum::points3 == points)
	{
		m_3PointThrow++;
		if (statusSuccess)
		{
			m_3PointShoot++;
			updateScore();
		}
	}
}

void Player::assist()
{
	m_assists++;
	if (m_assists !=0 && (m_assists % 10) == 0)
		cout << "Good job, " << m_name << " reached " << m_assists << " assists!" << endl;

	//ישנם שחקנים התלויים בהמשך המתודה.
}

void Player::block()
{
	m_blocks++;
	if (m_blocks != 0 && (m_blocks % 10) == 0)
		cout << "Good job, " << m_name << " reached " << m_blocks << " blocks!" << endl;
}

void Player::printMe() const
{
	cout << "Player Details: " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << getName() << ", " << getAge() << endl;
	cout << "Height........... " << getHeight() << endl;
	cout << "Shirt number..... " << getShirtNum() << endl;
	cout << "Shoe size........ " << getShoeSize() << endl;
	cout << endl;
	cout << "Player stats:" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Fouls............ " << getFoulsNum() << endl;
	cout << "Blocks........... " << getBlockNum() << endl;
	cout << "Assists.......... " << getAssistNum() << endl;
	cout << "2throws.......... " << get2PointThrows() << endl;
	cout << "3throws.......... " << get3PointThrows() << endl;
	cout << "2Shoots.......... " << get2PointShoots() << endl;
	cout << "3Shoots.......... " << get3PointShoots() << endl;
	cout << "Score............ " << getScore() << endl;
}

void Player::scanToMe()
{
	string tmpName;
	int tmpNum;
	float tmpFloat;
	
	cout << "Enter name: ";
	fflush(stdin);
	cin >> tmpName;
	cout << endl;
	setName(tmpName);

	cout << "Enter shirt Number: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	setShirtNum(tmpNum);
	
	cout << "Enter height: ";
	fflush(stdin);
	cin >> tmpFloat;
	cout << endl;
	setHeight(tmpFloat);

	cout << "Enter age: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	setAge(tmpNum);

	cout << "Enter shoes size: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	setShoeSize(tmpNum);

	cout << "Enter number of blocks: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	setBlockNum(tmpNum);

	cout << "Enter number of assists: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	setAssistNum(tmpNum);

	cout << "Enter number of fouls: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	setFoulsNum(tmpNum);

	cout << "Enter number of 2 points throws: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	set2PointThrows(tmpNum);

	cout << "Enter number of 2 points shoots: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	set2PointShoots(tmpNum);

	cout << "Enter number of 3 points throws: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	set3PointThrows(tmpNum);

	cout << "Enter number of 3 points shoots: ";
	fflush(stdin);
	cin >> tmpNum;
	cout << endl;
	set3PointShoots(tmpNum);

	cout << "Updating score of " << m_name << endl;
	updateScore();

}

float Player::scoreAssistsRatio() const
{
	if (m_score == 0)
		cout << "Score of " << m_name << " is 0, cannot divide by it." << endl;
	else
		return ((float)m_assists / (float)m_score);

	return 0;
}

void Player::updateScore()
{
	m_score = m_2PointShoot * 2 + m_3PointShoot * 3;
}

ostream& operator<<(ostream& out, const Player& player)
{
	player.printMe();
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Player& player)
{
	player.scanToMe();
	return in;
}
