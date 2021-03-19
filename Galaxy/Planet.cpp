
#include "Planet.hpp"

	char* Planet:: get_planetname() const { return name; }
	char* Planet:: get_Planetsystem() const { return PlanetSystem; }
	char* Planet::get_republic() const { return republic; }
	TypeOfPlanet Planet::get_type() const { return typeofplanet; }

	void Planet::set_planetname(const char* _name)
	{
		if (name != nullptr) delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	void Planet::set_type(const TypeOfPlanet _type) { typeofplanet = _type; }

	void  Planet::set_planetsystem(const char* _planetsystem) {
		if (PlanetSystem != nullptr) delete[] PlanetSystem;
		PlanetSystem = new char[strlen(_planetsystem) + 1];
		strcpy(PlanetSystem, _planetsystem);
	}
	void Planet::set_republic(const char* _republic) {
		if (republic != nullptr) delete[] republic;
		republic = new char[strlen(_republic) + 1];
		strcpy(republic, _republic);
	}

	Planet::Planet()
	{
		name = nullptr;
		PlanetSystem = nullptr;
		republic = nullptr;
		typeofplanet = TypeOfPlanet::Carbon;
	}
	Planet::Planet(const char* _name, const char* _planetsystem, const char* _republic, const TypeOfPlanet _type)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);

		PlanetSystem = new char[strlen(_planetsystem) + 1];
		strcpy(PlanetSystem, _planetsystem);

		republic = new char[strlen(_republic) + 1];
		strcpy(republic, _republic);

		typeofplanet = _type;
	}

	Planet::Planet(const Planet& other)
	{
		name = new char[strlen(other.name) + 1];
		PlanetSystem = new char[strlen(other.PlanetSystem) + 1];
		republic = new char[strlen(other.republic) + 1];
		strcpy(name, other.name);
		strcpy(PlanetSystem, other.PlanetSystem);
		strcpy(republic, other.republic);
		typeofplanet = other.typeofplanet;
	}
	 Planet:: ~Planet()
	{
		delete[] name;
		delete[] PlanetSystem;
		delete[] republic;
	}
	 Planet& Planet:: operator=(const Planet& other)
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

	 std::ostream& operator<<(std::ostream& os, const Planet& planet) {
		 os <<"Name of planet: " << planet.get_planetname() << std::endl;
		 os <<"Planet system: "<< planet.get_Planetsystem() << std::endl;
		 os << "Republic: "<<planet.get_republic() << std::endl;
		 os << "Type of planet: ";
		 switch (planet.typeofplanet) {
		 case TypeOfPlanet::Chthonian: os << "Chthonian" << std::endl; break;
		 case TypeOfPlanet::Carbon: os << "Carbon" << std::endl; break;
		 case TypeOfPlanet::Coreless: os << "Coreless" << std::endl; break;
		 case TypeOfPlanet::Desert: os << "Desert" << std::endl; break;
		 }

		 return os;
	 }
	 void Planet:: WriteInFilePlanet(const Planet& planet)
	 {
		 std::ofstream myfile;
		 myfile.open("WritePlanets.txt", std::ios::out);
		 myfile << planet.get_planetname() << std::endl;
		 myfile << planet.get_Planetsystem() << std::endl;
		 myfile << planet.get_republic() << std::endl;
		 switch (planet.get_type())
		 {
		 case TypeOfPlanet::Carbon: myfile << "Carbon" << std::endl; break;
		 case TypeOfPlanet::Chthonian: myfile << "Chthonian" << std::endl; break;
		 case TypeOfPlanet::Coreless: myfile << "Coreless" << std::endl; break;
		 case TypeOfPlanet::Desert: myfile << "Desert" << std::endl; break;
		 }

		 myfile.close();
	 }