#pragma once
#include "Jedi.h"
#include "Vector.h"
#include<fstream>


class Planet {
	String name;
	Vector<Jedi> citizens;

public:
	String get_name() const { return name; }
	const Vector<Jedi>& get_citizens() const { return citizens; }
	Planet();
	Planet(const String _name, const Vector<Jedi> _citizens, size_t _jedicount);
	Vector<Jedi>& add_citizen(const String& jedi_name, const rankofJedi rank, int jedi_age, const String& saber_color, double jedi_strength);
	void set_planetname(const String& plname) { name = plname; }
	void remove_citizen(const String& name);
	void promote_citizen(const String& name,double multiplier);
	void demote_citizen(const String& name, double multiplier);
	Jedi& strongest_citizen();
	Jedi youngest_jedi(rankofJedi rank,Jedi youngest,size_t indexofyoungest);
	String mostusedsaber(rankofJedi rank);
	String mostUsedColor();
	void print();
	void citizensort();

	//added
	//void saveToFile(std::ofstream& outFile);
};
