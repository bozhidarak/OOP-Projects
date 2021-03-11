// jedi.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring> 

enum class RankofJedi { Padawan, Knight, Guardian, Master };
enum class RankofStormtrooper { Chief, Trooper, Captain };


class Planet {
	char* name;
	char* PlanetSystem;
	char* republic;
public:
	char* get_planetname() const { return name; }
	char* get_Planetsystem() const { return PlanetSystem; }
	char* get_republic() const { return republic; }

	void set_planetname(const char* _name)
	{
		if (name != nullptr) delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name); }

	void set_planetsystem(const char* _planetsystem) {
		if (PlanetSystem != nullptr) delete[] PlanetSystem;
		PlanetSystem = new char[strlen(_planetsystem) + 1]; 
		strcpy(PlanetSystem, _planetsystem); }
	void set_republic(const char* _republic) { 
		if (republic != nullptr) delete[] republic;
		republic = new char[strlen(_republic) + 1]; 
		strcpy(republic, _republic); }

	Planet()
	{
		name = nullptr;
		PlanetSystem = nullptr;
		republic = nullptr;
	}
	Planet(const char* _name, const char* _planetsystem, const char* _republic)
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
	void set_name(const char* _name) \
	{
		if (name != nullptr) delete[] name;
		name = new char[strlen(_name) + 1]; 
		strcpy(name, _name); 
	}
	void set_rank(const RankofJedi _rank) { rank = _rank; }
	void set_midichlorian(const float _midichlorian) { midichlorian = _midichlorian; }
	void set_planet(const Planet _planet)   { planet = _planet; }
	void set_species(const char* _species)
	{
		if (spicies != nullptr) delete[] spicies;
		spicies = new char[strlen(_species) + 1];
		strcpy(spicies, _species); 
	}
	void set_militaryRank(const char* _militaryRank)
	{
		if (militaryRank != nullptr) delete[] militaryRank;
		militaryRank = new char[strlen(_militaryRank) + 1]; 
		strcpy(militaryRank, _militaryRank);
	}

	char* get_name() const { return name; }
	RankofJedi get_rankofJedi() { return rank; }
	float get_midichlorian() { return midichlorian; }
	char* get_spicies() const { return spicies; }
	char* get_militaryrank() const { return militaryRank; }


	void print()
	{
		std::cout << "Jedi:" << std::endl;
		std::cout << "Name: " << get_name() << std::endl;

		std::cout << "Rank: ";
		switch (rank)
		{
		case RankofJedi::Padawan: std::cout << "Padawan" << std::endl;   break;
		case RankofJedi::Knight: std::cout << "Knight" << std::endl;   break;
	    case RankofJedi::Guardian: std::cout << "Guardian" << std::endl;   break;
		case RankofJedi::Master: std::cout << "Master" << std::endl;   break;
		}

		std::cout << "Midichlorian: " << get_midichlorian() << std::endl;
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
		rank = RankofJedi::Guardian;
	}

	Jedi(const char* _name, const float _medichlorian,const char* _spicies,const char* _militaryRank, const RankofJedi _rank, const Planet _planet)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);

		midichlorian = _medichlorian;

		spicies = new char[strlen(_spicies) + 1];
		strcpy(spicies, _spicies);

		militaryRank = new char[strlen(_militaryRank) + 1];
		strcpy(militaryRank, _militaryRank);

		rank = _rank;
		planet = _planet;
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
		planet = other.planet;
		rank = other.rank;
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
	char* get_id() const { return id; }
	RankofStormtrooper get_rank() const { return rank; }
	char* get_type() const { return type; }

	void set_id(const char* _id)
	{
		if (id != nullptr) delete[] id;
		id = new char[strlen(_id) + 1]; 
		strcpy(id, _id);
	}
	void set_rank(const RankofStormtrooper _rank) { rank = _rank; }
	void set_type(const char* _type) 
	{ 
		if (type != nullptr) delete[] type;
		type = new char[strlen(_type) + 1]; 
		strcpy(type, _type); 
	}

	void set_planet(const Planet _planet)   { planet = _planet; }

	void print()
	{
		std::cout << "Stormtrooper: " << std::endl;
		std::cout << "ID: " << get_id() << std::endl;
		std::cout << "Rank: ";
		switch (rank)
		{
		case RankofStormtrooper::Chief: std::cout << "Chief" << std::endl;   break;
		case RankofStormtrooper::Trooper: std::cout << "Trooper" << std::endl;   break;
		case RankofStormtrooper::Captain: std::cout << "Captain" << std::endl;   break;
		}
		std::cout << "Type: " << get_type() << std::endl;
		std::cout << "From Planet: " << this->planet.get_planetname()
			<< " Planet system: " << this->planet.get_Planetsystem() << std::endl;
		std::cout << "Republic: " << this->planet.get_republic() << std::endl;
	}

	Stormtrooper()
	{
		id = nullptr;
		type = nullptr;
		rank = RankofStormtrooper::Captain;
	}

	Stormtrooper(const char* _id, const char* _type, const RankofStormtrooper _rank, const Planet _planet)
	{
		id = new char[strlen(_id) + 1];
		strcpy(id, _id);

		type = new char[strlen(_type) + 1];
		strcpy(type, _type);

		rank = _rank;
		planet = _planet;
	}

	Stormtrooper(const Stormtrooper& other)
	{
		id = new char[strlen(other.id) + 1];
		type = new char[strlen(other.type) + 1];
		strcpy(id, other.id);
		strcpy(type, other.type);
		rank = other.rank;
		planet = other.planet;
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
	Jedi Anakin;
	Stormtrooper someone;
	Planet TheRepublic("Tatooine", "the Galactic Republic", "idk");

	Anakin.set_name("Anakin");
	Anakin.set_militaryRank("idk");
	Anakin.set_midichlorian(666);
	Anakin.set_planet(TheRepublic);
	Anakin.set_species("Human");
	Anakin.set_rank(RankofJedi::Knight);

	someone.set_id("Gosho123");
	someone.set_planet(TheRepublic);
	someone.set_rank(RankofStormtrooper::Captain);
	someone.set_type("Clone");

	Anakin.print();
	someone.print();
	

}
