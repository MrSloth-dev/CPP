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

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form {
private:
	std::string const _name;
	bool _signed;
	int	const _minGradeSign;
	int	const _minGradeExec;
public:

	Form(std::string name, int min_grade_sign, int _min_grade_exec);
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

	void	beSigned(const Bureaucrat& B);
};
#endif
