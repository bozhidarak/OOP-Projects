#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
	T* arr;
	size_t capacity;
	size_t size;
	
	void copy(const Vector<T>& other)
	{
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];//WHY??!?!?!?!? 
		for (size_t i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}
	void destroy()
	{
		delete[] arr;
	}
	void resize()
	{
		while (size >= capacity) {
			capacity *= 2;
		}
		T* buff = new T[capacity];
		for (size_t i = 0; i < size; i++)
			buff[i] = arr[i];
		delete[] arr;
		arr = buff;
	}

public:
	size_t get_capacity() const { return capacity; }
	size_t get_size() const { return size; }

	Vector()
	{
		arr = nullptr;
		capacity = 8;
		size = 0;
	}

	Vector(const Vector& other)
	{
		copy(other);
	}

	Vector(const T* _arr)
	{
		size_t _size = 0;
		size_t _capacity = 8;
		while (_arr[_size] != NULL)
		{
			_size++;
		}
		while (_capacity < _size)
		{
			_capacity *= 2;
		}
		size = _size;
		capacity = _capacity;
		arr = new T[capacity];
		for (size_t i = 0; i < size; i++)
			arr[i] = _arr[i];
	}

	~Vector()
	{
		destroy();
	}

	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			destroy();
			copy(other);
		}
		return *this;
	}

	T& operator[](const size_t index)
	{
		if (index > size)
			exit(1);
		return arr[index];
	}

	const T& operator[](const size_t index) const
	{
		if (index > size)
			exit(1);
		return arr[index];
	}

	void pushback(const T& elem)
	{
		T* buff = new T[size + 1];
		if (size >= capacity)
			resize();
		for (size_t i = 0; i < size; i++)
			buff[i] = arr[i];
		buff[size] = elem;
		size++;
		delete[] arr;
		arr = buff;
	}

	const bool empty() { return size == 0; }

	friend std::ostream& operator<<(std::ostream& out, Vector& v)
	{
		for (size_t i = 0; i < v.size; i++)
			out << v.arr[i];
		return out;
	}

	void erase(size_t index)
	{
		for (size_t i = index; i < size - 1; i++)
			std::swap(arr[i], arr[i + 1]);
		--size;
	}
	Vector operator+=(const T& elem)
	{
		pushback(elem);
		return *this;
	}

	void removeAtIndex(size_t index)
	{
		for (size_t i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
};