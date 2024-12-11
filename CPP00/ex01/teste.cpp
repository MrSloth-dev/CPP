#include <string>
#include <iostream>
int main()
{
	std::string	name;
	std::string	number;

	std::cout << "Hello ";
	std::getline(std::cin, name);
	std::cout << "number ";
	std::getline(std::cin, number);
	std::cout << name << number;

}
