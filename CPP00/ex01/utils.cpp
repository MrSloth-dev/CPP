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

void	handleSignal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	stoi(std::string & s)
{
	int	i;
	std::istringstream(s) >> i;
	return i;
}

bool isNumber(std::string str)
{
	for (int i = 0; i < (int)str.length() ;i++)
	{
		if (std::isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

void	ft_display()
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
