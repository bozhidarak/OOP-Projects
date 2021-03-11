// Jedi.Homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring> 

enum class RankofJedi { Padawan, Knight, Guardian, Master};
enum class RankofStormtrooper {Chief, Trooper, Captain};


char* EnumTostring(RankofJedi rank)
{ 
	char rankstring[32];
	if (rank == RankofJedi::Guardian)
	{
		strcpy(rankstring, "Guardian");
		return rankstring;
	}
	if (rank == RankofJedi::Padawan)
	{
		strcpy(rankstring, "Padwan");
		return rankstring;
	}
	if (rank == RankofJedi::Knight)
	{
		strcpy(rankstring, "Knight");
		return rankstring;
	}
	if (rank == RankofJedi::Master)
	{
		strcpy(rankstring, "Master");
		return rankstring;
	}
}

char* EnumToString2(RankofStormtrooper rank)
{
	char rankstring[32];
	if (rank == RankofStormtrooper::Captain)
	{
		strcpy(rankstring, "Captain");
		return rankstring;
	}
	if (rank == RankofStormtrooper::Chief)
	{
		strcpy(rankstring, "Chief");
		return rankstring;
	}
	if (rank == RankofStormtrooper::Trooper)
	{
		strcpy(rankstring, "Trooper");
		return rankstring;
	}
}

class Planet {
	char* name;
	char* PlanetSystem;
	char* republic;
public:
	char* get_planetname() { return name; }
	char* get_Planetsystem() { return PlanetSystem; }
	char* get_republic() { return republic; }

	void set_planetname(const char* _name) { strcpy(name, _name); }
	void set_planetsystem(const char* _planetsystem) { strcpy(PlanetSystem, _planetsystem); }
	void set_republic(const char* _republic) { strcpy(republic, _republic); }

	Planet()
	{
		name = nullptr;
		PlanetSystem = nullptr;
		republic = nullptr;
	}
	Planet(char* _name, char* _planetsystem, char* _republic)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		
		PlanetSystem = new char[strlen(_planetsystem) + 1];
		strcpy(PlanetSystem, _planetsystem);
		
		republic = new char[strlen(_republic) + 1];
		strcpy(republic, _republic);
	}

	Planet(const Planet& other)
	{
		name = new char[strlen(other.name) + 1];
		PlanetSystem = new char[strlen(other.PlanetSystem) + 1];
		republic = new char[strlen(other.republic) + 1];
		strcpy(name, other.name);
		strcpy(PlanetSystem, other.PlanetSystem);
		strcpy(republic, other.republic);
	}
	~Planet()
	{
		delete[] name;
		delete[] PlanetSystem;
		delete[] republic;
	}
	Planet& operator=(const Planet& other)
	{
		if (this != &other) {
			delete[] name;
			delete[] PlanetSystem;
			delete[] republic;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			PlanetSystem = new char[strlen(other.PlanetSystem) + 1];
			strcpy(PlanetSystem, other.PlanetSystem);
			republic = new char[strlen(other.republic) + 1];
			strcpy(republic, other.republic);		
		}
		return *this;
	}
};

class Jedi {

	char* name;
	RankofJedi rank;
	float midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;


public:
	void set_name(const char* _name)				{	strcpy(name,_name);	}
	void set_rank(RankofJedi _rank)                 { rank = _rank; }
	void set_midichlorian(float _midichlorian)		{	midichlorian = _midichlorian; }
	void set_planet( const char* name, const char* republic,const char* Planetsystem)
	{
		strcpy(this->planet.get_planetname(), name);
		strcpy(this->planet.get_republic(), republic);
		strcpy(this->planet.get_Planetsystem(), Planetsystem);
	}
	void set_species(const char* _species)           	{ strcpy(spicies, _species); }
	void set_militaryRank(const char _militaryRank[32])  { strcpy(militaryRank, _militaryRank); }


	char* get_name()            { return name; }
	RankofJedi get_rankofJedi() { return rank; }
	float get_midichlorian()    { return midichlorian; }
	char* get_spicies()      { return spicies; }
	char* get_militaryrank() { return militaryRank; }


	void print()
	{
		std::cout << "Jedi:" << std::endl;
		std::cout << "Name: " << get_name()<<std::endl;
		std::cout << "Rank: " << EnumTostring(get_rankofJedi())<<std::endl;
		std::cout << "Midichlorian: " << get_midichlorian()<<std::endl;
		std::cout << "Spicies: " << get_spicies() << std::endl;
		std::cout << "Military rank: " << get_militaryrank() << std::endl;
		std::cout << "Home planet: " << this->planet.get_planetname()
			<< " From " << this->planet.get_Planetsystem() << std::endl;
		std::cout << "From Republic " << this->planet.get_republic() << std::endl;
		std::cout << std::endl;
		
	}

	Jedi()
	{
		name = nullptr;
		midichlorian = 0;
		 spicies = nullptr;
		militaryRank = nullptr;
		//rankofjedi ??
		//planet??
	}

	Jedi(char* _name, int _medichlorian, char* _spicies, char* _militaryRank)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		_medichlorian = _medichlorian;

		spicies = new char[strlen(_spicies) + 1];
		strcpy(spicies, _spicies);

		militaryRank = new char[strlen(_militaryRank) + 1];
		strcpy(militaryRank, _militaryRank);
	}

	Jedi(const Jedi& other)
	{
		name = new char[strlen(other.name) + 1];
		spicies = new char[strlen(other.spicies) + 1];
		militaryRank = new char[strlen(other.militaryRank) + 1];
		strcpy(name, other.name);
		strcpy(militaryRank, other.militaryRank);
		strcpy(spicies, other.spicies);
		midichlorian = other.midichlorian;
	}

	~Jedi()
	{
		delete[] name;
		delete[] spicies;
		delete[] militaryRank;
	}
	Jedi& operator=(const Jedi& other)
	{
		if (this != &other) {
			delete[] name;
			delete[] spicies;
			delete[] militaryRank;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			spicies = new char[strlen(other.spicies) + 1];
			strcpy(spicies, other.spicies);
			militaryRank = new char[strlen(other.militaryRank) + 1];
			strcpy(militaryRank, other.militaryRank);
		}
		return *this;
	}


};

class Stormtrooper {
	char* id;
	RankofStormtrooper rank;
	char* type;
	Planet planet;
public: 
	char* get_id() { return id; }
	RankofStormtrooper get_rank() { return rank; }
	char* get_type() { return type; }

	void set_id(const char* _id) { strcpy(id, _id); }
	void set_rank(RankofStormtrooper _rank) { rank = _rank; }
	void set_type(const char* _type) { strcpy(type, _type); }
	void set_planet(const char* name,const char* republic,const char* planetsystem)
	{
		strcpy(this->planet.get_planetname(), name);
		strcpy(this->planet.get_Planetsystem(), planetsystem);
		strcpy(this->planet.get_republic(), name);
	}

	void print()
	{	
		std::cout << "Stormtrooper: " << std::endl;
		std::cout << "ID: " << get_id() << std::endl;
		std::cout << "Rank: " << EnumToString2(get_rank()) << std::endl;
		std::cout << "Type: " << get_type() << std::endl;
		std::cout << "From Planet: " << this->planet.get_planetname()
			<< " Planet system: " << this->planet.get_Planetsystem() << std::endl;
		std::cout << "Republic: " << this->planet.get_republic() << std::endl;
	}

	Stormtrooper()
	{
		id = nullptr;
		type = nullptr;
	}

	Stormtrooper(char* _id, char* _type)
	{
		id = new char[strlen(_id) + 1];
		strcpy(id, _id);

		type = new char[strlen(_type) + 1];
		strcpy(type, _type);
	}

	Stormtrooper(const Stormtrooper& other)
	{
		id = new char[strlen(other.id) + 1];
		type = new char[strlen(other.type) + 1];
		strcpy(id, other.id);
		strcpy(type, other.type);
	}

	~Stormtrooper()
	{
		delete[] id;
		delete[] type;
	}
	Stormtrooper& operator=(const Stormtrooper& other)
	{
		if (this != &other) {
			delete[] id;
			delete[] type;
			id = new char[strlen(other.id) + 1];
			strcpy(id, other.id);
			type = new char[strlen(other.type) + 1];
			strcpy(type, other.type);
		}
		return *this;
	}

};


int main()
{
	/*Jedi Anakin;
	Stormtrooper someone;

	Anakin.set_name("Anakin");
	Anakin.set_militaryRank("idk");
	Anakin.set_midichlorian(666);
	Anakin.set_planet("Tatooine", "the Galactic Republic", "idk");
	Anakin.set_species("Human");
	Anakin.set_rank(RankofJedi::Knight);

	someone.set_id("Gosho123");
	someone.set_planet("Earth","Bulgaria","Solar");
	someone.set_rank(RankofStormtrooper::Captain);
	someone.set_type("Clone");

	Anakin.print();
	someone.print();
	*/
	
}
