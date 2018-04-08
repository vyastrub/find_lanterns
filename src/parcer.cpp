#include "../includes/parcer.hpp"

Parcer::Parcer(const char *filename)
{
	_file.open(filename);
	if (!_file.is_open())
		throw std::invalid_argument("invalid filename");
}

void Parcer::run()
{
	City & _instance = City::getInstance();
	std::vector<int> num;
	std::string line;

	int line_count = 0;
	while (getline(_file, line))
	{
		for (auto i = line.begin(); i < line.end(); ++i)
		{
			std::string tmp;
			if (*i >= '0' && *i <= '9')
			{
				while (*i >= '0' && *i <= '9')
					tmp.push_back(*i++);
				num.push_back(stoi(tmp));
			}
		}
		if (num.size() != 3)
		{
			_file.close();
			throw std::invalid_argument("invalid input");
		}
		if (line_count++ == 0)
			_instance.init(num);
		else 
			_instance.addRails(num);
		num.clear();
	}
	_file.close();
}