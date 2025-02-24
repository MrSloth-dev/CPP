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
#include <ctime>
#include <climits>
#include <cstdlib>
#include <vector>
#include <iostream>

Span::Span(unsigned int N): _vector(0), _maxSize(N), _curSize(0) { };
Span::~Span() {};

Span::Span(const Span& copy): _vector(copy._vector), _maxSize(copy._maxSize), _curSize(0) { }
Span& Span::operator=(const Span& copy) {
	if (this != &copy) {
		_vector = copy._vector;
		_maxSize = copy._maxSize;
		_curSize = copy._curSize;
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
    unsigned int minSpan = UINT_MAX;
    if (getcurSize() < 2)
        throw NoSpanException();
    std::sort(_vector.begin(), _vector.end());
    for (unsigned int i = 0; i < _vector.size() - 1; i++) {
        unsigned int span = _vector[i + 1] - _vector[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
	if (getcurSize() < 2)
		throw NoSpanException();
	std::sort(_vector.begin(), _vector.end());
	int start = _vector.front();
	int end = _vector.back();
	std::cout <<"min val: " << start;
	std::cout <<"  max val: " << end << std::endl << std::endl;;
	return end - start;
}

void	Span::fillVector() {
	srand(time(0));
	while (getcurSize() < getmaxSize())
		addNumber(static_cast<int>(rand() % (_maxSize * 100)));
}

void	Span::printVector() {
	std::sort(_vector.begin(), _vector.end());
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}



const char * Span::MaxSizeReachedException::what() const throw() {
	return "Vector has its max size reached";
}

const char * Span::NoSpanException::what() const throw() {
	return "Vector has no span, because has less than 2 elements";
}
