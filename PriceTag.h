#pragma once
#include<iostream>
#include<fstream>

template <typename T>
class PriceTag {
private:
	T product;
	double price;
public:
	PriceTag(T _product, double _price) {
		product = _product;
		price = _price;
	}
	void setproduct(T _product) { product = _product; }
	void setprice(double _price) { price = _price; }
	T getproduct() const { return product; }
	double getprice() const { return price; }
	friend std::ostream& operator<<(std::ostream& os, const PriceTag& other) {
		os << other.product << std::endl;
		os << other.price << std::endl;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, PriceTag& other) {
		T _prod;
		double _price;
		is >> _prod >> _price;
		other.price = _price;
		other.product = _prod;
		return is;
	}
	PriceTag& discount(double _discount) {
		price -= _discount*price;
		return *this;
	}
	

	
};
