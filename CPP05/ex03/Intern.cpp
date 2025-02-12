/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:11:26 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/12 16:04:32 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern at your service!" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Copy Intern at your service!" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern quit!" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assign!" << std::endl;
	(void)other;
	return *this;
}

const char* Intern::FormNotFound::what() const throw() {
	return "Form not Found!";
}

Form*	Intern::makeForm(std::string form, std::string target) {
	const int num_forms = 3;
	int	index = -1;
	std::string array[num_forms] = {
		"PresidentialPardonForm",
		"ShrubberyCreationForm",
		"RobotomyRequestForm"
	};
	for (int i = 0; i < num_forms; i++) {
		if (array[i] == form) {
			index = i;
			break;
		}
	}
	if (index != -1)
		std::cout << "Intern creates " << form << std::endl;
	switch (index) {
	case 0: return new ShrubberyCreationForm(target);
	case 1: return new RobotomyRequestForm(target);
	case 2: return new PresidentialPardonForm(target);
	default : throw FormNotFound();
	}
}
