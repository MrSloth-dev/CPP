/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:59:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/12 11:37:55 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form(target, 25, 5), _target(target) {
  std::cout << "Pardon Form Created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : Form(copy.getName(), copy.getGradeSign(), copy.getGradeExec()),
      _target(copy._target) {
  std::cout << "Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "Pardon Form Destroyed" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
  return this->_target;
}

void PresidentialPardonForm::Aexecute() {
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
