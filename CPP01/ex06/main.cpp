/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:33:55 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/31 13:43:39 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Print(Harl Karen, std::string level)
{
	std::cout << "[ " << level << " ] " << std::endl;
	Karen.complain(level);
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error: Arguments invalid" << std::endl;
		return 1;
	}
	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int min_level = 4;
	for (int i = 0; i < 4; i++) {
		if (argv[1] == array[i]) {
			min_level = i;
			break;
		}
	}
	Harl Karen;
	switch (min_level) {
		case  0:
			Print(Karen, "DEBUG");
		case 1:
			Print(Karen, "INFO");
		case 2:
			Print(Karen, "WARNING");
		case 3:
			Print(Karen, "ERROR");
			break;
		default:
			std::cout <<"[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
