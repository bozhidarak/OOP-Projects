#include "SWUniverse.h"

//SWUniverse::SWUniverse() {
//	count = 0;
//}

//da naprawq samo s imeto
void SWUniverse::add_planet(const String planet_name) {//trqbwa li & 

	Planet pl;
	pl.set_planetname(planet_name);
	planets.pushback(pl);

}

void SWUniverse::create_jedi(const String& planet_name, const String jedi_name, const rankofJedi rank, int jedi_age, const String saber_color, double jedi_strength)
{
	bool flag_planetname = false;
	bool flag_jediname = false;
	size_t planets_size = planets.get_size();
	for (size_t i = 0; i < planets_size; i++)
		if (planets[i].get_name() == planet_name) flag_planetname = true;
	if (!flag_planetname)
	{
		std::cout << "There is no such planet." << std::endl;
		return;
		
	}
	for (size_t i = 0; i < planets_size; i++)
	{
		for (size_t j = 0; j < planets[i].get_citizens().get_size(); j++)//ako nqma jedi kakwo stawa
			if (planets[i].get_citizens()[j].get_name() == jedi_name)
				flag_jediname = true;
		if (flag_jediname)
		{
			std::cout << "There is an alredy excisting jedi with this name.";
			return;
		}
	}
	for (int i = 0; i < planets_size; i++)//ne go dobawqm kym pyrwiq for za da moje pyrwo da se proweri dali ima jedi s takowa ime ili dali ima takawa planeta 
		if (planets[i].get_name() == planet_name)
		{
			planets[i].add_citizen(jedi_name, rank, jedi_age, saber_color, jedi_strength);
		}
}

void SWUniverse::remove_jedi(const String& jedi_name, const String& planet_name) {
	size_t planetscount = planets.get_size();
	bool found = false;
	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet_name)
		{
			
			for (size_t j = 0; j < planets[i].get_citizens().get_size(); j++)
			{
				if (planets[i].get_citizens()[j].get_name() == jedi_name)
				{
					found = true;
				}
			}
			if (!found)
			{
				std::cout << "Jedi " << jedi_name << " does not live on this planet.";
				return;
			}
			else planets[i].remove_citizen(jedi_name);
		}
	}
}


void SWUniverse::promote_jedi(const String& jedi_name, double multiplier) {

	size_t planets_size = planets.get_size();

	for (size_t i = 0; i < planets_size; i++)
	{
		for (size_t j = 0; j < planets[i].get_citizens().get_size(); j++)
		{
			if (planets[i].get_citizens()[j].get_name() == jedi_name)
			{
				planets[i].promote_citizen(jedi_name, multiplier);
				return;
			}
		}
	}
	std::cout << "There is no jedi with this name.";
}

void SWUniverse::demote_jedi(const String& jedi_name, double multiplier) {
	size_t planets_size = planets.get_size();

	for (size_t i = 0; i < planets_size; i++)
	{
		for (size_t j = 0; j < planets[i].get_citizens().get_size(); j++)
		{
			if (planets[i].get_citizens()[j].get_name() == jedi_name)
			{
				planets[i].demote_citizen(jedi_name, multiplier);
				return;
			}
		}
	}
	std::cout << "There is no jedi with this name.";
}

void SWUniverse::get_strongest_jedi(const String& planet_name) {
	size_t planetscount = planets.get_size();
	Jedi strongest = planets[0].get_citizens()[0];
	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet_name)
		{
			strongest = planets[i].strongest_citizen();
			break;
		}
	}
	std::cout << "Strongest jedi: " << std::endl;
	std::cout <<"Name: "<< strongest.get_name() << std::endl;
	std::cout << "Power: " << strongest.get_power() << std::endl; //nz dali da doizkarwam infoto
}

void SWUniverse::get_youngest_jedi(const String& planet_name, rankofJedi jedi_rank) {

	size_t planetscount = planets.get_size();
	Jedi youngest;
	bool found = false;
	size_t indexofyoungest = 0;

	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet_name) {

			size_t citizenscount = planets[i].get_citizens().get_size();
			for (size_t j = 0; j < citizenscount; j++) {
				if (planets[i].get_citizens()[j].get_rankofjedi() == jedi_rank)
				{
					found = true;
					youngest = planets[i].get_citizens()[j];
					indexofyoungest = j;
				}
			}
			if (!found)
			{
				std::cout << "There isn't a Jedi with this rank from this planet." << std::endl;
				return;
			}
		}
	}

	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet_name) {

			youngest = planets[i].youngest_jedi(jedi_rank,youngest,indexofyoungest);
		}
	}
	std::cout << "Youngest Jedi:"<<std::endl;
	std::cout << "Name: " << youngest.get_name() << std::endl;
	std::cout << "Age: " << youngest.get_age() << std::endl;
}

String SWUniverse::get_most_used_saber_color(const String& planet_name, rankofJedi jedi_rank) {
	size_t planetscount = planets.get_size();
	String mostusedcolor;

	for (size_t i = 0; i < planetscount; i++) {
		if (planets[i].get_name() == planet_name) 
		{
			mostusedcolor = planets[i].mostusedsaber(jedi_rank);
		}
	}
	return mostusedcolor;
}
//
//String SWUniverse:: get_most_used_saber_color(const String& planet_name) {
//	size_t planetscount = planets.get_size();
//	String mostusedcolor;
//
//	for (size_t i = 0; i < planetscount; i++) {
//		if (planets[i].get_name() == planet_name)
//		{
//			mostusedcolor = planets[i].mostusedsaber();
//		}
//	}
//	return mostusedcolor;
//
//}

void SWUniverse:: print(const String planet_name) {
	size_t planetscount = planets.get_size();
	
	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet_name)
		{
			planets[i].print();
		}
	}


}
