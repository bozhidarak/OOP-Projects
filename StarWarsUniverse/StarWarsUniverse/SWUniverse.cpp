#include "SWUniverse.h"

//SWUniverse::SWUniverse() {
//	
//}

void SWUniverse::add_planet(const String planet_name) {

	Planet pl;
	pl.set_planetname(planet_name);
	planets.pushback(pl);

}

void SWUniverse::create_jedi(const String& planet_name, const String jedi_name, const rankofJedi rank, int jedi_age, const String saber_color, double jedi_strength)
{
	bool flag_jediname = false;
	size_t planets_size = planets.get_size();//count

	for (size_t i = 0; i < planets_size; i++)
	{
		size_t citizenscount = planets[i].get_citizens().get_size();
		for (size_t j = 0; j < citizenscount; j++)
		{
			if (planets[i].get_citizens()[j].get_name() == jedi_name)
				flag_jediname = true;
		}
		if (flag_jediname)
		{
			std::cout << "There is an alredy excisting jedi with this name." << std::endl;
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
			size_t citizenscount = planets[i].get_citizens().get_size();
			for (size_t j = 0; j < citizenscount; j++)
			{
				if (planets[i].get_citizens()[j].get_name() == jedi_name)
				{
					found = true;
				}
			}
			if (!found)
			{
				std::cout << "Jedi " << jedi_name << " does not live on this planet, enter comand again"<<std::endl;
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
		size_t citizenscount = planets[i].get_citizens().get_size();
		for (size_t j = 0; j < citizenscount; j++)
		{
			if (planets[i].get_citizens()[j].get_name() == jedi_name)
			{
				planets[i].promote_citizen(jedi_name, multiplier);
				return;
			}
		}
	}
	std::cout << "There is no jedi with this name. Enter command again.";
}

void SWUniverse::demote_jedi(const String& jedi_name, double multiplier) {
	size_t planets_size = planets.get_size();

	for (size_t i = 0; i < planets_size; i++)
	{
		size_t citizenscount = planets[i].get_citizens().get_size();
		for (size_t j = 0; j < citizenscount; j++)
		{
			if (planets[i].get_citizens()[j].get_name() == jedi_name)
			{
				planets[i].demote_citizen(jedi_name, multiplier);
				return;
			}
		}
	}
	std::cout << "There is no jedi with this name. Enter command again.";
}

void SWUniverse::get_strongest_jedi(const String& planet_name) {
	size_t planetscount = planets.get_size();
	Jedi strongest;
	for (size_t i = 0; i < planetscount; i++)
	{
		if ((planets[i].get_name() == planet_name) && planets[i].get_citizens().get_size())
		{
			if (planets[i].get_citizens().get_size() != 0)
			{
				strongest = planets[i].strongest_citizen();
				break;
			}
			else { std::cout << "There are no Jedi on this planet."; break; }
		}
	}
		std::cout << "Strongest jedi: " << std::endl;
		std::cout << strongest << std::endl;
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
	std::cout << youngest << std::endl;
}

String SWUniverse::get_most_used_saber_color_byrank(const String& planet_name, rankofJedi jedi_rank) {
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

String SWUniverse::get_most_used_saber_color(const String planet_name) {

	size_t planetscount = planets.get_size();
	String mostUsedColor;
	for (size_t i = 0; i < planetscount; i++) {

		if (planets[i].get_name() == planet_name) {
			mostUsedColor = planets[i].mostUsedColor();
			return mostUsedColor;
		}
	}
}

void SWUniverse:: print(const String planet_name) {
	size_t planetscount = planets.get_size();
	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet_name)
		{
			planets[i].print();
			return;
		}
	}
	std::cout << "Planet not found. Enter command again." << std::endl;
}

void SWUniverse::printjedi(const String jedi_name) {
	size_t planetscount = planets.get_size();

	for (size_t i = 0; i < planetscount; i++) {
		size_t citizenscount = planets[i].get_citizens().get_size();
		for (size_t j = 0; j < citizenscount; j++) {
			if (planets[i].get_citizens()[j].get_name() == jedi_name) {
				std::cout << planets[i].get_citizens()[j] << std::endl;
				return;
			}
		}
	}
	std::cout << "Jedi not found. Enter command again." << std::endl;
}

void SWUniverse::twoplanets(const String planet1_name, const String planet2_name) {
	size_t planetscount = planets.get_size();
	Planet planet1, planet2;
	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == planet1_name)
			planet1 = planets[i];
		else if (planets[i].get_name() == planet2_name)
			planet2 = planets[i];
	}
//	if (planet1.get_name() == nullptr || planet2.get_name() == nullptr) {
	//	std::cout << "Planets not found." << std::endl;
	//	return;
	//}
	size_t citizenscountofplanet2 = planet2.get_citizens().get_size();
	for (size_t i = 0; i < citizenscountofplanet2; i++)
	{
		planet1.add_citizen(planet2.get_citizens()[i].get_name(),planet2.get_citizens()[i].get_rankofjedi(),planet2.get_citizens()[i].get_age(),planet2.get_citizens()[i].get_colorofsaber(),planet2.get_citizens()[i].get_power());
	}
	planet1.citizensort();
	size_t citizenscount = planet1.get_citizens().get_size();
	for (size_t i = 0; i < citizenscount; i++) {
		std::cout << planet1.get_citizens()[i];
		std::cout<<std::endl;
	}
}

void SWUniverse::start() {
	String func;
	bool exit = true;
	while (exit)
	{
		std::cout << "Enter a comand: " << std::endl;
		std::cin >> func;

			if (func == "add_planet")
			{
				String argument;
				bool loop = false;
				do
				{
				std::cout << "Enter name of planet: ";
				std::cin >> argument;
				if (checkString(argument)) 
					loop = true;
				else
				{
					loop = false;
					add_planet(argument);
				}
				} while (loop);
			}

			else if (func == "create_jedi")
			{
				String planetname, jediname, saber,rank_str;
				int age;
				double strength;
				rankofJedi rank;
				bool loop = false;
				planetname = enterplanetname();
				do {
					std::cout << "Enter name of Jedi:";
					std::cin >> jediname;
					if (checkString(jediname)) loop = true;
					else loop = false;
				} while (loop);

				do {
					std::cout << "Enter color of saber:";
					std::cin >> saber;
					if (checkString(saber)) loop = true;
					else loop = false;
				} while (loop);

				do {
					std::cout << "Enter age and strength:"<<std::endl<<"(age is a positive whole number, strength is a positive number):"<<std::endl;
					std::cin >> age >> strength;
					if (age < 0 || strength < 0) loop = true;
					else loop = false;
				} while (loop);
				std::cin.ignore();
				do {
					loop = false;
					std::cout << "Enter rank of Jedi:" << std::endl << "ONLY Allowed: YOUNGLING, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER,GRAND_MASTER: " << std::endl;
					std::cin >> rank_str;
					if (checkrank(rank_str)) loop = true;
					else
					{
						rank = StringtoRank(rank_str);
						loop = false;
					}
				} while (loop);

				create_jedi(planetname, jediname, rank, age, saber, strength);
			}

			else if (func == "remove_jedi")
			{
					bool loop = false;
					String jediname, planetname;
				do {
					std::cout << "Enter name of Jedi: "<<std::endl;
					std::cin >> jediname;
					if (checkString(jediname)) loop = true;
					else loop = false;
				} while (loop);
				planetname = enterplanetname();
				remove_jedi(jediname, planetname);
			}

			else if (func == "promote_jedi")
			{
				bool loop = false;
				String jediname;
				double multiplier;
				do {
					std::cout << "Enter name of Jedi: " << std::endl;
					std::cin >> jediname;
					if (checkString(jediname)) loop = true;
					else loop = false;
				} while (loop);
				do {
					std::cout << "Enter multiplier: " << std::endl << "(Must be a positive number!)";
					std::cin >> multiplier;
					if (multiplier < 0) loop = true;
					else loop = false;
				} while (loop);
				std::cin.ignore();
				promote_jedi(jediname, multiplier);
			}

			else if (func == "demote_jedi")
			{
			bool loop = false;
			String jediname;
			double multiplier;
			do {
				std::cout << "Enter name of Jedi: " << std::endl;
				std::cin >> jediname;
				if (checkString(jediname)) loop = true;
				else loop = false;
			} while (loop);
			do {
				std::cout << "Enter multiplier: " << std::endl << "(Must be a positive number!)";
				std::cin >> multiplier;
				if (multiplier < 0) loop = true;
				else loop = false;
			} while (loop);
			 std::cin.ignore();
			 demote_jedi(jediname, multiplier);
			}

			else if (func == "get_strongest_jedi")
			{
			bool loop = false;
			String planetname;
			planetname = enterplanetname();
			get_strongest_jedi(planetname);
			}

			else if (func == "get_youngest")
			{
			bool loop = false;
			String planetname, rank_str;
			rankofJedi rank;
			planetname = enterplanetname();
			do {
				std::cout << "Enter rank of Jedi:" << std::endl <<
					"ONLY Allowed: YOUNGLING, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER,GRAND_MASTER: " << std::endl;
				std::cin >> rank_str;
				if (checkrank(rank_str)) loop = true;
				else
				{
					rank = StringtoRank(rank_str);
					loop = false;
				}
			} while (loop);
			get_youngest_jedi(planetname, rank);
			}

			else if (func == "get_saber_color_byrank") {
			bool loop = false;
			String planetname,rank_str, color;
			rankofJedi rank;
			planetname = enterplanetname();
			do {
				std::cout << "Enter rank of Jedi:" << std::endl <<
					"ONLY Allowed: YOUNGLING, INITIATE, PADAWAN, KNIGHT_ASPIRANT, KNIGHT, MASTER, BATTLE_MASTER,GRAND_MASTER: " << std::endl;
				std::cin >> rank_str;
				if (checkrank(rank_str)) loop = true;
				else
				{
					rank = StringtoRank(rank_str);
					loop = false;
				}
			} while (loop);
			color = get_most_used_saber_color_byrank(planetname, rank);
			std::cout << color << std::endl;
			}

			else if (func == "get_saber_color")
			{
			bool loop = false;
			String planetname, color;
			planetname = enterplanetname();
			color = get_most_used_saber_color(planetname);
			std::cout << color << std::endl;
			}

			else if (func == "print")//planet
			{
			bool loop = false;
			String planetname;
			if (planets.get_size() == 0)std::cout << "There are no planets. " << std::endl;
			else {
				planetname = enterplanetname();
				print(planetname);
			}
			}

			else if (func == "printjedi") {
			bool loop = false;
			String jediname;
			do {
				std::cout << "Enter name of Jedi: " << std::endl;
				std::cin >> jediname;
				if (checkString(jediname)) loop = true;
				else loop = false;
			} while (loop);
			printjedi(jediname);
			}
			else if (func == "exit") exit = false;
			//twoplanets
			else if (checkforplus(func)) {
			size_t sizeoffunc = func.get_size();
			size_t firstwordindex, secondwordindex; //end and begining
			String firstword, secondword;
			for (size_t i = 0; i < sizeoffunc; i++) {
				if (func[i] == ' ') {
					firstwordindex = i; break;
				}
			}
			secondwordindex = firstwordindex + 3;
			for (size_t i = 0; i < firstwordindex; i++)
			{
				firstword.pushback(func[i]);
			}
			
			if (checkforplanet(firstword)) {
				for (size_t i = secondwordindex; i < sizeoffunc; i++)
				{
					secondword.pushback(func[i]);
				}
				if (checkforplanet(secondword)) {
					twoplanets(firstword, secondword);
				}
				else std::cout << "There are no such planets, try again. ";
			}
			else std::cout << "There are no such planets, try again. ";

			}
			else std::cout << "Invalid command, try again.";

	}
}

bool SWUniverse::checkString(String name) { //nqmam operator [] za const string
	bool flag = false;
	if (name == "") flag = true;
	size_t sizeofname = name.get_size();
	for (size_t i = 0; i < sizeofname; i++)
	{
		if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9')))
			 flag = true;
	}
	return flag;
}

bool SWUniverse::checkforplanet(String plname) {
	bool found = false;
	size_t planetscount = planets.get_size();
	for (size_t i = 0; i < planetscount; i++)
	{
		if (planets[i].get_name() == plname)
			found = true;
	}
	return found;
}

rankofJedi SWUniverse::StringtoRank(String rank_str)
{
	rankofJedi rank;
	if (rank_str == "YOUNGLING") rank = rankofJedi::YOUNGLING;
	else if (rank_str == "INITIATE") rank = rankofJedi::INITIATE;
	else if (rank_str == "PADAWAN") rank = rankofJedi::PADAWAN;
	else if (rank_str == "KNIGHT_ASPIRANT") rank = rankofJedi::KNIGHT_ASPIRANT;
	else if (rank_str == "KNIGHT") rank = rankofJedi::KNIGHT;
	else if (rank_str == "MASTER") rank = rankofJedi::MASTER;
	else if (rank_str == "BATTLE_MASTER") rank = rankofJedi::BATTLE_MASTER;
	else if (rank_str == "GRAND_MASTER") rank = rankofJedi::GRAND_MASTER;
	return rank;
}

bool SWUniverse::checkrank(String rank_str) {
	if (rank_str == "YOUNGLING" || rank_str == "INITIATE" || rank_str == "PADAWAN" || rank_str == "KNIGHT_ASPIRANT" || rank_str == "KNIGHT"
		|| rank_str == "MASTER" || rank_str == "BATTLE_MASTER" || rank_str == "GRAND_MASTER") return false;
	else return true;
}

String SWUniverse::enterplanetname() {
	String planetname;
	bool loop;
	do {
		std::cout << "Enter name of planet:";
		std::cin >> planetname;
		if (checkforplanet(planetname)) loop = false;
		else loop = true;
	} while (loop);
	return planetname;
}

bool SWUniverse::checkforplus(String name) {
	size_t sizeofname = name.get_size();
	for (size_t i = 0; i < sizeofname; i++) {
		if (name[i] == '+') return true;
	}
	return false;
}

