/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:52:46 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/12 17:21:02 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include <sstream>

void	HandleSignal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	Stoi(std::string & s)
{
	int	i = 0;
	try {
		std::istringstream iss(s);
		if (!(iss >> i))
			return -1;
	}
	catch (...) {
		return -1;
	}
	return i;
}

bool IsNumber(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; i < (int)str.length() ;i++)
	{
		if (std::isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

void	Display()
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|  Welcome to 90's Phonebook                |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|   To Add Contact type ADD                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|   To Search Contact type SEARCH           |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|  For Exiting type EXIT                    |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
}
