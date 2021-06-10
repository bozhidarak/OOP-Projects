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


