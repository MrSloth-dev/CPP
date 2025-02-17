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

#include "Base.hpp"

class D : public Base { } ;

int main()
{
	std::srand(time(0));
	Base* class1 = generate();
	identify(class1);
	identify(*class1);
	Base* class2 = generate();
	identify(class2);
	identify(*class2);
	Base* class3 = generate();
	identify(class3);
	identify(*class3);
	Base* class4 = generate();
	identify(class4);
	identify(*class4);
	Base* class5 = new D();
	identify(class5);
	identify(class5);
	delete class1;
	delete class2;
	delete class3;
	delete class4;
	delete class5;
}
