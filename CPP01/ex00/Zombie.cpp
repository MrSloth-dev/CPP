#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	this->announce();
};

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " died from hunger..." << std::endl;
};
