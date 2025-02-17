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
#include <exception>
#include <iostream>

int main(void) {
  {
    Intern Dumb;
    try {
      Form* A = Dumb.makeForm("RobotomyRequestForm", "test1");
      delete A;
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
    try {
      Form* A = Dumb.makeForm("ShrubberyCreationForm", "test2");
      delete A;
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
    try {
      Form* A = Dumb.makeForm("PresidentialPardonForm", "test3");
      delete A;
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
    try {
      Form* A = Dumb.makeForm("Rubberish", "test4");
      delete A;
    } catch (std::exception &e) {
      std::cerr << "Form not found!" << std::endl;
    }
  }
}
