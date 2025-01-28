/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:52:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/23 16:32:43 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< " You didn’t put enough bacon in my burger!"
		<< " If you did, I wouldn’t be asking for more!" << std::endl;
}


void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (array[i] == level)
		{
			(this->*funptr[i])();
			return ;
		}
	}
}

