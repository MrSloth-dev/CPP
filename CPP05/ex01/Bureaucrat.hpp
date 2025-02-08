/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:09:27 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/08 19:07:36 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Form.hpp"
#include <exception>
#include <ostream>
#include <string>

#include <iostream>

class Bureaucrat {
	private:
	const std::string _name;
	int _grade;
	public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	int	getGrade() const;
	std::string	getName() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooLowException :  public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooHighException :  public std::exception {
		virtual const char* what() const throw();
	};

	void signForm(Form& F);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
