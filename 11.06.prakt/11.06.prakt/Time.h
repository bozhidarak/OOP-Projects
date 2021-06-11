#pragma once
#include <iostream>
#include <fstream>

class Time {
protected:
	unsigned long time;
public:
	Time();
	Time(unsigned long _time);
	unsigned long GetValue();
	void SetValue(unsigned long _time);
	friend std::ostream& operator<<(std::ostream& os, const Time& other) {
		os << other.time;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Time& other) {
		unsigned long _time;
		is >> _time;
		other.time = _time;
		return is;
	}
	Time& operator+=(unsigned long other);
	Time operator+ (unsigned long other);



};