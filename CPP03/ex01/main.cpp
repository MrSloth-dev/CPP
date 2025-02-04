/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:43:36 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/30 17:11:37 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "ClapTrap" << std::endl;
		std::string target = "Sandro";
		ClapTrap Joel("Joel");
		Joel.attack(target);
		Joel.beRepaired(2);
		Joel.takeDamage(10);
		Joel.takeDamage(2);
		Joel.attack("Sandro");
	}
	{
		std::cout << std::endl << "ScavTrap" << std::endl;
		std::string target = "Sandro";
		ScavTrap Tony("Tony");
		Tony.attack(target);
		Tony.beRepaired(2);
		Tony.takeDamage(10);
		Tony.takeDamage(2);
		Tony.attack("Sandro");
		Tony.guardGate();
	}
	{
		std::string target = "Sandro";
		std::cout << std::endl << "pointerrr" << std::endl;
		ClapTrap *Tome = new ScavTrap("Tome");
		Tome->attack(target);
		Tome->takeDamage(100);
		delete Tome;
	}
}
