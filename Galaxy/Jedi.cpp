#include "Jedi.hpp"
#include "Planet.hpp"

	void Jedi:: set_name(const char* _name)
	{
		if (name != nullptr) delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	void Jedi::set_rank(const RankofJedi _rank) { rank = _rank; }
	void Jedi::set_midichlorian(const float _midichlorian) { midichlorian = _midichlorian; }
	void Jedi::set_planet(const Planet _planet) { planet = _planet; }
	void Jedi::set_species(const char* _species)
	{
		if (spicies != nullptr) delete[] spicies;
		spicies = new char[strlen(_species) + 1];
		strcpy(spicies, _species);
	}
	void Jedi::set_militaryRank(const char* _militaryRank)
	{
		if (militaryRank != nullptr) delete[] militaryRank;
		militaryRank = new char[strlen(_militaryRank) + 1];
		strcpy(militaryRank, _militaryRank);
	}

	char* Jedi::get_name() const { return name; }
	RankofJedi Jedi::get_rankofJedi() { return rank; }
	float Jedi::get_midichlorian() { return midichlorian; }
	char* Jedi::get_spicies() const { return spicies; }
	char* Jedi::get_militaryrank() const { return militaryRank; }


	void Jedi:: print()
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
		planet.printplanet<const char*, const TypeOfPlanet>(planet.get_planetname(), planet.get_republic(), planet.get_Planetsystem(), planet.get_type());

	}

	Jedi:: Jedi()
	{
		name = nullptr;
		midichlorian = 0;
		spicies = nullptr;
		militaryRank = nullptr;
		rank = RankofJedi::Guardian;
	}

	Jedi::Jedi(const char* _name, const float _medichlorian, const char* _spicies, const char* _militaryRank, const RankofJedi _rank, const Planet _planet)
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

	Jedi::Jedi(const Jedi& other)
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

	Jedi::~Jedi()
	{
		delete[] name;
		delete[] spicies;
		delete[] militaryRank;
	}
	Jedi& Jedi:: operator=(const Jedi& other)
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

	void Jedi::WriteInFileJedi(const Jedi& jedi)
	{
		std::ofstream myfile;
		myfile.open("WriteJedi.txt", std::ios::out);
		myfile << jedi.get_militaryrank() << std::endl;
		myfile << jedi.get_name() << std::endl;
		myfile << jedi.get_spicies() << std::endl;
		switch (get_rankofJedi())
		{//?? jedi.get_rankofJedi??
		case RankofJedi::Padawan: myfile << "Padawan" << std::endl;   break;
		case RankofJedi::Knight: myfile<< "Knight" << std::endl;   break;
		case RankofJedi::Guardian: myfile << "Guardian" << std::endl;   break;
		case RankofJedi::Master: myfile << "Master" << std::endl;   break;
		}
		myfile.close();

	}