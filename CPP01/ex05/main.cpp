/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:33:55 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/23 16:34:46 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main()
{
	srand(time(NULL));

	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	Harl Karen;
	for (int i = 0; i < 10; i++) {
		int randomNum = rand() % 4;
		Karen.complain(array[randomNum]);
		std::cout << std::endl;
	}
}
