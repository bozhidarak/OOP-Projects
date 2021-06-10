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
	void set_jediage(int _age) { age = _age; }
	void set_colorofsaber(const String& _colorofsaber) { colorofSaber = _colorofsaber;}
	void set_jedipower(const double _power) { power = _power; }


	friend std::ostream& operator<<(std::ostream& os, const Jedi& other)
	{
		os <<"Name: " <<other.name<<std::endl;
		os << "Age: "<<other.age<<std::endl;
		os << "Color of saber: " << other.colorofSaber<<std::endl;
		os << "Power: " << other.power<<std::endl;
		os << "Rank: ";
		switch (other.rank)
		{
		case rankofJedi::YOUNGLING: os << "Youngling" << std::endl;
			break;
		case rankofJedi::INITIATE: os<<"Initiate"<<std::endl;
			break;
		case rankofJedi::PADAWAN: os << "Padwan" << std::endl;
			break;
		case rankofJedi::KNIGHT_ASPIRANT: os << "Knight - Aspirant" << std::endl;
			break;
		case rankofJedi::KNIGHT:os << "Knight" << std::endl;
			break;
		case rankofJedi::MASTER:os << "Master" << std::endl;
			break;
		case rankofJedi::BATTLE_MASTER:os << "Battle - Master" << std::endl;
			break;
		case rankofJedi::GRAND_MASTER:os << "Grand - Master" << std::endl;
			break;
		default: os << "Invalid rank"<<std::endl;
			break;
		}
		return os;
	}

};
