/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:11:12 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/08 18:27:11 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


AForm::AForm(std::string const name, int const min_grade_sign, int const min_grade_exec) : _name(name), _signed(false), _minGradeSign(min_grade_sign), _minGradeExec(min_grade_exec) {
	if (_minGradeExec < 1 || _minGradeSign < 1)
		throw GradeTooLowException();
	else if (_minGradeExec > 150 || _minGradeSign > 150)
		throw GradeTooHighException();
	else {
		std::cout << "I'm a Form and my target is " << name << std::endl;
	}
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed) , _minGradeSign(copy._minGradeSign), _minGradeExec(copy._minGradeExec){
	*this = copy;
}

//Operators
AForm & AForm::operator=(const AForm& other) {
	this->_signed = other._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& F) {
	os << "Name: " << F.getName() << std::endl;
	os << "Minimum Grade Sign: " << F.getGradeSign() << std::endl;
	os << "Minimum Grade Exec: " << F.getGradeExec() << std::endl;
	os << "Signed: " << F.getSigned() << std::endl;
	return os;
}

AForm::~AForm() {
	std::cout << this->_name << ", the AForm is out!" << std::endl;
}
// Geters
std::string AForm::getName(void) const {
	return this->_name;
}

bool AForm::getSigned(void) const {
	return this->_signed;
}

int	AForm::getGradeSign(void) const {
	return this->_minGradeSign;
}

int	AForm::getGradeExec(void) const {
	return this->_minGradeExec;
}
// Exceptions
const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade Too High!";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not Signed!";
}

//Methods
void	AForm::beSigned(const Bureaucrat& B) {
	if (B.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(const Bureaucrat& executor) {
	if (this->getSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > this->_minGradeExec)
		throw Bureaucrat::GradeTooLowException();
	else {
		try {this->Aexecute();}
		catch(std::exception &e) {}
	}
}

