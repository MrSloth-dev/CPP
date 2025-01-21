/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:36:44 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 12:41:41 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 10;
	Zombie *ZombieHorde = zombieHorde(N, "Unnamed Zombie");
	delete [] ZombieHorde;
	return (0);

	
}
