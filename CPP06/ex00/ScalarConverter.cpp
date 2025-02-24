/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:45:41 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 16:43:51 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>


/* class ScalarConverter {
	private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);
	ScalarConverter(const ScalarConverter& copy);
	public:
	static void	convert(const std::string& literal);
}; */

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return *this;
}
void ScalarConverter::convert(const std::string &str) {

	std::istringstream	iss(str);
	double				val;
	std::string	remainder;
	std::string dotcheck = iss.str();

	if (iss >> val) {
		iss >> remainder;
		if ((remainder.length() != 0 && remainder != "f") || (remainder == "f" && dotcheck.find('.') == dotcheck.npos)) {
			std::cout << "Error: Invalid Input" << std::endl;
			return ;
		}


		if (val >= 0 && val <= 127 && val == static_cast<int>(val)) {
				if (isprint(static_cast<int>(val)))
					std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;

		if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
				std::cout << "int: " << static_cast<int>(val) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		bool isNumber = val == static_cast<long>(val);
		if (isNumber) {
			std::cout << "float: "  << std::fixed << std::setprecision(0) << val << ".0f"  << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(0) << val << ".0"   << std::endl;
		}
		else {
			std::cout << "float: "  << std::fixed << val << "f"  << std::endl;
			std::cout << "double: " << std::fixed << val << ""   << std::endl;
		}
	}
	else if (str == "nan" || str == "nanf"){
		std::cout << "char: impossible" <<
		std::endl << "int: impossible" <<
		std::endl << "float: nanf" <<
		std::endl << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff" ){
		std::cout << "char: impossible" <<
		std::endl << "int: impossible" <<
		std::endl << "float: +inff" <<
		std::endl << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff"){
		std::cout << "char: impossible" <<
		std::endl << "int: impossible" <<
		std::endl << "float: -inff" <<
		std::endl << "double: -inf" << std::endl;
	}
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
		std::cout << "char: '" << static_cast<char>(str[1]) << "'" <<
		std::endl << "int: " << static_cast<int>(str[1]) <<
		std::endl << "float: " << static_cast<float>(str[1]) << ".0f"  <<
		std::endl << "double: " << static_cast<double>(str[1]) << ".0" << std::endl;
	}
	else if (str.length() == 1) {
		std::cout << "char: '" << static_cast<char>(str[0]) << "'" <<
		std::endl << "int: " << static_cast<int>(str[0]) <<
		std::endl << "float: " << static_cast<float>(str[0]) << ".0f"  <<
		std::endl << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
	}
	else
		std::cout << "Error: Invalid Input" << std::endl;
}
