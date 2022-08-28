#include <iostream>
#include <string>

#include "Player.h"
#include "Forward.h"
#include "Guard.h"
#include "powerForward.h"
#include "SmallForward.h"
#include "PointGuard.h"
#include "ShootingGuard.h"
#include "management.h"

using namespace std;


int main()
{
	

	cout << "~~~Initializing players and first squad management~~~" << endl;
	cout << "-----------------------------------------------------" << endl;

	PointGuard lb("Lebron James", 3, 1.97f, 14, 43);
	PowerForward kd("K.D", 7, 1.97f, 22, 43);
	ShootingGuard sc("Steph Curry", 12, 1.90f, 26, 45);
	SmallForward ld("Luka Doncic", 9, 1.94f, 22, 43);
	ShootingGuard jh("James Harden", 30, 1.90f, 26, 45);
	SmallForward da("Deni Avdia", 44, 1.97f, 22, 43);
	PowerForward jt("Jason Tatum", 15, 1.90f, 26, 45);
	ShootingGuard dl("Damian Lilard", 10, 1.90f, 26, 45);

	Player* player_arr[6] = { &lb,&kd,&sc ,&ld , &jh , &da };

	Player* player_five[5] = { &lb ,&ld,&sc,&kd, &jh };

	Management mg1(player_arr, 6, player_five);

	cout << endl <<"~~~Add a player to the first squad management~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Luka Doncic was added." << endl;

	mg1.add_player(&dl);

	cout << endl << "~~~Print the first squad and opening five~~~" << endl;
	cout << "-----------------------------------------------------" << endl;

	mg1.print_squad();
	mg1.print_five();

	cout << endl << "~~~Copy the first squad management to the second~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "~~Print just the opening five for compare.~~" << endl;
	
	Management mg2(mg1);
	mg2.print_five();

	cout << endl << "~~~Initializing players and update the second squad management~~~" << endl;
	cout << "-----------------------------------------------------" << endl;

	ShootingGuard DH("Dor Haimo", 10, 1.97f, 26, 43);
	PowerForward TD("Tomer Ducho", 7, 1.97f, 22, 43);
	ShootingGuard PF("Peer Fich", 9, 1.90f, 26, 45);
	PowerForward YG("Yovel Gavri", 3, 1.97f, 22, 43);
	PointGuard GO("Gal Or", 8, 1.90f, 25, 45);
	SmallForward MT("Matan Tarif", 44, 1.93f, 32, 43);
	PointGuard EL("Eli Luzon", 99, 1.90f, 35, 45);
	SmallForward RN("Rabi Nahman", 1, 1.90f, 39, 45);

	Player* player_arr2[7] = { &RN,&DH,&TD ,&PF , &YG , &GO, &EL };
	
	mg2.update_squad(player_arr2, 7);

	mg2.print_squad();

	cout << endl << "~~~Choose an opening five from the squad ~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Warning! we replaced between Dor Haimo(10) & Rabi Nahman(1) after it - so choose 10 and DO NOT choose 1 in the opening five" << endl;
	
	mg2.opening_five();
	mg2.print_five();

	cout << endl << "~~~replace a player from the opening five ~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	
	mg2.replace_in_quintet(RN.getShirtNum(), DH.getShirtNum());
	mg2.print_five();

	cout << endl << "~~~Update some players stats from squad 1~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	
	mg1.do_shoot(lb.getShirtNum(), PointsEnum::points3, true);
	mg1.do_shoot(lb.getShirtNum(), PointsEnum::points3, false);
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_shoot(lb.getShirtNum(), PointsEnum::points2, true);
	mg1.do_shoot(lb.getShirtNum(), PointsEnum::points2, true);
	mg1.do_shoot(lb.getShirtNum(), PointsEnum::points2, false);
	mg1.do_shoot(lb.getShirtNum(), PointsEnum::points2, false);
	cout << "------------------" << endl;
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points3, false);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points2, true);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points2, false);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points3, false);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points2, true);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points2, true);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points3, false);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points2, false);
	mg1.do_shoot(jh.getShirtNum(), PointsEnum::points2, true);
	cout << "------------------" << endl;
	mg1.do_shoot(kd.getShirtNum(), PointsEnum::points3, true);
	mg1.do_block(kd.getShirtNum());
	mg1.do_shoot(kd.getShirtNum(), PointsEnum::points3, true);
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());
	
	mg1.do_shoot(ld.getShirtNum(), PointsEnum::points2, false);
	mg1.do_shoot(ld.getShirtNum(), PointsEnum::points2, false);
	mg1.do_shoot(ld.getShirtNum(), PointsEnum::points2, false);
	mg1.do_shoot(ld.getShirtNum(), PointsEnum::points3, false);

	cout << endl << "~~~Print total score & statistics~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	mg1.total_points();
	mg1.team_statistics();
	
	cout << endl << "~~~make 5 fouls and change player in the opening five~~~" << endl;
	cout << "-----------------------------------------------------" << endl;

	mg1.do_foul(ld.getShirtNum());
	mg1.do_foul(ld.getShirtNum());
	mg1.do_foul(ld.getShirtNum());
	mg1.do_foul(ld.getShirtNum());
	mg1.do_foul(ld.getShirtNum());

	mg1.replace_in_quintet(da.getShirtNum(), ld.getShirtNum());

	cout << endl << "~~~ Reach 10 blocks & assists ~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());
	mg1.do_block(kd.getShirtNum());

	cout << "------------------" << endl;

	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());
	mg1.do_assist(lb.getShirtNum());


	cout << endl << "~~~ Some players methods ~~~" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "scant to player:" << endl;
	
	Forward p1;
	cin >> p1;

	cout << "------------------" << endl;
	cout << "Use copy constructor and print the new forward player:" << endl << endl;
	
	Forward p2 = p1;
	cout << p2;

	cout << "------------------" << endl;
	cout << "Do assists & scores and check the < > operators." << endl << endl;

	p1.assist();
	p1.shoot(PointsEnum::points3, true);
	p2.assist();
	p2.shoot(PointsEnum::points2, true);

	cout << "I have smaller ratio: " << endl << endl;
	if (p1 < p2)
		cout << p1 << endl;

	cout << "I have bigger ratio: " << endl << endl;
	if (p2 > p1)
		cout << p2 << endl;

}
