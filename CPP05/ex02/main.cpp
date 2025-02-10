/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:07:28 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 16:34:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main()
{
	/* {

		std::cout << std::endl << "TEST NUMER 1 " << std::endl;
		Bureaucrat Name1("Name1", 150);
		std::cout << Name1 <<std::endl;
		try {Name1.decrementGrade();}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{

		std::cout << std::endl << "TEST NUMER 2 " << std::endl;
		Bureaucrat Name2("Name2", 1);
		std::cout << Name2 <<std::endl;
		try {Name2.incrementGrade();}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST NUMER 3 " << std::endl;
		Bureaucrat Name1("Name1", 150);
		Bureaucrat Name3;
		std::cout << Name3 << std::endl;
		Name3 = Name1;
		std::cout << Name3 << std::endl;
		try {Name3.decrementGrade(); }
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << Name3 << std::endl;
		try {Name3.decrementGrade(); }
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	} */
	{
		std::cout << std::endl << "TEST NUMER 4 " << std::endl;
		ShrubberyCreationForm("hey");
	}
}
