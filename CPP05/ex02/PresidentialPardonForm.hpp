/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:07:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/12 11:32:29 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		PresidentialPardonForm();
		void PrinTree(std::ostream& os);
		const std::string _target;
		void	Aexecute();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		std::string getTarget() const;
};
