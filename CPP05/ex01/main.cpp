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
#include "Form.hpp"

#include <iostream>

int main()
{
	{

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
	}
	{
		std::cout << std::endl << "TEST NUMER 4 " << std::endl;
		Bureaucrat Name4("Name4", 50);
		Form Form1("Pardon", 60,60);
		Form Form2("Pardonette", 40,40);
		try {Name4.signForm(Form1);} 
		catch (std::exception &e) {
			std::cout << "wtf" << std::endl;
		}
		try {Name4.signForm(Form2);} 
		catch (std::exception &e) {
			std::cout << "wtf" << std::endl;
		}
	}
	{
		std::cout << std::endl << "TEST NUMER 5 " << std::endl;
		Bureaucrat Name4("Name4", 50);
		Bureaucrat Name5(Name4);
		Form Form1("Pardon", 60,60);
		Form Form2("Pardonette", 40,40);
		try {Name5.signForm(Form1);} 
		catch (std::exception &e) { }
		try {Name5.signForm(Form2);} 
		catch (std::exception &e) { }
	}
}
