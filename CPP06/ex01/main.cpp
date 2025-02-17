/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 17:37:34 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	std::string str = "Hello, world!";
	Data data;

	std::cout << "Before Serialize(pointer address)" << std::endl;
	std::cout << &data << std::endl;
	std::cout << std::endl << "After Serialize" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;
	std::cout << std::endl << "After deSerialize" << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << deserialized << std::endl;
	if (&data == deserialized)
		std::cout << std::endl << "Great Success!" << std::endl;
	else
		std::cout << std::endl << "Oh no!" << std::endl;

}
