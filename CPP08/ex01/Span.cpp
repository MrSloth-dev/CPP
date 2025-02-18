/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:51:43 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 17:10:06 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

int	Span::_curSize = 0;

Span::Span(unsigned int N): _vector(0), _maxSize(N) { };
Span::~Span() {};

Span::Span(const Span& copy): _vector(copy._vector), _maxSize(copy._maxSize) { }
Span& Span::operator=(const Span& copy) {
	if (this != &copy) {
		_vector = copy._vector;
		_maxSize = copy._maxSize;
	}
	return *this;
}

unsigned int Span::getcurSize() {
	return this->_curSize;
}
unsigned int Span::getmaxSize() {

	return this->_maxSize;
}

void Span::addNumber(int newNumber) {
	if (getcurSize() == getmaxSize())
		throw Span::MaxSizeReachedException();
	this->_curSize++;
	this->_vector.push_back(newNumber);
}

unsigned int Span::shortestSpan() {
	unsigned int minSpan = INT_MAX;
	if (getcurSize() < 2)
		throw NoSpanException();
	std::sort(_vector.begin(), _vector.end());
	std::vector<int>::iterator start = _vector.begin();
	for (unsigned int i = 0; i < _vector.size() - 1; i++) {
		unsigned int span = abs(*start - *(++start));
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() {
	if (getcurSize() < 2)
		throw NoSpanException();
	unsigned int maxSpan = 0;
	std::sort(_vector.begin(), _vector.end());
	std::vector<int>::iterator start = _vector.begin();
	for (unsigned int i = 0; i < _vector.size() - 1; i++) {
		unsigned int span = abs(*start - *(++start));
		if (span > maxSpan)
			maxSpan = span;
	}
	return maxSpan;
}
const char * Span::MaxSizeReachedException::what() const throw() {
	return "Vector has its max size reached";
}

const char * Span::NoSpanException::what() const throw() {
	return "Vector has no span, because has less than 2 elements";
}
