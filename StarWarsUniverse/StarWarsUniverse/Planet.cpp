#include "Planet.h"

Planet::Planet() {

	//nqmam drugo tuk zashtoto stirnga i vektora si imat defoltni konstruktori
}

Planet::Planet(const String _name, const Vector<Jedi> _citizens, size_t _jedicount) {
	name = _name;
	citizens = _citizens;

}

Vector<Jedi>& Planet::add_citizen(const String& jedi_name, const rankofJedi rank, int jedi_age, const String& saber_color, double jedi_strength) {
	Jedi helper;
	helper.set_jediname(jedi_name);
	helper.set_rankofJedi(rank);
	helper.set_jediage(jedi_age);
	helper.set_colorofsaber(saber_color);
	helper.set_jedipower(jedi_strength);
	citizens.pushback(helper);
	return citizens;
}

void Planet::remove_citizen(const String& name) {
	size_t citizenscount = citizens.get_size();
	for (int i = 0; i < citizenscount; i++)
	{
		if (citizens[i].get_name() == name)
		{
			citizens.removeAtIndex(i);
		}
	}
}

void Planet::promote_citizen(const String& name, double multiplier) {
	size_t temp = citizens.get_size();

	for (int j = 0; j < temp; j++)
	{
		if (citizens[j].get_name() == name)
		{
			if (citizens[j].get_rankofjedi() == rankofJedi::GRAND_MASTER)
			{
				std::cout << "You can not promote rank Grand Master. Enter command again." << std::endl;
				return;
			}
			switch (citizens[j].get_rankofjedi())
			{
			case rankofJedi::YOUNGLING: citizens[j].set_rankofJedi(rankofJedi::INITIATE);
				break;

			case rankofJedi::INITIATE:  citizens[j].set_rankofJedi(rankofJedi::PADAWAN);
				break;

			case rankofJedi::PADAWAN:  citizens[j].set_rankofJedi(rankofJedi::KNIGHT_ASPIRANT);
				break;

			case rankofJedi::KNIGHT_ASPIRANT:  citizens[j].set_rankofJedi(rankofJedi::KNIGHT);
				break;

			case rankofJedi::KNIGHT:  citizens[j].set_rankofJedi(rankofJedi::MASTER);
				break;

			case rankofJedi::MASTER: citizens[j].set_rankofJedi(rankofJedi::BATTLE_MASTER);
				break;

			case rankofJedi::BATTLE_MASTER: citizens[j].set_rankofJedi(rankofJedi::GRAND_MASTER);
				break;
			default: std::cout << "Invalid rank.";//nqma da vleze ama vse pak
				break;
			}
			citizens[j].set_jedipower(citizens[j].get_power() + citizens[j].get_power() * multiplier);
			return;// nqma kak da ima s dwe ednakvi imena taka che da ne produljawa s cikula
		}
	}

}

void Planet::demote_citizen(const String& name, double multiplier) {

	size_t temp = citizens.get_size();

	for (size_t i = 0; i < temp; i++) {
		if (citizens[i].get_name() == name) {
			if (citizens[i].get_rankofjedi() == rankofJedi::YOUNGLING)
			{
				std::cout << "You can not demote rank Youngling. Enter command again." << std::endl;
				return;
			}
			switch (citizens[i].get_rankofjedi())
			{
			case rankofJedi::INITIATE: citizens[i].set_rankofJedi(rankofJedi::YOUNGLING);
				break;
			case rankofJedi::PADAWAN: citizens[i].set_rankofJedi(rankofJedi::INITIATE);
				break;
			case rankofJedi::KNIGHT_ASPIRANT: citizens[i].set_rankofJedi(rankofJedi::PADAWAN);
				break;
			case rankofJedi::KNIGHT:citizens[i].set_rankofJedi(rankofJedi::KNIGHT_ASPIRANT);
				break;
			case rankofJedi::MASTER:citizens[i].set_rankofJedi(rankofJedi::KNIGHT);
				break;
			case rankofJedi::BATTLE_MASTER:citizens[i].set_rankofJedi(rankofJedi::MASTER);
				break;
			case rankofJedi::GRAND_MASTER:citizens[i].set_rankofJedi(rankofJedi::BATTLE_MASTER);
				break;
			default: std::cout << "Invalid rank." << std::endl;// znam che nqma da vleze ama da ima
				break;
			}
			citizens[i].set_jedipower(citizens[i].get_power() - citizens[i].get_power() * multiplier);
			return;
		}
	}
}


Jedi& Planet::strongest_citizen() {
	size_t indexofstrongest = 0;
	double max = citizens[0].get_power();
	size_t citizenscount = citizens.get_size();
	for (size_t i = 1; i < citizenscount; i++)
	{
		if (citizens[i].get_power() > max)
		{
			max = citizens[i].get_power();
			indexofstrongest = i;
		}
	}
	return citizens[indexofstrongest];
}

Jedi Planet::youngest_jedi(rankofJedi rank, Jedi youngest, size_t indexofyoungest) {

	size_t citizenscount = citizens.get_size();
	Jedi temp = youngest;

	if (indexofyoungest + 1 == citizenscount)
		return temp;

	for (size_t i = (indexofyoungest + 1); i < citizenscount; i++)
	{
		if (citizens[i].get_rankofjedi() == rank) {
			if (citizens[i].get_age() < temp.get_age())
			{
				temp = citizens[i];
			}
			else if (citizens[i].get_age() == temp.get_age())
			{
				if (citizens[i].get_name() < temp.get_name()) temp = citizens[i];
			}
		}
	}
	return temp;
}

String Planet::mostusedsaber(rankofJedi rank) {
	size_t citizenscount = citizens.get_size();
	Vector<int> colorcounter;
	size_t temp = citizenscount;
	while (temp != 0)
	{
		colorcounter.pushback(0);
		temp--;
	}

	for (size_t i = 0; i < citizenscount - 1; i++)
	{
		if (citizens[i].get_rankofjedi() == rank) {
			colorcounter[i] = 1;
		}
		for (size_t j = i + 1; j < citizenscount; j++)
		{
			if (citizens[j].get_rankofjedi() == rank) {
				if (citizens[i].get_colorofsaber() == citizens[j].get_colorofsaber()) {
					colorcounter[i]++;
				}
			}
		}
	}
	size_t colorsize = colorcounter.get_size();// = citizenscount
	int max = 0;
	size_t indexofcolor = 0;
	for (size_t i = 0; i < colorsize; i++)
	{
		if (colorcounter[i] > max) {
			max = colorcounter[i];
			indexofcolor = i;
		}
	}
	return citizens[indexofcolor].get_colorofsaber();
}

String Planet::mostUsedColor() {
	size_t citizenscount = citizens.get_size();
	Vector<int> colorcounter;
	Vector<bool> foundgrandmaster;
	size_t temp = citizenscount;
	//bool foundGrandMaster = false;
	while (temp != 0)
	{
		colorcounter.pushback(1);
		foundgrandmaster.pushback(0);
		temp--;
	}

	for (size_t i = 0; i < citizenscount - 1; i++)
	{
		if (citizens[i].get_rankofjedi() == rankofJedi::GRAND_MASTER)
		{
			foundgrandmaster[i] = 1;
		}
		for (size_t j = i + 1; j < citizenscount; j++)
		{
			if (citizens[i].get_colorofsaber() == citizens[j].get_colorofsaber()) {
				colorcounter[i]++;
				if (citizens[j].get_rankofjedi() == rankofJedi::GRAND_MASTER) // && foundgrandmaster[i] = 0
				{
					foundgrandmaster[i] = 1;
				}

			}
		}
	}
	size_t colorsize = citizenscount;//da mahna
	int max = 0;
	size_t indexofcolor = 0;
	for (size_t i = 0; i < colorsize; i++)
	{
		if (colorcounter[i] > max && foundgrandmaster[i] == 1) {
			max = colorcounter[i];
			indexofcolor = i;
		}
	}
	return citizens[indexofcolor].get_colorofsaber();
}

void Planet::print() {
	size_t citizenscount = citizens.get_size();
	std::cout << get_name() << std::endl;

	for (size_t i = 0; i < citizenscount - 1; i++) {
		for (size_t j = i + 1; j < citizenscount; j++) {
			if (citizens[i].get_rankofjedi() > citizens[j].get_rankofjedi())
			{
				Jedi temp = citizens[i];
				citizens[i] = citizens[j];
				citizens[j] = temp;
			}
			else if (citizens[i].get_rankofjedi() == citizens[j].get_rankofjedi()) {
				if (citizens[j].get_name() < citizens[i].get_name()) {

					Jedi temp = citizens[i];
					citizens[i] = citizens[j];
					citizens[j] = temp;
				}
			}
		}
	}

	for (size_t i = 0; i < citizenscount; i++) {
		std::cout << citizens[i] << std::endl;
	}
	return;
}

void Planet::citizensort() {
	size_t citizenscount = citizens.get_size();
	for (size_t i = 0; i < citizenscount - 1; i++)
	{
		for (size_t j =  i + 1; j < citizenscount; j++)
		{
			if (citizens[j].get_name() < citizens[i].get_name())
			{
				Jedi temp = citizens[i];
				citizens[i] = citizens[j];
				citizens[j] = temp;
			}
		}
	}


}
//
//void Planet::saveToFile(std::ofstream& outFile) {
//	outFile << this->name << " " << this->citizens.get_size() << " ";
//	for (int i = 0; i < this->citizens.get_size(); i++) {
//
//	}
//}
