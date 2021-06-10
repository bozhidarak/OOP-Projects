#pragma once
#include "Planet.h"
#include <fstream>
////added
//#include<fstream>
//
////added
//const char location[] = "jedi_data.txt";

class SWUniverse {
private:
	Vector<Planet> planets;

public:
	Vector<Planet> get_planets() { return planets; }
	void add_planet(const String planet_name);
	void create_jedi(const String& planet_name, const String jedi_name, const rankofJedi rank, int jedi_age, const String saber_color, double jedi_strength);
	void remove_jedi(const String& jedi_name, const String& planet_name);
	void promote_jedi(const String& jedi_name, double multiplier);
	void demote_jedi(const String& jedi_name, double multiplier); 
	void get_strongest_jedi(const String& planet_name);
	void get_youngest_jedi(const String& planet_name, rankofJedi jedi_rank);
	String get_most_used_saber_color_byrank(const String& planet_name, rankofJedi jedi_rank); // tr li &?
	String get_most_used_saber_color(const String planet_name);//&?
	void print(const String planet_name);//planet
	void printjedi(const String jedi_name);
	void twoplanets(const String planet1_name, const String planet2_name);
	//znachi pisha q taka puk ot konzolata kato se wuwede plus shte se izpulnqwa tazi funkciq
	void start();
	bool checkString(String name);
	bool checkforplanet(String plname);
	rankofJedi StringtoRank(String rank_str);
	bool checkrank(String rank_str);
	String enterplanetname();
	bool checkforplus(String name);

	//read write added
	/*void readFromFile();
	void saveToFile();*/

};
