/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:11:12 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/08 18:27:11 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int min_grade_sign, int min_grade_exec) : _name(name), _minGradeSign(min_grade_sign), _minGradeExec(min_grade_exec) {
	_signed = false;
	if (_minGradeExec < 1 || _minGradeSign < 1)
		throw GradeTooLowException();
	else if (_minGradeExec > 150 || _minGradeSign > 150)
		throw GradeTooHighException();
	else {
		std::cout << "Hello there, my name is " << name << std::endl;
	}
}

Form::Form(const Form& copy) : _name(copy._name), _minGradeSign(copy._minGradeSign), _minGradeExec(copy._minGradeExec), _signed(copy._signed) {
	*this = copy;
}
Form::~Form() {
	std::cout << this->_name << "Form is out!" << std::endl;
}


// Exceptions
const char* Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade Too High!";
}

void	Form::beSigned(const Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() >= this->getGradeSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}
