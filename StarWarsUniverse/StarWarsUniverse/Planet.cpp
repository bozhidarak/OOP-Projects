#include "Planet.h"

Planet::Planet() {
	jedicount = 0;
	//nqmam drugo tuk zashtoto stirnga i vektora si imat defoltni konstruktori
}

Planet::Planet(const String _name, const Vector<Jedi> _citizens, size_t _jedicount) {
	name = _name;
	citizens = _citizens;
	jedicount = _jedicount;
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
			if (multiplier < 0)
			{
				std::cout << "The multiplier needs to be a positiv number.";
				return;//ne znam dali ne trqbwa prosto da se izchistwa ekrana ili neshto 
			}
			if (citizens[j].get_rankofjedi() == rankofJedi::GRAND_MASTER)
			{
				std::cout << "You can not promote rank Grand Master.";
				return;//tuk sushto
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
			default: std::cout << "Invalid rank.";
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
			if (multiplier < 0)
			{
				std::cout << "The multiplier needs to be a positiv number.";
				return;//ne znam dali ne trqbwa prosto da se izchistwa ekrana ili neshto 
			}
			if (citizens[i].get_rankofjedi() == rankofJedi::YOUNGLING)
			{
				std::cout << "You can not demote rank Grand Master.";
				return;//tuk sushto
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
			default: std::cout << "Invalid rank." << std::endl;// znam che nqma da vleze ama za wseki sluchai
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
/*
Jedi& Planet::youngest_jedi(rankofJedi rank) {
	size_t citizenscount = citizens.get_size();
	size_t indexofyoungest = 0;
	Jedi youngest;
	for (size_t i = 0; i < citizenscount; i++)
	{
		if (citizens[i].get_rankofjedi() == rank)
		{
			youngest = citizens[i];
			indexofyoungest = i;
			break;
		}
     }

	for (size_t i = indexofyoungest + 1; i < citizenscount; i++)
	{
		if (citizens[i].get_rankofjedi() == rank)
		{
			if (citizens[i].get_age() < youngest.get_age()) { youngest = citizens[i]; }
			else if (citizens[i].get_age() == youngest.get_age())
			{
				if (citizens[i] < youngest) youngest = citizens[i];
			}
		}
	}
	return youngest;

}*/

Jedi Planet::youngest_jedi(rankofJedi rank,Jedi youngest,size_t indexofyoungest) {

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
			colorcounter[i] = 1;//izdisha tuk 
		}
		else colorcounter[i] = 0;
		for (size_t j = i + 1; j < citizenscount; j++)
		{
			if (citizens[j].get_rankofjedi() == rank) {
				if (citizens[i].get_colorofsaber() == citizens[j].get_colorofsaber()) {
					colorcounter[i]++;
				}
			}
		}
	}
	size_t colorsize = colorcounter.get_size();
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
//
//String Planet::mostusedsaber() {
//	size_t citizenscount = citizens.get_size();
//	Vector<int> colorcounter;
//	size_t temp = citizenscount;
//	while (temp != 0)
//	{
//		colorcounter.pushback(0);
//		temp--;
//	}
//
//	for (size_t i = 0; i < citizenscount - 1; i++)
//	{   colorcounter[i] = 1;
//		for (size_t j = i + 1; j < citizenscount; j++)
//		{
//				if (citizens[i].get_colorofsaber() == citizens[j].get_colorofsaber()) {
//					colorcounter[i]++;
//				}
//		}
//	}
//	size_t colorsize = colorcounter.get_size();
//	int max = 0;
//	size_t indexofcolor = 0;
//	for (size_t i = 0; i < colorsize; i++)
//	{
//		if (colorcounter[i] > max && citizens[i].get_rankofjedi() == rankofJedi::GRAND_MASTER) {//ima dupka i ne tr da e taka
//			max = colorcounter[i];
//			indexofcolor = i;
//		}
//	}
//	return citizens[indexofcolor].get_colorofsaber();
//}


void Planet::print() {
	size_t citizenscount = citizens.get_size();
	std::cout << get_name() << std::endl;
	
	for (size_t i = 0; i < citizenscount - 1; i++) {
		for (size_t j = i + 1; j < citizenscount; j++) {
			if (citizens[i].get_rankofjedi() < citizens[j].get_rankofjedi())
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

}