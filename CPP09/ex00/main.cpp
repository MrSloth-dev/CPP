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

bool checkDatabase() {
	std::string file = "./data.csv";
	BitcoinExchange& btc = BitcoinExchange::getInstance();
	std::ifstream input;
	input.open(file.c_str(), std::ios::in);
	try {
		if (! input.is_open() || input.fail())
			throw BitcoinExchange::NoDatabaseException();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(input, line)) {
		if (line.find(',') == line.npos || line == "date,exchange_rate")
			continue;
		line.replace(line.find(','), 1, " ");
		std::istringstream iss(line);
		std::string dates;
		float value;
		iss >> dates >> value;
		try {
		if (!btc.checkDate(dates))
			throw BitcoinExchange::InvalidDateException();
		if (value < 0)
			throw BitcoinExchange::InvalidValueException();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			std::cerr << "Error -> " << line << std::endl;
			return false;
		}
		std::cout << "->line: " << line << std::endl;
		std::cout << "dates: " << dates << std::endl;
		std::cout << "value: " << value << std::endl;
	}
	return true;
}
int main(int argc, char * argv[])
{
	(void)argc;
	/* if (argc != 2) {
		std::cout << "Error: Usage : ./btc <path/to/file>" << std::endl;
		return 1;
	} */
	checkDatabase();
	std::cout << argv[1] << std::endl;
}

