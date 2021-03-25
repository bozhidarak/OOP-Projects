#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstring>
#include <fstream>

inline int CharToInt(char* arr)//123 -> 120
{
	int num = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		num = num * 10 + arr[i] - '0';
	}
	return num;
}

inline bool CharToBool(char* arr)
{
	bool flag = false;
	if (arr[0] == '0') flag = false;
	else flag = true;

	return flag;
}

template<typename T>
class BattleShip {
private: 
	   int speed;
	   int numberOfGuns;
	   bool CanHyperJump;
	   int size;
	   T pilot;
public:
	
	void set_speed(const int _speed) { speed = _speed; }
	void set_numberOfGuns(const int _number) { numberOfGuns = _number; }
	void set_CanHyperJump(const bool _canhyperjump) { CanHyperJump = _canhyperjump; }
	void set_size(const int _size) { size = _size; }
	void set_pilot(const T _pilot) { pilot = _pilot; }

	int get_speed() const { return speed; }
	int get_numberOfGuns() const { return numberOfGuns; }
	bool get_canHyperJump() const { return CanHyperJump; }
	int get_size() const { return size; }
	T get_pilot() const { return pilot; }

	BattleShip() {
		speed = 0;
		numberOfGuns = 0;
		CanHyperJump = 0;
		size = 0;
	}

	BattleShip(const BattleShip& other)
	{
		speed = other.speed;
		numberOfGuns = other.numberOfGuns;
		CanHyperJump = other.CanHyperJump;
		size = other.size;
	}

	BattleShip(const int _speed, const int _numberofGuns, const bool _canHyperJump, const int _size, const T _pilot)
	{
		speed = _speed;
		numberOfGuns = _numberofGuns;
		CanHyperJump = _canHyperJump;
		size = _size;
		pilot = _pilot;
	}

	BattleShip& operator=(const BattleShip& other)
	{
		if (this != &other)
		{
			speed = other.speed;
			numberOfGuns = other.numberOfGuns;
			CanHyperJump = other.CanHyperJump;
			size = other.size;
			pilot = other.pilot;
		}
		return *this;
	}

	void ReadFromFile(const BattleShip& ship)
	{
		std::ifstream myfile;
		myfile.open("ReadShip.txt", std::ios::in);
		char buffer[50];
		int i = 1;
		while (myfile.getline(buffer, 64, '\n'))
		{
			if (i == 5) break;
			if (i == 1)
			{
				this->set_speed(CharToInt(buffer));
			}
			if (i == 2) this->set_numberOfGuns(CharToInt(buffer));
			if (i == 3) this->set_CanHyperJump(CharToBool(buffer));
			if (i == 4) this->set_size(CharToInt(buffer));
			//if(i==6) this -> set_pilot
			i++;
		}
		myfile.close();
	}

	void print()
	{
		std::cout << "Speed: " << get_speed() << std::endl;;
		std::cout << "Number of guns: " << get_numberOfGuns() << std::endl;
		std::cout << "Can it hyperjump? " << get_canHyperJump()<<std::endl;
		//std::cout << "Pilot: " << get_pilot() << std::endl;
	}
	
};


