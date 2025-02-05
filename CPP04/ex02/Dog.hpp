/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:25:40 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 17:40:17 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
	Brain* brain;

	public:
	Dog();
	Dog(const Dog&);
	~Dog();
	Dog& operator=(const Dog& other);

	void	makeSound() const;

	std::string	getType() const;
	void		setType(std::string type);
	void		setIdea(unsigned int index, std::string idea);
	std::string	getIdea(unsigned int index) const;
};

