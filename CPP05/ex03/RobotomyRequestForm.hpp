/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:07:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 16:14:52 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"

class RobotomyRequestForm: public Form {
	private:
		RobotomyRequestForm();
		void PrinTree(std::ostream& os);
		const std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		std::string getTarget() const;
		void	Aexecute();
		class RobotomyFailedException :  public std::exception {
			virtual const char* what() const throw();
		};
};
