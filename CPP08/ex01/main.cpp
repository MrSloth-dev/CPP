/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 17:10:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main()
{
	{
		Span vector(100);
		vector.addNumber(10);
		vector.addNumber(20);
		vector.addNumber(40);
		vector.addNumber(400);
		vector.addNumber(123);
		vector.addNumber(723);
		vector.addNumber(12);
		std::cout << vector.shortestSpan() << std::endl;
		std::cout << vector.longestSpan() << std::endl;


	}
	{
	}
}

