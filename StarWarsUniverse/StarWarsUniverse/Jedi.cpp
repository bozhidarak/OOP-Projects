#include "Jedi.h"

void Jedi::copy(const Jedi& other) {
	name = other.name;
	rank = other.rank;
	age = other.age;
	colorofSaber = other.colorofSaber;
	power = other.power;
}


Jedi::Jedi() {
	rank = rankofJedi::YOUNGLING;
	age = 0;
	power = 0;
}

Jedi::Jedi(const String _name, const rankofJedi _rank, const int _age, const String _colorofsaber, const double _power) {
	name = _name;
	rank = _rank;
	age = _age;
	colorofSaber = _colorofsaber;
	power = _power;
}

Jedi::Jedi(const Jedi& other) {
	copy(other);
}

Jedi& Jedi::operator=(const Jedi& other) { //nqmam destroy zashtoto String sam shte si go naprawi
	if (this != &other) {
		copy(other);
	}
	return *this;
}
//glavni bukwi
bool Jedi::operator<(const Jedi& other) {

	for (size_t i = 0; i < mymin(name.get_size(), other.get_name().get_size()); i++)
	{
		if (name[i] < other.get_name()[i])
		{
			return true;
		}
		else if (name[i] > other.get_name()[i]) return false;
		//poshov posho
		//gosho <  goshov true
	}// gosho < georgi false
	//petar < stefan true
	//pavel < pavli
	if (mymin(name.get_size(), other.get_name().get_size()) == name.get_size())
	{
		return true;
	}
	return false;
}

size_t Jedi:: mymin(size_t num1, size_t num2) {
	if (num1 > num2) return num1;
	return num2;
}

/*
void Jedi::promote(double multiplier) {
	if (multiplier < 0)
	{
		std::cout << "The multiplier needs to be a positive number" << std::endl;
		return;
	}
	if(rank == rankofJedi::GRAND_MASTER)
	{
		std::cout << "You can't promote jedi from this rank."<<std::endl;
		return;
	}
	switch (rank)
	{
	case rankofJedi::YOUNGLING: rank = rankofJedi::INITIATE;
		break;
	case rankofJedi::INITIATE: rank = rankofJedi::PADAWAN;
		break;
	case rankofJedi::PADAWAN: rank = rankofJedi::KNIGHT_ASPIRANT;
		break;
	case rankofJedi::KNIGHT_ASPIRANT: rank = rankofJedi::KNIGHT;
		break;
	case rankofJedi::KNIGHT: rank = rankofJedi::MASTER;
		break;
	case rankofJedi::MASTER: rank = rankofJedi::BATTLE_MASTER;
		break;
	case rankofJedi::BATTLE_MASTER: rank = rankofJedi::GRAND_MASTER;
		break;
	default: std::cout << "Invalid rank" << std::endl;
		break;
	}
	power += multiplier * power;
	return;
}*/
/*
void Jedi::demote(double multiplier) {

	if (multiplier < 0) {
		std::cout << "The multiplier must be a positive number.";
	}
	if (rank == rankofJedi::YOUNGLING) {
		std::cout << "You can't demote a jedi from this rank.";
		return;
	}
	switch (rank)
	{
	case rankofJedi::INITIATE: rank = rankofJedi::YOUNGLING;
		break;
	case rankofJedi::PADAWAN: rank = rankofJedi::INITIATE;
		break;
	case rankofJedi::KNIGHT_ASPIRANT: rank = rankofJedi::PADAWAN;
		break;
	case rankofJedi::KNIGHT: rank = rankofJedi::KNIGHT_ASPIRANT;
		break;
	case rankofJedi::MASTER: rank = rankofJedi::KNIGHT;
		break;
	case rankofJedi::BATTLE_MASTER: rank = rankofJedi::MASTER;
		break;
	case rankofJedi::GRAND_MASTER: rank = rankofJedi::BATTLE_MASTER;
		break;
	default: std::cout << "Invalid rank.";// ne bi trqbwalo da wliza no wse pak
		break;
	}
	power -= multiplier * power;
	return;
}*/