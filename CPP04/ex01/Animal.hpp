/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:08:21 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 14:05:02 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>
#include <iostream>

class Animal {
	private:
	protected:
	std::string _type;
	public:
	Animal(void);
	Animal(std::string _name);
	virtual ~Animal();

	Animal&		operator=(const Animal& other);
	std::string	getType() const;
	void		setType(std::string type);
	virtual void	makeSound() const;
};
#endif
