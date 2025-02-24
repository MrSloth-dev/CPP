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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <exception>
#include <iostream>

int main(void)
{
	{
		std::cout << std::endl << "TEST NUMER 1 " << std::endl;
		Bureaucrat Bush("bush", 1);
		ShrubberyCreationForm hello("tree");
		Bush.executeForm(hello);
		Bush.signAForm(hello);
		Bush.executeForm(hello);
	}
	{
		std::cout << std::endl << "TEST NUMER 2 " << std::endl;
		Bureaucrat Duck("joni", 1);
		AForm* hello = new ShrubberyCreationForm("pointerHEY");
		Duck.executeForm(*hello);
		delete hello;
	}
	{
		std::cout << std::endl << "TEST NUMER 3 " << std::endl;
		Bureaucrat Obama("Obama", 1);
		Bureaucrat Donald("Donald", 150);
		RobotomyRequestForm hello("Robotomy");

		Obama.signAForm(hello);
		Obama.executeForm(hello);
		Donald.executeForm(hello);
	}
	{
		std::cout << std::endl << "TEST NUMER 4 " << std::endl;
		Bureaucrat Duck("joni", 1);
		AForm* hello = new RobotomyRequestForm("pointerRobotomy");
		Duck.executeForm(*hello);
		delete hello;
	}
	{
		std::cout << std::endl << "TEST NUMER 5 " << std::endl;
		Bureaucrat Obama("Obama", 1);
		Bureaucrat Donald("Donald", 150);
		PresidentialPardonForm hello("PardonMe");

		Donald.signAForm(hello);
		std::cout << std::endl;

		Obama.executeForm(hello);
		std::cout << std::endl;

		Obama.signAForm(hello);
		std::cout << std::endl;

		Donald.executeForm(hello);
		std::cout << std::endl;

		Obama.executeForm(hello);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "TEST NUMER 6 " << std::endl;
		Bureaucrat Obama("Obama", 1);
		Bureaucrat Donald("Donald", 150);
		AForm* hello = new PresidentialPardonForm("pointer_PardonMe");

		Donald.signAForm(*hello);
		std::cout << std::endl;

		Obama.signAForm(*hello);
		std::cout << std::endl;

		Donald.executeForm(*hello);
		std::cout << std::endl;
		Obama.executeForm(*hello);
		std::cout << std::endl;
		delete hello;
	}
	{
		Bureaucrat Donald("Donald", 1);
		ShrubberyCreationForm temp("temporary");
		Donald.executeForm(temp);
	}
}
