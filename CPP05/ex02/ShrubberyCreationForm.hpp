/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:59:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 16:55:06 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class ShrubberyCreationForm: public AForm {
	private:
		ShrubberyCreationForm();
		void PrinTree(std::ostream& os);
	const std::string target;
	protected:
		int const _minGradeSign;
		int const _minGradeExec;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void	execute(Bureaucrat const & executor);
};
