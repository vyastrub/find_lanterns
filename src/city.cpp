#include "../includes/city.hpp"

std::string City::add(std::string s1, std::string s2)
{ 
	std::string result;
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	for (auto & i : s1)
		i -= '0';
	for (auto & i : s2)
		i -= '0';
	if (s2.size() < s1.size())
		s2.resize(s1.size(), 0);
	else if (s1.size() < s2.size())
		s1.resize(s2.size(), 0);

	int tmp = 0;
	for (size_t i = 0; i < s2.size(); ++i)
	{
		int sub = s1[i] + s2[i] + tmp;
		if (sub > 9)
		{
			sub -= 10;
			tmp = 1;
		}
		else
			tmp = 0;
		result.push_back(sub + '0');
	}
	if (tmp != 0)
		result.push_back(tmp + '0');	
	std::reverse(result.begin(), result.end());
	return result;
}

std::string City::sub(std::string s1, std::string s2)
{ 
	std::string result;
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	for (auto & i : s1)
		i -= '0';
	for (auto & i : s2)
		i -= '0';
	s2.resize(s1.size(), 0);
	int tmp = 0;
	for (size_t i = 0; i < s2.size(); ++i)
	{
		int sub = s1[i] - s2[i] - tmp;
		if (sub < 0)
		{
			sub += 10;
			tmp = 1;
		}
		else
			tmp = 0;
		result.push_back(sub + '0');
	}
	std::reverse(result.begin(), result.end());
	return result;
}

std::string City::mul(std::string s1, std::string s2)
{ 
	std::vector<int> result(s1.size() + s2.size(), 0);
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	for (auto & i : s1)
		i -= '0';
	for (auto & i : s2)
		i -= '0';

	for (size_t i = 0; i < s1.size(); ++i)
		for (size_t j = 0; j < s2.size(); ++j)
			result[i + j] += s1[i] * s2[j];
	int tmp;
	for (size_t i = 0; i < s1.size() + s2.size(); ++i)
	{
		tmp = result[i] / 10;
		result[i] = result[i] % 10;
		result[i + 1] += tmp;
	}
	for (auto it = result.end() - 1; it >= result.begin(); ++it)
	{
		if (*it == 0)
			result.pop_back();
		else
			break ;
	}
	std::reverse(result.begin(), result.end());
	std::string res;
	for (auto i : result)
		res.push_back(i + '0');
	return res;
}

void City::init(const std::vector<int> & params)
{
	_rows = params[0];
	_cols = params[1];
	_rails = params[2];
	if ((_rows < 1 && _rows > 1000000000) ||
		(_cols < 1 && _cols > 1000000000))
	{
		throw std::invalid_argument("invalid map size");
	}
	if (_rails < 0 || _rails > 1000)
		throw std::invalid_argument("invalid rails quantity");
}

void City::addRails(const std::vector<int> & rails)
{
	int r = rails[0];
	int c1;
	int c2;
	if (rails[1] <= rails[2])
	{
		c1 = rails[1];
		c2 = rails[2];
	}
	else
	{
		c1 = rails[2];
		c2 = rails[1];
	}

	if (r < 1 || r > _rows || c1 < 1 || c1 > _cols || c2 < 1 || c2 > _cols)
		throw std::invalid_argument("rails out of city");
	for (auto & i : _rail_system)   //merging  incoming rails
		if (i.r == r)
		{
			if (c1 >= i.c1 && c2 <= i.c2)  
				return;	
			else if ((c1 < i.c1 && c2 >= i.c1) || (c2 > i.c2 && c1 <= i.c2))
			{
				if (c1 < i.c1)
					i.c1 = c1;
				if (c2 > i.c2)
					i.c2 = c2;
				return;
			}
		}
	Rails tmp(r, c1, c2);
	_rail_system.push_back(tmp);
}

void City::getLanterns()
{
	std::ofstream out("out.txt");
	if (!out.is_open())
		throw std::invalid_argument("error writing file");
	std::string total_rails = "0";
	for (auto i : _rail_system)
		total_rails = add(total_rails, std::to_string(i.c2 - i.c1 + 1));
	std::string total_area = mul(std::to_string(_rows), std::to_string(_cols));
	out << sub(total_area, total_rails);
	out.close();
}

