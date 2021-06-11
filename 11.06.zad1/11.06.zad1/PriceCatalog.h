#pragma once
#include"PriceTag.h"
#include <vector>

template<typename T>
class PriceCatalog {
private: 
	std::vector<PriceTag<T>>  catalog;
public:
	PriceCatalog& operator+=(const PriceTag<T>& tag) {
		catalog.push_back(tag);
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const PriceCatalog& other) {
		os << other;
		return os;
	}

};