/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:10 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/12 15:48:32 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Form.hpp"
#include <exception>

class Intern {
	public:
	Intern();
	Intern(const Intern& copy);
	~Intern();
	Intern& operator=(const Intern& other);

		class FormNotFound :  public std::exception {
			virtual const char* what() const throw();
		};

	Form* makeForm(std::string form, std::string target);
};
