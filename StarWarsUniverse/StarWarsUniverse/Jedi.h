#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.h"

//nqmam destruktor zashtoto w String si ima

enum class rankofJedi {YOUNGLING, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER,GRAND_MASTER };

class Jedi {
private:
	String name;
	rankofJedi rank;
	int age;
	String colorofSaber;
	double power;
	void copy(const Jedi& other);
public:
	Jedi();
	Jedi(const String _name,const rankofJedi _rank,const int _age,const String _colorofsaber,const double _power);
	Jedi(const Jedi& other);
	Jedi& operator=(const Jedi& other);

	String get_name() const { return name; }
	rankofJedi get_rankofjedi() const {
		return rank;
	}
	int get_age() const { return age; }
	String get_colorofsaber() const { return colorofSaber; }
	double get_power() const { return power; }

	void set_jediname(const String& _name) { name = _name; }
	void set_rankofJedi(const rankofJedi _rank) { rank = _rank; }
	void set_jediage(int _age) { age = _age; } // da proverq kude tr da imam const i &
	void set_colorofsaber(const String& _colorofsaber) { colorofSaber = _colorofsaber;}
	void set_jedipower(const double _power) { power = _power; }

	bool operator<(const Jedi& other);

	size_t mymin(size_t num1, size_t num2);
	//void promote(double multiplier);
	//void demote(double multiplier);


};
