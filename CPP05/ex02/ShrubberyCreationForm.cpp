/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:59:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 16:33:58 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <ostream>

void ShrubberyCreationForm::PrinTree(std::ostream& os) {
    int height = 20;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            os << " ";
        }
        for (int k = 0; k < 2 * i + 1; ++k) {
            os << "*";
        }
        os << std::endl;
    }
    for (int i = 0; i < height / 3; ++i) {
        for (int j = 0; j < height - 1; ++j) {
            os << " ";
        }
        os << "*" << std::endl;
    }
    os << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _minGradeSign(145), _minGradeExec(137) {
	std::ofstream File((target + "_shrubbery").c_str(), std::ofstream::out);
	try {File.is_open();}
	catch (std::exception &e) {
		std::cout << "Error: invalid target" << std::endl;
		return;
	}
	this->PrinTree(File);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), _minGradeSign(copy.getGradeSign()), _minGradeExec(copy.getGradeExec()) {
    std::cout << "Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "RIP!" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) { 
    try {this->beSigned(executor); }
    catch (std::exception &e) {
        std::cerr << executor.getName() << " cannot sign " << this->getName();
    }
}
