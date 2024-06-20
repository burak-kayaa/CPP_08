#include "Span.hpp"

Span::Span() : _n(0), _v(std::vector<int>()) {}

Span::Span(unsigned int n) : _n(n), _v(std::vector<int>()) {}

Span::Span(Span const &other) : _n(other._n), _v(other._v) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_n = other._n;
		_v = other._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw Span::FullSpanException();
	_v.push_back(n);
}

void	Span::addNumber(unsigned int range, time_t seed)
{
	if (_v.size() + range > _n)
		throw Span::FullSpanException();
	srand(seed);
	for (unsigned int i = 0; i < range; i++)
		_v.push_back(rand());
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw Span::FullSpanException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (size_t i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw Span::FullSpanException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}
