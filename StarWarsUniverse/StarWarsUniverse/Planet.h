#pragma once
#include "Jedi.h"
#include "Vector.h"


class Planet {
	String name;
	Vector<Jedi> citizens;
	size_t jedicount;// = citizens.get_size();

public:
	String get_name() const { return name; }
	const Vector<Jedi>& get_citizens() const { return citizens; }
	//size_t get_citizens_size() const { return citizens.get_size(); }
	Planet();
	Planet(const String _name, const Vector<Jedi> _citizens, size_t _jedicount);//mai ne mi trqbwa
	size_t get_jedicount() const { return jedicount; }
	Vector<Jedi>& add_citizen(const String& jedi_name, const rankofJedi rank, int jedi_age, const String& saber_color, double jedi_strength);
	void set_planetname(const String& plname) { name = plname; }
	void remove_citizen(const String& name);
	void promote_citizen(const String& name,double multiplier);
	void demote_citizen(const String& name, double multiplier);
	Jedi& strongest_citizen();
	Jedi& youngest_jedi(rankofJedi rank);

};
