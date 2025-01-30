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
	std::string target = "Sandro";
	ClapTrap Joel("Joel");
	ScavTrap tony("tony");
	Joel.attack(target);
	Joel.beRepaired(2);
	Joel.takeDamage(10);
	Joel.takeDamage(2);
	Joel.attack("Sandro");
}
