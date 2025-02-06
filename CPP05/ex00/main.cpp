/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:07:28 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/06 15:29:22 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
	Bureaucrat Joao("Joao", 150);
	try {Joao.decrementGrade();}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
