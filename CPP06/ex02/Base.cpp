/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:40:09 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 17:53:39 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <exception>

/* class Base {
	public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
*/

Base::~Base(){}

Base*	generate(void) {
	int rand = std::rand() % 3;
	switch (rand) {
		case 0 : return new A();
		case 1 : return new B();
		case 2 : return new C();
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class is C" << std::endl;
	else
		std::cout << "Class not identifiable" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class is A" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class is B" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class is C" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	std::cout << "Class not identifiable" << std::endl;
}
