#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int n);
		void addNumber(unsigned int range, time_t seed);
		int shortestSpan();
		int longestSpan();
		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Span is full";
				}
		};
};

#endif