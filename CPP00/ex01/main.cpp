/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:59:34 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/12 17:14:26 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


bool	getPrompt(std::string msg, std::string &var)
{
	std::cout << msg;
	std::getline(std::cin, var);
	if (std::cin.eof() || std::cin.fail() )
	{
		std::cout << std::endl <<"You pressed Ctrl + D, Program is Quitting" << std::endl;
		return false;
	}
	std::cout << std::endl;
	return true;
}

Contact	ft_create_contact()
{
	Contact temp;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
	std::cout << "Please enter contact details : "<< std::endl;
	getPrompt("First Name : ", firstname);
	if (firstname.length() == 0)
		return temp;
	getPrompt("Last Name : ", lastname);
	if (lastname.length() == 0)
		return temp;
	while (getPrompt("Phone Number : ", phone) && ((isNumber(phone) == 0 || phone.length() != 9))) {
		std::cout << "Phone number not valid. Must have 9 digits"<< std::endl;
		sleep(1);
		std::cout << "Please try again."<< std::endl;
		sleep(1);
	}
	if (phone.length() == 0)
		return temp;
	getPrompt("NickName : ", nickname);
	if (nickname.length() == 0)
		return temp;
	getPrompt("Darkest Secret : ", secret);
	if (secret.length() == 0)
		return temp;
	temp.set_first_name(firstname);
	temp.set_last_name(lastname);
	temp.set_phone_number(phone);
	temp.set_nickname(nickname);
	temp.set_darkest_secret(secret);
	return (temp);
}

int	main()
{
	Phonebook phonebook;

	handleSignal();
	std::cout << "\033[2J\033[H";
	std::string input;
	while (1)
	{
		do
		{
			ft_display();
			if (!getPrompt("Type your option : ", input))
				break;
			if (std::cin.fail()){
				std::cout << "Invalid input. Please enter ADD, SEARCH or EXIT" << std::endl, sleep(1);
				continue;
			}
			else if (input == "ADD")
			{
				Contact temp;
				temp = ft_create_contact();
				if (!std::cin.eof() && temp.get_first_name().length() == 0) {
					std::cout << "All contact field must be filled" << std::endl;
					continue;
				}
				phonebook.add(temp);
			}
			else if (input == "SEARCH")
			{
				std::string temp;
				getPrompt("Search [0 .. 7]: ", temp);
				if (isNumber(temp) == 1 && stoi(temp) < 8 && stoi(temp) >= 0)
				{
					std::cout << "Searching ..." << std::endl;
					phonebook.search(stoi(temp));
				}
				else
					std::cout << "Invalid Index, choose between 0 and 7" << std::endl;
			}
			else if (input == "EXIT")
				break ;
			else
				std::cout << "Invalid input." << std::endl, sleep(1);
		} while (input != "EXIT" && !std::cin.eof());
		std::cout << "Exiting.. Thank you!" << std::endl; return (0);
	}
}
