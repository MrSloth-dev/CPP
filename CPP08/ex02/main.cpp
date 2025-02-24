/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 17:10:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
	{
	{
		std::cout << std::endl << "Normal iterator" << std::endl;
		MutantStack<int> mutStack;
		mutStack.push(10);
		mutStack.push(20);
		mutStack.push(30);
		mutStack.push(40);
		mutStack.push(50);
		mutStack.push(60);
		for (MutantStack<int>::iterator ite = mutStack.begin(); ite != mutStack.end(); ite++){
			*ite += 1;
			std::cout << *ite << std::endl;
		}
	}
	{
		std::cout << std::endl << "constant iterator" << std::endl;
		MutantStack<int> mutStack;
		mutStack.push(10);
		mutStack.push(20);
		mutStack.push(30);
		mutStack.push(40);
		mutStack.push(50);
		mutStack.push(60);
		for (MutantStack<int>::const_iterator ite = mutStack.cbegin(); ite != mutStack.cend(); ite++) {
			// *ite += 1;
			std::cout << *ite << std::endl;
		}
	}
	{
		std::cout << std::endl << "reverse iterator" << std::endl;
		MutantStack<int> mutStack;
		mutStack.push(10);
		mutStack.push(20);
		mutStack.push(30);
		mutStack.push(40);
		mutStack.push(50);
		mutStack.push(60);
		for (MutantStack<int>::reverse_iterator ite = mutStack.rbegin(); ite != mutStack.rend(); ite++) {
			*ite += 1;
			std::cout << *ite << std::endl;
		}
	}
	{
		std::cout << std::endl << "constante reverse iterator" << std::endl;
		MutantStack<int> mutStack;
		mutStack.push(10);
		mutStack.push(20);
		mutStack.push(30);
		mutStack.push(40);
		mutStack.push(50);
		mutStack.push(60);
		for (MutantStack<int>::const_reverse_iterator ite = mutStack.crbegin(); ite != mutStack.crend(); ite++) {
			// *ite += 1;
			std::cout << *ite << std::endl;
		}
	}
}

