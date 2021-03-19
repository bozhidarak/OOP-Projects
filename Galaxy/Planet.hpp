#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring>
#include<fstream>

enum class TypeOfPlanet { Chthonian, Carbon, Coreless, Desert};

class Planet {
private:
	char* name;
	char* PlanetSystem;
	char* republic;
	TypeOfPlanet typeofplanet;

public:

	char* get_planetname() const;
	char* get_Planetsystem() const;
	char* get_republic() const;
	TypeOfPlanet get_type() const;
	void set_planetname(const char* _name);
	void set_planetsystem(const char* _planetsystem);
	void set_republic(const char* _republic);
	void set_type(const TypeOfPlanet _type);

	Planet();	
	Planet(const char* _name, const char* _planetsystem, const char* _republic, const TypeOfPlanet _type);
	Planet(const Planet& other);	
	~Planet();
	Planet& operator=(const Planet& other);

	friend std::ostream& operator<<(std::ostream& os, const Planet& planet);

	template<typename T1, class T2>
	void printplanet(const T1 name, const T1 republic, const T1 planetSystem, const T2 type)
	{	
			Planet p;
			p.set_planetname(name);
			p.set_planetsystem(planetSystem);
			p.set_republic(republic);
			p.set_type(type);
			std::cout << p;
		
	}

	void WriteInFilePlanet(const Planet& planet);
	
};
