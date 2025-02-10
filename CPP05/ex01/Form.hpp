/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:11:12 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/08 19:07:23 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;
class Form {
private:
	Form();
	std::string const _name;
	bool _signed;
	int	const _minGradeSign;
	int	const _minGradeExec;
public:
	Form(std::string const name, int const min_grade_sign, int const min_grade_exec);
	Form(const Form& copy);
	Form& operator=(const Form& other);
	~Form();

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;

	class GradeTooLowException :  public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooHighException :  public std::exception {
		virtual const char* what() const throw();
	};

	void	beSigned(Bureaucrat& B);
};

std::ostream& operator<<(std::ostream os, const Form&);
