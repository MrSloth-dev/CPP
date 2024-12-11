/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:59:34 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/03 10:44:30 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cctype>
#include <string>
#include <sstream>
#include <limits>

void	ft_display()
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|  Welcome to 90's Phonebook                |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|  1-> Add Contact                          |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|  2-> Search Contact                       |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|  3-> View all Contacts                    |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|  4-> Exit                                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "Type your option : ";
}

void	getPrompt(std::string msg, std::string &var)
{
	std::cout << msg;
	std::getline(std::cin, var);
	std::cout << std::endl;
}

Contact	ft_create_contact()
{
	Contact temp;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Add Contact : "<< std::endl;
	getPrompt("First Name : ", firstname);
	temp.set_first_name(firstname);
	getPrompt("Last Name : ", lastname);
	temp.set_last_name(lastname);
	getPrompt("Phone Number : ", phone);
	temp.set_phone_number(phone);
	getPrompt("NickName : ", nickname);
	temp.set_nickname(nickname);
	getPrompt("Darkest Secret : ", secret);
	temp.set_darkest_secret(secret);
	return (temp);
}

int	stoi(std::string & s)
{
	int	i;
	std::istringstream(s) >> i;
	return i;
}
bool isNumber(std::string str)
{
	for (int i = 0; i < (int)str.length() ;i++)
	{
		if (std::isdigit(str[i]) == 0)
			return 0;
	}
	return 1;
}

int	main()
{
	Phonebook phonebook;
	Contact jao;
	int	option = 0;

	while (1)
	{
		do
		{
			// std::cout << "\033[2J";
			ft_display();
			std::cin >> option;
			std::cin.clear();
			if (option == 1)
			{
				Contact temp;
				temp = ft_create_contact();
				phonebook.add(temp);
			}
			else if (option == 2)
			{
				std::string temp;
				getPrompt("Search : ", temp);
				std::cout << "Search : ";
				std::getline(std::cin, temp, '\n');
				std::cout << std::endl;
				std::cout << " ___________________________________________ " << std::endl;
				std::cout << "|  Results found                            |" << std::endl;
				if (isNumber(temp) == 1 && stoi(temp) < 8 && stoi(temp) >= 0)
					phonebook.search(stoi(temp));
				else
					std::cout << "Invalid Index" << std::endl;

			}
			else if (option == 3)
			{
				std::string temp;
				std::cout << " ___________________________________________ " << std::endl;
				std::cout << "|  Show all results                         |" << std::endl;
				std::cout << "|___________________________________________|" << std::endl;
				std::cout << "Showing all contacts : " << std::endl;
				for (int i = 0; i < 8; i++)
					phonebook.search(i);

			}
			else
				std::cout << "Invalid input." << std::endl;
			std::cin.clear();
		} while (option != 4);
		std::cout << "Exiting.. Thank you!" << std::endl; return (0);
	}
	// jao.set_first_name("Joao");
	// jao.set_last_name("Barbosa");
	// jao.set_phone_number("917325972");
	// phonebook.add(jao);
	// phonebook.search("Joao");

}
