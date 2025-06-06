/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/24 12:24:17 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	{
		Data data;

		std::cout << std::endl << "Test 1" << std::endl;
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
	{
		std::cout << std::endl << "Test 2" << std::endl;
		Data* data2 = new Data;

		std::cout << "Before Serialize(pointer address)" << std::endl;
		std::cout << data2 << std::endl;
		std::cout << std::endl << "After Serialize" << std::endl;
		uintptr_t raw = Serializer::serialize(data2);
		std::cout << raw << std::endl;
		std::cout << std::endl << "After deSerialize" << std::endl;

		Data* deserialized = Serializer::deserialize(raw);
		std::cout << deserialized << std::endl;
		if (data2 == deserialized)
			std::cout << std::endl << "Great Success!" << std::endl;
		else
			std::cout << std::endl << "Oh no!" << std::endl;

		delete data2;
	}
	{
		std::cout << std::endl << "Test 2" << std::endl;
		Data* data2 = new Data;
		Data* data = new Data;

		std::cout << "Before Serialize(pointer address)" << std::endl;
		std::cout << data2 << std::endl;
		std::cout << std::endl << "After Serialize" << std::endl;
		uintptr_t raw = Serializer::serialize(data2);
		std::cout << raw << std::endl;
		std::cout << std::endl << "After deSerialize" << std::endl;

		Data* deserialized = Serializer::deserialize(raw);
		std::cout << deserialized << std::endl;
		if (data == deserialized)
			std::cout << std::endl << "Great Success!" << std::endl;
		else
			std::cout << std::endl << "Oh no!" << std::endl;

		delete data2;
		delete data;
	}
}
