#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class String {
private:
	char* str;
	size_t size;
	void copy(const String& other);
	void destroy();
public:
	String();
	String(const char* _str);
	String(const String& other);
	~String();
	String& operator=(const String& other);

	size_t get_size() { return size; }
	const bool empty();
	char& operator[](const size_t index);
	void resize(const size_t _size);
	//void myconcat(const String& other);
	//void pushback(const char elem);//DA MAHNA
	//String& operator+=(const String& other);
	bool operator==(const String& other);
	friend std::ostream& operator<<(std::ostream& out, const String& other)
	{
		for (size_t i = 0; i < other.size; i++)
			out << other.str[i];
		return out;
	}

	bool operator<(const String& other);


};
