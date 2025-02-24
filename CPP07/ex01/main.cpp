/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 00:03:58 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class test {
	private:
	test();
	test(const test& copy);
	test& operator=(const test& other);
	~test();

public:

	static void	addFive(int& num) {
		num += 5;
	}

	static void	upper(std::string& str) {
		for (int i = 0; i < static_cast<int>(str.length()); i++) {
			if (std::islower(str[i]))
				str[i] -= 32;
		}
	}
	static void	Capitalize(std::string& str) {
			if (std::islower(str[0]))
				str[0] -= 32;
				
	}
};

template <typename T>void print(T a) {
	std::cout << a <<std::endl;
}

int main()
{
	{
		int	array[] = {2 , 4, 6, 8, 10};
		::iter(array, 5, test::addFive);
		for (int i = 0; i < 5; i++) {
			std::cout << array[i] << std::endl;
		}

	}
	{
		std::cout << std::endl;
		std::string	array[] = {"hola" , "nuestros", "amigos", "estamos", "felices"};
		::iter(array, 5, test::upper);
		for (int i = 0; i < 5; i++) {
			std::cout << array[i] << std::endl;
		}

	}
	{
		std::cout << std::endl;
		std::string	array[] = {"hola" , "nuestros", "amigos", "estamos", "felices"};
		::iter(array, 5, test::Capitalize);

		for (int i = 0; i < 5; i++) {
			std::cout << array[i] << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::string	array[] = {"hola" , "nuestros", "amigos", "estamos", "felices"};
		::iter(array, 5, ::print<std::string>);
	}
	{
		std::cout << std::endl;
		int	array[] = {2 , 4, 6, 8, 10};
		::iter(array, 5, test::addFive);
		::iter(array, 5, ::print<int>);

	}
}
