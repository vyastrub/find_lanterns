#ifndef RAILS_HPP
# define RAILS_HPP

struct Rails
{
	Rails() = default;
	~Rails() = default;
	Rails(const int _r, const int _c1, const int _c2)
		: r{_r}, c1{_c1}, c2{_c2} {}

	int r;
	int c1;
	int c2;
};

#endif