/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:51:05 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/21 12:59:52 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "Address of string : " << &string << std::endl;
	std::cout << "Address of stringPTR : " << stringPTR << std::endl;
	std::cout << "Address of stringREF : " << &stringREF << std::endl<< std::endl;
	std::cout << "The value of string : " << string << std::endl;
	std::cout << "The value pointed to stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to stringREF : " << stringREF << std::endl;
}
