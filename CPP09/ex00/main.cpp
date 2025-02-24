/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 15:50:21 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easy.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main()
{
	{
		const int find = 10;
		std::vector<int> temp;
		std::cout << "Trying to find " << find << " in vector" << std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 2);
		std::vector<int>::iterator ite = ::easyfind(temp, find);
		if (ite != temp.end())
			std::cout << find << " is in our container" << std::endl;
		else
			std::cerr << find << " is not in our container" << std::endl;
	}
	{
		const char find = 'b';
		std::vector<int> temp;
		std::cout << std::endl << "Trying to find " << find << " in vector"<< std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(static_cast<char>(i * 2));
		try {
			::easyfind(temp, find);
			std::cout << find << " is in our container" << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << find << " is not in our container" << std::endl;
		}
	}
}

