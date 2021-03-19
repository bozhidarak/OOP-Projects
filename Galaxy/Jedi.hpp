#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring>
#include "Planet.hpp"
#include <fstream>

enum class RankofJedi { Padawan, Knight, Guardian, Master };

class Jedi {

	char* name;
	RankofJedi rank;
	float midichlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;


public:
	void set_name(const char* _name);
	
	void set_rank(const RankofJedi _rank);
	void set_midichlorian(const float _midichlorian);
	void set_planet(const Planet _planet);
	void set_species(const char* _species);
	void set_militaryRank(const char* _militaryRank);
	char* get_name() const;
	RankofJedi get_rankofJedi(); 
	float get_midichlorian();
	char* get_spicies() const;
	char* get_militaryrank() const;


	void print();
	Jedi();
	Jedi(const char* _name, const float _medichlorian, const char* _spicies, const char* _militaryRank, const RankofJedi _rank, const Planet _planet);
	Jedi(const Jedi& other);
	~Jedi();
	Jedi& operator=(const Jedi& other);
	void WriteInFileJedi(const Jedi& jedi);
};