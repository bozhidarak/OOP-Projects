#pragma once
#include "Time.h"
#include<string>
#include <fstream>

class TimestampWithDescription : public Time {
private:
	std::string desc;
public:
	void SetDescription(std::string _desc);
	std::string GetDescription() const;
	friend std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& other) {
		os << other.time << std::endl;
		os << other.desc << std::endl;;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, TimestampWithDescription& other) {
		std::string _desc;
		unsigned long _time;
		is >> _desc >> _time;
		other.desc = _desc;
		other.time = _time;
		return is;
	}
};