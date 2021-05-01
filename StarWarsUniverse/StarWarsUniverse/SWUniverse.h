#pragma once
#include "Planet.h"
//da proverq include dali sa oki

class SWUniverse {
private:
	Vector<Planet> planets;
	//size_t count;
public:
	//SWUniverse();
	Vector<Planet> get_planets() { return planets; }
	void add_planet(const String planet_name);
	void create_jedi(const String& planet_name, const String jedi_name, const rankofJedi rank, int jedi_age, const String saber_color, double jedi_strength);
	void remove_jedi(const String& jedi_name, const String& planet_name);
	void promote_jedi(const String& jedi_name, double multiplier);
	void demote_jedi(const String& jedi_name, double multiplier); 
	void get_strongest_jedi(const String& planet_name);
	void get_youngest_jedi(const String& planet_name, rankofJedi jedi_rank);
};