#include "Weapon.hpp"


void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string Weapon::getType() const
{
	return (this->_type);
}

Weapon& Weapon::operator=(const Weapon &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}
