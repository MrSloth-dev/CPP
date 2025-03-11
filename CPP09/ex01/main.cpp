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

#include <cctype>
#include <string>
#include <stack>
#include <iostream>
int main(int argc, char*argv[]) {
	std::stack<int> stck;
	if (argc != 2) {
		std::cerr <<"Error: Usage : ./RPN 'operation'" << std::endl;
		return 1;
	}



	return ((void)argc, (void)argv, 0);
}
