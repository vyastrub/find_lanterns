#ifndef PARCER_HPP
# define PARCER_HPP

#include "city.hpp"

class Parcer
{

public:
	
	Parcer() = delete;
	Parcer(Parcer &) = delete;
	Parcer(const char *filename);
	~Parcer() = default;

	void run();

private:

	std::ifstream _file;
};

#endif