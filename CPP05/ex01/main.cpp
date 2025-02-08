/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:07:28 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/06 15:29:22 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
	Bureaucrat Name1("Name1", 150);
	std::cout << Name1 <<std::endl;
	try {Name1.decrementGrade();}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat Name2("Name2", 1);
	std::cout << Name2 <<std::endl;
	try {Name1.incrementGrade();}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat Name3;
	std::cout << Name3 << std::endl;
	Name3 = Name1;
	std::cout << Name3 << std::endl;
	Name3.decrementGrade();
	std::cout << Name3 << std::endl;
	try {Name3.decrementGrade(); }
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
