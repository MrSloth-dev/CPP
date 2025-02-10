/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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

class Bureaucrat;
class AForm {
	private:
		AForm();
		std::string const _name;
		bool _signed;
		int	const _minGradeSign;
		int	const _minGradeExec;
	public:
		AForm(std::string const name, int const min_grade_sign, int const min_grade_exec);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;

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

		void	beSigned(const Bureaucrat& B);
};

std::ostream& operator<<(std::ostream os, const AForm&);
