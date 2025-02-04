/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:26:58 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/04 11:09:22 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #pragma once
#include <string>
#include "ICharacter.hpp"
class AMateria
{
protected:
	std::string _type;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	~AMateria();
	AMateria& operator=(const AMateria& other);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
}; */

#include "AMateria.hpp"
#include <iostream>
AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria const" << std::endl;
};

AMateria::AMateria(const AMateria& other) {
	*this = other;
	this->_type = other._type;
}

AMateria::~AMateria() {
	std::cout << "AMateria destru" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
}
std::string const & AMateria::getType() const {
	return this->_type;
}
AMateria* AMateria::clone() const {
	return new AMateria(this->_type);
}
