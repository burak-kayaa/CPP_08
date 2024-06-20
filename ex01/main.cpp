#include "Span.hpp"
#include <vector>

int	main(void)
{
	Span sp(10);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	// use this method to add a range of numbers
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}