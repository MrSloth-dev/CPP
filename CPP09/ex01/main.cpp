/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:22:00 by joao-pol          #+#    #+#             */
/*   Updated: 2025/03/07 12:31:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>
#include <stack>
#include <iostream>

bool IsNumber(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; i < (int)str.length() ;i++)
	{
		if (str.length() > 1 && i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (std::isdigit(str[i]) == 0)
			return false;
	}
	return true;
}


long	Stoi(std::string str)
{
	int	i = 0, res = 0, neg = 1;

	if (!IsNumber(str))
		return std::numeric_limits<long>::min();
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9') {
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}
int main(int argc, char*argv[]) {
	std::stack<float> stck;
	if (argc != 2) {
		std::cerr <<"Error: Usage : ./RPN 'operation'" << std::endl;
		return 1;
	}
	std::istringstream iss(argv[1]);
	std::string token;
	while (iss >> token) {
		long value;
		float temp;
		value = Stoi(token);
		if (value == std::numeric_limits<long>::min()) {
			if (token != "-" && token != "+" && token != "*" && token != "/"){
				std::cerr << "Error: Invalid." << std::endl;
				return 1;
			}
		}
		else {
			stck.push(value);
			continue;
		}
		if (stck.size() < 2) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (token == "+") {
			temp = stck.top();
			stck.pop();
			temp += stck.top();
			stck.pop();
			stck.push(temp);
		}
		else if (token == "-") {
			temp = stck.top();
			stck.pop();
			temp -= stck.top();
			stck.pop();
			stck.push(temp);
		}
		else if (token == "*") {
			temp = stck.top();
			stck.pop();
			temp *= stck.top();
			stck.pop();
			stck.push(temp);
		}
		else if (token == "/") {
			temp = stck.top();
			stck.pop();
			temp /= stck.top();
			stck.pop();
			stck.push(temp);
		}
	}
	if (stck.size() != 1) {
		if (stck.size() > 1)
			std::cerr << "Error" << std::endl;
		else 
			std::cerr << "Error" << std::endl;
		return 1;
	}
	else
		std::cout << stck.top() << std::endl;
	return (0);
}
