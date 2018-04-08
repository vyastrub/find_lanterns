#ifndef CITY_HPP
# define CITY_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "rails.hpp"

class City
{

public:
	City(const City &) = delete;
	City & operator=(const City &) = delete;

	static City & getInstance()
	{
		static City instanse;

		return instanse;
	}
	void init(const std::vector<int> & params);
	void addRails(const std::vector<int> & rails);
	void getLanterns();

private:
	std::string add(std::string s1, std::string s2);
	std::string mul(std::string s1, std::string s2);
	std::string sub(std::string s1, std::string s2);
	City() = default;
	~City() = default;
 
	int _rows;
	int _cols;
	int _rails;
	std::vector<Rails> _rail_system;
};


#endif 