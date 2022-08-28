#pragma once
#include <iostream>
#include "Player.h"
#include "Guard.h"
#include "Forward.h"
#include "powerForward.h"
#include "SmallForward.h"
#include "PointGuard.h"
#include "ShootingGuard.h"


class Management
{
public:
	/*Constructors & Distructors*/
	Management();
	Management(Player* arr[], const int size, Player* n_five[]);
	Management(const Management& mng);
	~Management();

	/*Operators*/
	Management& operator=(const Management& mng);
	
	/*Methods*/
	void update_squad(Player** pl, int size);
	void add_player(Player* pl);
	void player_check(Player* pl);
	void opening_five();
	void print_squad_for_coach() const;
	void replace_in_quintet(int shirt_num_in, int shirt_num_out);
	
	void do_foul(int shirt_num);
	void do_assist(int shirt_num);
	void do_shoot(int shirt_num, const PointsEnum& points, const bool& statusSuccess);
	void do_block(int shirt_num);
	int find_player(int shirt_num);

	void print_five() const;
	void print_squad() const;
	void team_statistics() const;
	void total_points() const;


private:
	/*Members*/
	Player** m_arr;
	int arr_size;
	int arr_count;
	Player* m_five[5];

};

