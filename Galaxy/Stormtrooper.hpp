#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring>
#include "Planet.hpp"
#include <fstream>

enum class RankofStormtrooper { Chief, Trooper, Captain };

class Stormtrooper {
	char* id;
	RankofStormtrooper rank;
	char* type;
	Planet planet;
public:
	char* get_id() const;
	RankofStormtrooper get_rank() const;
	char* get_type() const; 
	void set_id(const char* _id);
	void set_rank(const RankofStormtrooper _rank); 
	void set_type(const char* _type);
	void set_planet(const Planet _planet);
	void print();
	Stormtrooper();
	Stormtrooper(const char* _id, const char* _type, const RankofStormtrooper _rank, const Planet _planet);
	Stormtrooper(const Stormtrooper& other);
	~Stormtrooper();
	Stormtrooper& operator=(const Stormtrooper& other);
	void WriteInFileTrooper(const Stormtrooper& trooper);
};
