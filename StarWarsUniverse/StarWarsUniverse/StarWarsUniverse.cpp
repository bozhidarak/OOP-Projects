// StarWarsUniverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SWUniverse.h"

int main()
{
	String color = "green";
	//std::cout << color;
	Jedi j;
	j.set_rankofJedi(rankofJedi::INITIATE);
	j.set_colorofsaber(color);
	Planet pl;
	pl.set_planetname("zemQ");

	pl.add_citizen("gosho", j.get_rankofjedi(), 12, j.get_colorofsaber(), 10.89);

	SWUniverse sw;
	sw.add_planet("zemq");//raboti

	sw.create_jedi("zemq", "Gosho", rankofJedi::BATTLE_MASTER, 20, "green", 20.1);//raboti
	std::cout << sw.get_planets()[0].get_name() << std::endl;
	std::cout << sw.get_planets()[0].get_citizens()[0].get_name();
	std::cout << std::endl;

	sw.create_jedi("zemq", "Ivan", rankofJedi::KNIGHT, 50, "red", 3.2);
	sw.create_jedi("zemq", "Kolio", rankofJedi::KNIGHT, 30, "blue", 5);
	sw.create_jedi("zemq", "Petar", rankofJedi::KNIGHT, 80, "purple", 5);
	std::cout << "Check on remove_jedi: ";
	std::cout << sw.get_planets()[0].get_citizens().get_size() << std::endl;

	//sw.remove_jedi("Kolio", "zemq");//raboti
	std::cout << sw.get_planets()[0].get_citizens().get_size() << std::endl;

	//sw.promote_jedi("Ivan", 10);// raboti da proverq wse pak dali vuv for imam promenliva ili funkciq (i<temp)
	std::cout << sw.get_planets()[0].get_citizens()[1].get_power() << std::endl;

	//sw.demote_jedi("Petar", 0.1);//raboti da proverrq
	std::cout << "eho" << std::endl;
	std::cout << sw.get_planets()[0].get_citizens()[2].get_name() << std::endl;
	std::cout << sw.get_planets()[0].get_citizens()[2].get_power() << std::endl;
	switch (sw.get_planets()[0].get_citizens()[2].get_rankofjedi())
	{
	case rankofJedi::YOUNGLING: std::cout << "YOUNGLING";
		break;
	case rankofJedi::INITIATE:std::cout << "INITIATE";
		break;
	case rankofJedi::PADAWAN: std::cout << "PADWAN";
		break;
	case rankofJedi::KNIGHT_ASPIRANT: std::cout << "KNIGHT - ASPIRANT";
		break;
	case rankofJedi::KNIGHT: std::cout << "KNIGHT";
		break;
	case rankofJedi::MASTER: std::cout << "MASTER";
		break;
	case rankofJedi::BATTLE_MASTER: std::cout << "BATTLE - MASTER";
		break;
	case rankofJedi::GRAND_MASTER: std::cout << "GRAND MASTER";
		break;
	default:
		break;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	sw.get_strongest_jedi("zemq");//raboti no da proverq
	std::cout << std::endl;
	sw.get_youngest_jedi("zemq", rankofJedi::KNIGHT);//raboti no da proverq
	std::cout << std::endl;
	sw.print("zemq");//raboti
	//std::cout << std::endl;
	//sw.create_jedi("zemq", "Ivan1", rankofJedi::KNIGHT, 50, "redd", 3.2);
	//sw.create_jedi("zemq", "Ivan2", rankofJedi::KNIGHT, 50, "redd", 3.2);
	//sw.create_jedi("zemq", "Ivan3", rankofJedi::KNIGHT, 50, "redd", 3.2);
	std::cout<<sw.get_most_used_saber_color("zemq", rankofJedi::KNIGHT)<<std::endl;//raboti, da pomislq dali moje bez powtoreniq na cwetowete






}
