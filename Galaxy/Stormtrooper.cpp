#include "Stormtrooper.hpp"
#include "Planet.hpp"
 
	char* Stormtrooper:: get_id() const { return id; }
	RankofStormtrooper Stormtrooper:: get_rank() const { return rank; }
	char* Stormtrooper:: get_type() const { return type; }

	void Stormtrooper:: set_id(const char* _id)
	{
		if (id != nullptr) delete[] id;
		id = new char[strlen(_id) + 1];
		strcpy(id, _id);
	}
	void Stormtrooper:: set_rank(const RankofStormtrooper _rank) { rank = _rank; }
	void Stormtrooper:: set_type(const char* _type)
	{
		if (type != nullptr) delete[] type;
		type = new char[strlen(_type) + 1];
		strcpy(type, _type);
	}

	void Stormtrooper:: set_planet(const Planet _planet) { planet = _planet; }

	void Stormtrooper:: print()
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
		
		planet.printplanet<const char*, const TypeOfPlanet>(planet.get_planetname(), planet.get_republic(), planet.get_Planetsystem(), planet.get_type());
	}

	Stormtrooper:: Stormtrooper()
	{
		id = nullptr;
		type = nullptr;
		rank = RankofStormtrooper::Captain;
	}

	Stormtrooper:: Stormtrooper(const char* _id, const char* _type, const RankofStormtrooper _rank, const Planet _planet)
	{
		id = new char[strlen(_id) + 1];
		strcpy(id, _id);

		type = new char[strlen(_type) + 1];
		strcpy(type, _type);

		rank = _rank;
		planet = _planet;
	}

	Stormtrooper:: Stormtrooper(const Stormtrooper& other)
	{
		id = new char[strlen(other.id) + 1];
		type = new char[strlen(other.type) + 1];
		strcpy(id, other.id);
		strcpy(type, other.type);
		rank = other.rank;
		planet = other.planet;
	}

	Stormtrooper:: ~Stormtrooper()
	{
		delete[] id;
		delete[] type;
	}
	Stormtrooper& Stormtrooper:: operator=(const Stormtrooper& other)
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

	void Stormtrooper::WriteInFileTrooper(const Stormtrooper& trooper) {

		std::ofstream myfile;
		myfile.open("WriteTrooper.txt", std::ios::out);
		myfile << trooper.get_id() << std::endl;
		myfile << trooper.get_type() << std::endl;
		switch (trooper.get_rank())
		{
		case RankofStormtrooper::Captain: myfile << "Captain" << std::endl; break;
		case RankofStormtrooper::Chief: myfile << "Chief" << std::endl; break;
		case RankofStormtrooper::Trooper: myfile << "Trooper" << std::endl; break;
		}
		myfile.close();
	}
