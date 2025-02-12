/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:11:12 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 15:36:23 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <ostream>

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
		virtual ~Form() = 0;

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

		class NotSignedException :  public std::exception {
			virtual const char* what() const throw();
		};
		virtual void	beSigned(const Bureaucrat& B);

		void	execute(const Bureaucrat& executor);
		virtual void Aexecute(void) = 0;
};

std::ostream& operator<<(std::ostream os, const Form&);
