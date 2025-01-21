/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:36:44 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 12:08:36 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *PointerZombie;
	PointerZombie = newZombie("Helder");
	PointerZombie->announce();
	randomChump("Orlando");
	delete PointerZombie;
	return (0);

	
}
