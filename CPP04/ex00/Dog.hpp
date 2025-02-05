/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:49:59 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/05 15:50:06 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
	private:
	protected:
	std::string _name;
	public:
	Dog();
	Dog(std::string _name);
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};
