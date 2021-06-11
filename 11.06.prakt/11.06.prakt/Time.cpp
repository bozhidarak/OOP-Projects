#include "Time.h"

Time::Time()
{
	time = 0;
}

Time::Time(unsigned long _time) {
	time = _time;
}

unsigned long Time::GetValue() {
	return time;
}

void Time::SetValue(unsigned long _time) {
	time = _time;
}

Time& Time::operator+=(unsigned long other) {
	time = time + other;
	return *this;
}

Time Time::operator+ (unsigned long other)
{
	Time _other;
	_other.SetValue(time + other);
	return other;
}

