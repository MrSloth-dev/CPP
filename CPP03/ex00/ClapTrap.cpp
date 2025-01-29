
#include "ClapTrap.hpp"

#include <iostream>
void	ClapTrap::takeDamage(uint amount) {

}

void	ClapTrap::beRepaired(uint amount) {

}

void	ClapTrap::attack(const std::string& target) {


	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->AD << " points of damage!" << std::endl;
}

