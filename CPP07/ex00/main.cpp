/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:49:13 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 23:17:20 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	{
		std::cout << std::endl << "Test 1" << std::endl;
		int a = 10;
		int b = 20;

		::swap(a, b);
		std::cout << a << " " << b << std::endl;
	}
	{
		std::cout << std::endl << "Test 2" << std::endl;
		std::string x = ", World!";
		std::string y = "Hello";
		::swap(x, y);

		std::cout << x + y << std::endl;
	}
	{
		std::cout << std::endl << "Test 3" << std::endl;
		std::string y = "Hallo";
		::swap(y[1], y[4]);

		std::cout << y << std::endl;
	}
	{
		int a = 10;
		int b = 20;
		std::cout << std::endl << "Test 4" << std::endl;
		std::cout << ::max(a, b) << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << ", b is " << b  << std::endl;
	}
	{
		int a = 10;
		int b = 20;
		std::cout << std::endl << "Test 5" << std::endl;
		std::cout << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << ", b is " << b  << std::endl;
	}
	{
		std::cout << std::endl << "Test 6" << std::endl;
		std::cout << ::min("hello", "helllo") << std::endl;
		std::cout << ::max("hello", "helllo") << std::endl;
		std::cout << ::max("a", "A") << std::endl;
		std::cout << ::min("z", "Z") << std::endl;
	}
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
}
