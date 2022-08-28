#pragma once
#include <iostream>
#include <string>

using namespace std;

enum class PointsEnum	// for the Shoot function.
{
	points2,
	points3

};

class Player
{
public:
	/*Constructors & Distructors*/
	Player();
	Player(const string& name, const int& shirtnum, const float& height,const int& age, const int& shoeSize);
	Player(const Player& player);
	virtual ~Player();
	
	/*Operators*/
	Player& operator=(const Player& player);
	bool operator<(const Player& player);
	bool operator>(const Player& player);

	/*Setters*/
	void setName(const string& name);
	void setShirtNum(const int& num);
	virtual void setHeight(const float& height);
	void setAge(const int& age);
	void setShoeSize(const int& size);
	void setBlockNum(const int& blocks);
	void setAssistNum(const int& assists);
	void setFoulsNum(const int& fouls);
	void set2PointThrows(const int& throws);
	void set3PointThrows(const int& throws);
	void set2PointShoots(const int& shoots);
	void set3PointShoots(const int& shoots);

	/*Getters*/
	string getName() const;
	int getShirtNum() const;
	float getHeight() const;
	int getAge() const;
	int getShoeSize() const;
	int getBlockNum() const;
	int getAssistNum() const;
	int getFoulsNum() const;
	int get2PointThrows() const;
	int get3PointThrows() const;
	int get2PointShoots() const;
	int get3PointShoots() const;
	int getScore() const;

	/*Methods*/
	virtual void foul();
	virtual void shoot(const PointsEnum& points,const bool& statusSuccess);
	virtual void assist();
	virtual void block();
	virtual void printMe() const;
	virtual void scanToMe();

protected:
	/*Members*/
	string m_name;
	int m_shirtNum;
	float m_height;
	int m_age;
	int m_shoeSize;
	int m_blocks;
	int m_assists;
	int m_fouls;
	int m_2PointThrow;
	int m_3PointThrow;
	int m_2PointShoot;
	int m_3PointShoot;
	int m_score;

	/*Methods*/
	virtual float scoreAssistsRatio() const;
	virtual void updateScore();
};

ostream& operator<<(ostream& out, const Player& player);
istream& operator>>(istream& in, Player& player);
