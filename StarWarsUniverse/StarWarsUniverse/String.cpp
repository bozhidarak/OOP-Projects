#include "String.h"


//size_t String::mystrlen(String str) {
//	size_t i = 0;
//	while (str[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}

void String::copy(const String& other) {
	size = other.size;
	str = new char[size];
	strcpy(str, other.str);//da go naprawq moee i strlen
}

void String::destroy()
{
	//if (str != nullptr)
	delete[] str;
}

String::String()
{
	str = nullptr;
	size = 0;
}

String::String(const char* _str) {

	size = strlen(_str)+1;
	str = new char[size];
	strcpy(str, _str);
}

String::String(const String& other) {
	copy(other);
}

String::~String() {
	destroy();
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

const bool String::empty() {
	return size == 0;
}

char& String::operator[](const size_t index)
{
	return str[index];
}

void String::resize(const size_t _size) {
	if (size >= _size)
		return;
	while (_size > size)
		size++;
	char* buff = new char[size + 1];
	for (size_t i = 0; i < size; i++)
		buff[i] = str[i];
	delete[] str;
	str = new char[size + 1];
	str = buff;
}
/*
void String::myconcat(const String& other) {
	resize(strlen(str) + strlen(other.str));
	strcat(str, other.str);
}*/
/*
void String::pushback(const char elem) {
	char* buff = new char[size + 1];
	for (size_t i = 0; i < size; i++)
		buff[i] = str[i];
	delete[] str;
	buff[size] = elem;
	str = new char[size + 1];
	str = buff;
}*/

/*
String& String::operator+=(const String& other) {
	myconcat(other);
	return *this;
}*/

bool String::operator==(const String& other) {
	return !strcmp(str, other.str);
}

bool String::operator<(const String& other) {

	size_t shortsize;
	if (size > other.size) shortsize = other.size;
	else shortsize = size;
	for (size_t i = 0; i < shortsize; i++) {
		if (str[i] < other.str[i])
		{
			return true;
		}
		else if (str[i] > other.str[i])
		{
			return false;
		}
	}
	if (size < other.size) return true;
	else return false;

}

