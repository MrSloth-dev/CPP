/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:06:20 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/08 19:08:34 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#include <iostream>
#include <ostream>

//Constructors and Destructors
Bureaucrat::Bureaucrat(void) :_name("John Doe") {
	this->_grade = 75;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {

	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else {
		_grade = grade;
		std::cout << "Hello there, my name is " << name << std::endl;
	}
}

/**
 * @brief 
 */
Bureaucrat::~Bureaucrat() {
	std::cout << "Byeeee, my name is " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	*this = other;
}



//Getters
int	Bureaucrat::getGrade() const {
	return this->_grade;
}

std::string	Bureaucrat::getName() const {
	return this->_name;
}

//Incrememnt / Decrement

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

//Operators
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur) {
	os << bur.getName() << ", bureaucreate grade " << bur.getGrade() << std::endl;
	return os;
} 

// Exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade Too High!";
}

void	Bureaucrat::signForm(Form& F) const {
	try {F.beSigned(*this);}
	catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << F.getName() << " because "  << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << F.getName() << std::endl;

}

void Bureaucrat::executeForm(Form& form) {
	try {form.execute(*this);}
	catch (Form::NotSignedException &e)
	{
		std::cout << "Cannot execute " << form.getName() << ", because it's not signed!"<<std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " cannot execute " << form.getName() <<std::endl;
	}
}
