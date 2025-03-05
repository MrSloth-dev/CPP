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
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char * argv[])
{
	(void)argc;
	/* if (argc != 2) {
		std::cout << "Error: Usage : ./btc <path/to/file>" << std::endl;
		return 1;
	} */
	BitcoinExchange& btc = BitcoinExchange::getInstance();
	btc.checkInput();
	std::cout << argv[1] << std::endl;
}

