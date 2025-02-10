/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:59:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 16:21:24 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _minGradeSign(72), _minGradeExec(45) {
	std::ofstream File((target + "_shrubbery").c_str(), std::ofstream::out);
	try {File.is_open();}
	catch (std::exception &e) {
		std::cout << "Error: invalid target" << std::endl;
		return;
	}
	this->PrinTree(File);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()), _minGradeSign(copy.getGradeSign()), _minGradeExec(copy.getGradeExec()) {
    std::cout << "Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RIP!" << std::endl;
}
