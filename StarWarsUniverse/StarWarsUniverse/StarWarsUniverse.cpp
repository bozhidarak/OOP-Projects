// StarWarsUniverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SWUniverse.h"

int main()
{
	SWUniverse sw;
//	sw.add_planet("zemq");//raboti
//
//	sw.create_jedi("zemq", "Gosho", rankofJedi::BATTLE_MASTER, 20, "green", 20.1);//raboti
//	std::cout << sw.get_planets()[0].get_name() << std::endl;
//	std::cout << sw.get_planets()[0].get_citizens()[0].get_name();
//	std::cout << std::endl;
//
//	sw.create_jedi("zemq", "Ivan", rankofJedi::KNIGHT, 50, "red", 3.2);
//	sw.create_jedi("zemq", "Kolio", rankofJedi::KNIGHT, 30, "blue", 5);
//	sw.create_jedi("zemq", "Petar", rankofJedi::MASTER, 80, "purple", 500.1);
//	sw.create_jedi("zemq", "John", rankofJedi::GRAND_MASTER, 500, "blue", 30.2);
//	sw.create_jedi("zemq", "Ivan2", rankofJedi::KNIGHT, 1, "red", 1000.4);
//	sw.create_jedi("zemq", "Ivan3", rankofJedi::KNIGHT, 2, "red", 1000.4);
//
//	std::cout << "Check on remove_jedi: ";
//	std::cout << sw.get_planets()[0].get_citizens().get_size() << std::endl;
//
//	sw.remove_jedi("Kolio", "zemq");//raboti
//	//sw.remove_jedi("Ivan2", "zemq");
//	std::cout << sw.get_planets()[0].get_citizens().get_size() << std::endl;
//	std::cout << sw.get_planets()[0].get_citizens()[3].get_name() << std::endl;
//
//	std::cout << "Promote: " << std::endl;
//	sw.promote_jedi("Ivan8", 10);// raboti
//	std::cout << sw.get_planets()[0].get_citizens()[1].get_power() << std::endl;
//	std::cout << (sw.get_planets()[0].get_citizens()[1].get_rankofjedi() == rankofJedi::MASTER) << std::endl;
//
//	std::cout << "Demote: " << std::endl;
//	sw.demote_jedi("Petar", 0.1);//raboti
//	std::cout << sw.get_planets()[0].get_citizens()[2].get_name() << std::endl;
//	std::cout << sw.get_planets()[0].get_citizens()[2].get_power() << std::endl;
//	switch (sw.get_planets()[0].get_citizens()[2].get_rankofjedi())
//	{
//	case rankofJedi::YOUNGLING: std::cout << "YOUNGLING";
//		break;
//	case rankofJedi::INITIATE:std::cout << "INITIATE";
//		break;
//	case rankofJedi::PADAWAN: std::cout << "PADWAN";
//		break;
//	case rankofJedi::KNIGHT_ASPIRANT: std::cout << "KNIGHT - ASPIRANT";
//		break;
//	case rankofJedi::KNIGHT: std::cout << "KNIGHT";
//		break;
//	case rankofJedi::MASTER: std::cout << "MASTER";
//		break;
//	case rankofJedi::BATTLE_MASTER: std::cout << "BATTLE - MASTER";
//		break;
//	case rankofJedi::GRAND_MASTER: std::cout << "GRAND MASTER";
//		break;
//	default:
//		break;
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//
//	//Strongest Jedi:
//	sw.get_strongest_jedi("zemq");//raboti
//	std::cout << std::endl;
//
//	//Youngest Jedi:
//	sw.get_youngest_jedi("zemq", rankofJedi::KNIGHT);//raboti
//	std::cout << std::endl;
//
//	std::cout << "Print:" << std::endl;
//	sw.print("zemq");//raboti
//	std::cout << std::endl;
//
//	sw.create_jedi("zemq", "Ivan1", rankofJedi::KNIGHT, 50, "red", 3.2);
//	sw.create_jedi("zemq", "Ivan4", rankofJedi::KNIGHT, 50, "red", 3.2);
//	sw.create_jedi("zemq", "Ivan5", rankofJedi::KNIGHT, 50, "redd", 3.2);
//	sw.create_jedi("zemq", "Ivan6", rankofJedi::GRAND_MASTER, 50, "blue", 3.2);
//
//	std::cout<<sw.get_most_used_saber_color_byrank("zemq", rankofJedi::KNIGHT)<<std::endl;//raboti, da pomislq dali moje bez powtoreniq na cwetowete
//
//	sw.printjedi("Ivan1");//raboti uj
//
//	std::cout << sw.get_most_used_saber_color("zemq") <<std::endl;//raboti ama da proverq
//
//	sw.add_planet("Mars");
//	sw.create_jedi("Mars", "deiman", rankofJedi::BATTLE_MASTER, 32, "blue", 123);
//	//sw.create_jedi("Mars", "Ivan", rankofJedi::BATTLE_MASTER, 32, "blue", 123);
//
//
////validacia ako se dostupwa jedi koito ne sushtestwuwa t.e ima 3 jedii i az dostypwam 4-ti - 25.03.Klas Vector Kalin 7:18min !!!!!!!!! ne e mn dobre
//	// да чу€ допълнителното от 16.05 за 4-те принципа на ооп в началото преди финална защита
//	std::cout << "OTTTTTTTT"<<std::endl;
//	//без сериализаци€
//	sw.twoplanets("zemq", "Mars");//ne raboti neshto ne e nared s sortiraneto na imenata

	

	// available comands
	std::cout << "WELCOME!" << std::endl<<"Available commands for Star Wars Universe are:"<<std::endl;
	std::cout << std::endl;
	std::cout << "add_planet, create_jedi, remove_jedi, promote_jedi, demote_jedi, get_strongest_jedi " << std::endl <<
		"get_youngest_jedi, get_most_used_saber_color_byrank, get_most_used_saber_color, print, printjedi" << std::endl<<
		"<planet_name> + <planet_name>, exit" << std::endl;
	std::cout << std::endl;
	std::cout << "CHOOSE WISELY!" << std::endl;
	std::cout << std::endl;
	sw.start();




}
