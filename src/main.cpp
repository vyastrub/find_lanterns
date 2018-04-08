#include "../includes/city.hpp"
#include "../includes/parcer.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Usage ./city 'input_file.txt'" << std::endl;
		return 0; 
	}

	try
	{
		Parcer valid(av[1]);
		valid.run();
	}
	catch (const std::invalid_argument & e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
		return 0;
  	}

	City & instance = City::getInstance();
	try
	{
		instance.getLanterns();
	}
	catch (const std::invalid_argument & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 0;
  	}
	return 0;
}
