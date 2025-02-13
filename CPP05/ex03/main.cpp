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
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <iostream>

int main(void) {
  {
    Intern Dumb;
    try {
      Dumb.makeForm("RobotomyRequestForm", "test1");
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
    try {
      Dumb.makeForm("ShrubberyCreationForm", "test2");
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
    try {
      Dumb.makeForm("PresidentialPardonForm", "test3");
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
    try {
      Dumb.makeForm("Rubberish", "test4");
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
  }
	{
		Bureaucrat Max;
		std::cout << Max << std::endl;
	}
}
