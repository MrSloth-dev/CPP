/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:51:43 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 16:25:01 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <vector>

class Span {
	private:
	std::vector<int> _vector;
	unsigned int _maxSize;
	static int _curSize;

	Span();
	public:
	Span(unsigned int N);
	Span(const Span& copy);
	~Span();
	Span& operator=(const Span& copy);
	void addNumber(int newNumber);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	unsigned int getcurSize();
	unsigned int getmaxSize();

	class MaxSizeReachedException: public std::exception{
		const char * what() const throw();
	};
	class NoSpanException: public std::exception{
		const char * what() const throw();
	};
};

