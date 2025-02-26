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
#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

int main()
{
	{
		std::cout << "\nTest 1" << std::endl;
		try {
		Span vector(42);
		vector.addNumber(10);
		vector.addNumber(20);
		vector.addNumber(40);
		vector.addNumber(400);
		vector.addNumber(123);
		vector.addNumber(723);
		vector.addNumber(12);
		vector.fillVector();
		vector.printVector();
		std::cout << vector.shortestSpan() << std::endl;
		std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}

	}
	{
		std::cout << "\nTest 2" << std::endl;
		try {
			Span vector(10);
			vector.fillVector();
			vector.addNumber(100);
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
	{
		std::cout << "\nTest 3" << std::endl;
		try {
			Span vector(10);
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
	{
		std::cout << "\nTest 4" << std::endl;
		try {
			Span vector(10);
			vector.addNumber(10);
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
	{
		std::cout << "\nTest 5" << std::endl;
		try {
			Span vector(100);
			vector.fillVector();
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
	{
		std::cout << "\nTest 4" << std::endl;
		try {
			Span vector(10);
			vector.addNumber(10);
			vector.addNumber(-10);
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
	{
		std::cout << "\nTest 5" << std::endl;
		try {
			Span vector(1);
			vector.addNumber(10);
			vector.addNumber(-10);
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		}
		catch (Span::MaxSizeReachedException &e) {
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
	{
		std::cout << "\nTest 6" << std::endl;
		try {
			Span vector(1);
			vector.addNumber(10);
			std::cout << vector.shortestSpan() << std::endl;
			std::cout << vector.longestSpan() << std::endl;
		catch (Span::MaxSizeReachedException &e) {
		}
			std:: cerr << "Tried to add more numbers that it can hold!" << std::endl;
		}
		catch (Span::NoSpanException &e) {
			std:: cerr << "No span to calculate, need 2 or more elements" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Unexpected exception" << std::endl;
		}
	}
}

