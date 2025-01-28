/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:51:05 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 17:02:40 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::string wp = "crude spliked club";
		Weapon club = Weapon(wp);
		HumanB joel("Joel");
		joel.attack();
		joel.setWeapon(club);
		club.setType("some other type of club");
		joel.attack();
	}
	{
		std::string wp = "";
		Weapon club = Weapon(wp);
		HumanB toni("Toni");
		toni.setWeapon(club);
		toni.attack();
		club.setType("some other type of unknown");
		toni.attack();
		club.setType("some another type of unknown");
	}
	return 0;
}
