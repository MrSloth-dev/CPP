/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 00:03:58 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <exception>
#include <stdlib.h>
#include <ctime>

int main()
{
	{
		std::cout << std::endl << "Int Test" << std::endl;
		Array<int> list(8);
		for ( int i = 0; i < list.size(); i++) {
			try {
				list[i] = i * 10;
				std::cout << list[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "Invalid Index" << std::endl;
			}
		}
	}
	{
		std::cout << std::endl << "Double Test" << std::endl;
		Array<double> list(8);
		for ( int i = 0; i < list.size(); i++) {
			try {
				list[i] = 10.0 / (i + 1);
				std::cout << list[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "Invalid Index" << std::endl;
			}
		}
	}
	{
		std::cout << std::endl << "String Test" << std::endl;
		Array<std::string> list(8);
		for ( int i = 0; i < list.size(); i++) {
			try {
				list[i] = 'a' + i;
				std::cout << list[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "Invalid Index" << std::endl;
			}
		}
	}
	{
		std::cout << std::endl << "Copy Test" << std::endl;
		Array<int> list(8);
		for ( int i = 0; i < list.size(); i++) {
			try {
				list[i] = i * 10;
				std::cout << list[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "index not valid" << std::endl;
			}
		}

		Array<int> list2(list);
		std::cout << std::endl << "Copied List" << std::endl;
		for ( int i = 0; i < list2.size(); i++) {
			try {
				list2[i] = i * 10;
				std::cout << list2[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "index not valid" << std::endl;
			}
		}

		Array<int> list3;
		std::cout << std::endl << "before Assign Operator List" << std::endl;
		for ( int i = 0; i < list3.size(); i++) {
			try {
				list3[i] = i * 10;
				std::cout << list3[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "index not valid" << std::endl;
			}
		}

		list3 = list;
		std::cout << std::endl << "Assign Operator List" << std::endl;
		for ( int i = 0; i < list3.size(); i++) {
			try {
				list3[i] = i * 10;
				std::cout << list3[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "index not valid" << std::endl;
			}
		}
	}

	{
		std::cout << std::endl << "Error Test" << std::endl;
		Array<std::string> list(8);
		for ( int i = 0; i < list.size() + 2; i++) {
			try {
				list[i] = 'a' + i;
				std::cout << list[i] << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "Invalid Index" << std::endl;
			}
		}
	}
	{
		std::cout << std::endl << "Copy Random Test" << std::endl;
		srand(time(0));
		const unsigned int size = 10;
		int* numbers = new int[size];

		Array<int> list(size);
		for (int i = 0 ; i < list.size(); i++)
		{
			double rando = rand();
			list[i] = rando;
			numbers[i] = rando;
		}
		for (int i = 0 ; i < list.size(); i++)
			if (list[i] != numbers[i])
				std::cerr << "Number don't match, copy not precise" << std::endl;
			else
				std::cout << "   list[" << i<<"] is " << list[i] << std::endl << "numbers[" << i<<"] is " << numbers[i] << std::endl;
	}
}
