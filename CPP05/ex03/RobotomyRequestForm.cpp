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

#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form(target, 72, 45), _target(target) {
  std::cout << "Robotomy Request Created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : Form(copy.getName(), copy.getGradeSign(), copy.getGradeExec()) {
  std::cout << "Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
 std::cout << "Robotomy Request Destroyed" << std::endl;
}
const char* RobotomyRequestForm::RobotomyFailedException::what() const throw() {
	return "Robotomation has failed!";
}

std::string RobotomyRequestForm::getTarget() const {
  return this->_target;
}

void RobotomyRequestForm::Aexecute() {
  srand(time(NULL));
  int chance = rand() % 2;
  if (chance)
    std::cout << this->_target << " has been robotomized" << std::endl;
  else
    throw RobotomyFailedException();
}
