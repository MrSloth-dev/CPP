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

#include "BitcoinExchange.hpp"

int main(int argc, char * argv[])
{
	(void)argc;
	if (argc != 2) {
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange& btc = BitcoinExchange::getInstance();
		if (btc.checkInput(argv[1]))
			btc.parseInput(argv[1]);
	}
	catch (std::exception &e ) { }
}
 
