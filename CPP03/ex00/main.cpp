/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:43:36 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/29 13:44:29 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	{
		std::string target = "Sandro";
		ClapTrap Joel("Joel");
		Joel.attack(target);
		Joel.beRepaired(2);
		Joel.takeDamage(10);
		Joel.takeDamage(2);
		Joel.attack("Sandro");
	}
	{
		std::string target = "Sandro";
		ClapTrap Joel;
		Joel.attack(target);
		Joel.beRepaired(2);
		Joel.takeDamage(10);
		Joel.takeDamage(2);
		Joel.attack("Sandro");
	}
}
