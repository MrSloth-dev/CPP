/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:22:00 by joao-pol          #+#    #+#             */
/*   Updated: 2025/03/07 12:31:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char*argv[]) {
	try {

	if (argc < 2) {
		std::cerr <<"Error: Usage : ./PmergeMe <sequence> <of> <positive> <numbers> " << std::endl;
		return 1;
	}
	PmergeMe pmm(argv);
	pmm.executeVector();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
