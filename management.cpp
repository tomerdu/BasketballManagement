#include <iostream>
#include "management.h"


Management::Management()
	: m_arr(new Player* [1]), arr_count(0), arr_size(1)
{
	if (!m_arr)
	{
		cout << "memory allocation failed" << endl;
		exit(-1);
	}

	m_arr[0] = nullptr;

	for (int i = 0; i < 5; i++)
	{
		m_five[i] = nullptr;
	}
}



Management::Management(Player* arr[], const int size, Player* n_five[])
	: m_arr(new Player* [size]), arr_count(0), arr_size(size)
{
	if (!m_arr)
	{
		cout << "memory allocation failed" << endl;
		exit(-1);
	}

	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i])
		{
			add_player(arr[i]);

			for (int j = 0; j < 5; j++)
			{
				if (n_five[j] == arr[i])
				{
					m_five[j] = m_arr[i];
					break;
				}
			}
		}
		else
		{
			m_arr[i] = nullptr;
		}
	}

}

Management::Management(const Management& mng)
	: m_arr(new Player* [1]), arr_size(1)
{
	m_arr[0] = nullptr;
	*this = mng;
}

Management::~Management()
{
	if (m_arr)
	{
		for (int i = 0; i < arr_count; i++)
			if (m_arr[i])
				delete m_arr[i];

		delete[] m_arr;
	}
		
}

Management& Management ::operator=(const Management& mng)
{
	if (this == &mng)
		return *this;

	for (int i = 0; i < arr_size; i++)
	{
		delete m_arr[i];
	}
	delete[] m_arr;

	arr_count = 0;
	arr_size = mng.arr_size;

	m_arr = new Player* [mng.arr_size];
	if (!m_arr)
	{
		cout << "memory allocation failed" << endl;
		exit(-1);
	}

	for (int i = 0; i < arr_size; i++)
	{
		if (mng.m_arr[i])
		{
			add_player(mng.m_arr[i]);
			
			for (int j = 0; j < 5; j++)
			{
				if (mng.m_five[j] == mng.m_arr[i])
				{
					m_five[j] = m_arr[i];
					break;
				}
			}
		}
		else
		{
			m_arr[i] = nullptr;
		}
	}


	return *this;
}

void Management::update_squad(Player** pl, int size)
{
	if (m_arr == pl)
	{
		cout << "No changes in squad." << endl;
		return;
	}

	for (int i = 0; i < 5; i++)
		m_five[i] = nullptr;

	for (int i = 0; i < arr_count; i++)
		if (m_arr[i])
			delete m_arr[i];
	delete[] m_arr;

	arr_count = 0;
	arr_size = size;

	m_arr = new Player* [size];
	if (!m_arr)
	{
		cout << "memory allocation failed" << endl;
		exit(-1);
	}

	for (int i = 0; i < arr_size; i++)
	{
		if (pl[i])
			add_player(pl[i]);
		else
			m_arr[i] = nullptr;
	}
	cout << "Coach, the new squad initialized." << endl << "Dont forget to choose an opening five!!!" << endl << endl;
}

void Management::add_player(Player* pl)
{
	if (arr_count == arr_size)
	{
		Player** temp;
		arr_size = arr_size * 2;
		temp = new Player * [arr_size];
		if (temp == nullptr)
			exit(-1);
		memcpy(temp, m_arr, arr_size * sizeof(Player*));
		for (int i = arr_size / 2; i < arr_size; i++)
		{
			temp[i] = nullptr;
		}

		delete[] m_arr;
		m_arr = temp;

	}

	player_check(pl);
	if (!m_arr[arr_count])
	{
		cout << "memory allocation failed" << endl;
		exit(-1);
	}
	else
		arr_count++;
		
	
	
}

void Management::player_check(Player* pl)
{

	PowerForward* pf = dynamic_cast<PowerForward*>(pl);
	if (pf)
	{
		m_arr[arr_count] = new PowerForward(*pf);
		return;
	}

	SmallForward* sf = dynamic_cast<SmallForward*>(pl);
	if (sf)
	{
		m_arr[arr_count] = new SmallForward(*sf);
		return;
	}

	PointGuard* pg = dynamic_cast<PointGuard*>(pl);
	if (pg)
	{
		m_arr[arr_count] = new PointGuard(*pg);
		return;
	}

	ShootingGuard* sg = dynamic_cast<ShootingGuard*>(pl);
	if (sg)
	{
		m_arr[arr_count] = new ShootingGuard(*sg);
		return;
	}

	Forward* f = dynamic_cast<Forward*>(pl);
	if (f)
	{
		m_arr[arr_count] = new Forward(*f);
		return;
	}

	Guard* g = dynamic_cast<Guard*>(pl);
	if (g)
	{
		m_arr[arr_count] = new Guard(*g);
		return;
	}
	cout << "The player you sent does not match any title." << endl;
	return;
}


void Management::total_points() const
{
	int sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->getScore();

	cout << "Team total points --->" << sum << endl;
}



void Management:: opening_five()
{
	int shirt1, shirt2, shirt3, shirt4, shirt5;
	int* index = new int[arr_count];
	int count;
	int j = 0;

	bool stopLoop = true;
	while (stopLoop)
	{
		for (int i = 0; i < arr_count; i++)
			index[i] = 0;
		count = 0;

		cout << endl << "coach : make your own opening five" << endl;
		print_squad_for_coach();
		cout << endl << "Please enter five shirt numbers of players that you want in your opening five" << endl;
		cout << "player(1) : " << endl;
		fflush(stdin);
		cin >> shirt1;
		cout << "player(2) : " << endl;
		fflush(stdin);
		cin >> shirt2;
		cout << "player(3) : " << endl;
		fflush(stdin);
		cin >> shirt3;
		cout << "player(4) : " << endl;
		fflush(stdin);
		cin >> shirt4;
		cout << "player(5) : " << endl;
		fflush(stdin);
		cin >> shirt5;

		for (int i = 0; i < arr_count; i++)
		{
			if (shirt1 == m_arr[i]->getShirtNum() ||
				shirt2 == m_arr[i]->getShirtNum() ||
				shirt3 == m_arr[i]->getShirtNum() ||
				shirt4 == m_arr[i]->getShirtNum() ||
				shirt5 == m_arr[i]->getShirtNum())
			{
				index[i] = 1;
				count++;
			}
		}

		if (count != 5)
		{
			cout << "One or more of the players are not in your roster, try again! " << endl;
			continue;
		}	
		else
		{
			for (int i = 0; i < arr_count; i++)
			{
				if (index[i] == 1)
				{
					m_five[j] = m_arr[i];
					j++;
				}
			}

			cout << endl;
			cout << "your opening five Is ready" << endl;
			stopLoop = false;
		}

	}
	
	delete[] index;
}

void Management::print_squad_for_coach() const
{
	for (int i = 0; i < arr_count; i++)
	{
		cout << i + 1 << ". ";
		cout << "Name: " << m_arr[i]->getName();
		cout << " | Shirt number: " << m_arr[i]->getShirtNum() << endl;
	}
}


void Management::replace_in_quintet(int shirt_num_in, int shirt_num_out)
{
	int flag_in = 0;
	int flag_out = 0;
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < 5; i++)
	{
		if (shirt_num_in == m_five[i]->getShirtNum())
		{
			cout << "Player on court already" << endl;
			flag_in = 1;
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (shirt_num_out == m_five[i]->getShirtNum())
		{
			flag_out = 1;
			index1 = i;
			break;
		}
	}

	if (flag_in == 0 && flag_out == 1)
	{
		for (int i = 0; i < arr_count; i++)
		{
			if (shirt_num_in == m_arr[i]->getShirtNum())
			{
				index2 = i;
				break;
			}
		}

		m_five[index1] = m_arr[index2];

		cout << "Player changed:" << endl;
		cout << "Shirt " << shirt_num_in << " --> in " << endl;
		cout << "Shirt " << shirt_num_out << " <-- out" << endl << endl;
	}
	else
	{
		cout << "Change Player failed - try again" << endl;
	}
}

void Management::print_five() const
{
	cout << "Players on court: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Name: " << m_five[i]->getName();
		cout << " | Shirt number: " << m_five[i]->getShirtNum() << endl;
	}

}

void Management::print_squad() const
{
	for (int i = 0; i < arr_count; i++)
	{
		cout << *(m_arr[i]) << endl;
	}
}

void Management::team_statistics() const
{
	int sum = 0;

	cout << endl << "team statistics:" << endl;

	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->getBlockNum();
	cout << "Blocks --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->getAssistNum();
	cout << "Assists --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->getFoulsNum();
	cout << "Fouls --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->get2PointThrows();
	cout << "2 Point throws --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->get2PointShoots();
	cout << "2 Point shoots --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->get3PointThrows();
	cout << "3 Point throws --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->get3PointShoots();
	cout << "3 Point shoots --->" << sum << endl;
	sum = 0;
	for (int i = 0; i < arr_count; i++)
		sum += m_arr[i]->getScore();
	cout << "Total score --->" << sum << endl;
}

void Management::do_foul(int shirt_num)
{
	int index = find_player(shirt_num);
	
	if (index != -1)
		m_five[index]->foul();

}

void Management::do_assist(int shirt_num)
{
	int index = find_player(shirt_num);

	if (index != -1)
		m_five[index]->assist();

}

void Management::do_shoot(int shirt_num, const PointsEnum& points, const bool& statusSuccess)
{
	int index = find_player(shirt_num);

	if (index != -1)
		m_five[index]->shoot(points, statusSuccess);

}

void Management::do_block(int shirt_num)
{
	int index = find_player(shirt_num);

	if (index != -1)
		m_five[index]->block();
}

int Management::find_player(int shirt_num)
{
	for (int i = 0; i < 5; i++)
		if (m_five[i]->getShirtNum() == shirt_num)
			return i;
		
	cout << "The player is off the court" << endl;
	return -1;
}
