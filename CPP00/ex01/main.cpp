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

void	ft_display()
{
	std::cout << " ___________________________________________________ " << std::endl;
	std::cout << "|  Welcome to 90's Phonebook                        |" << std::endl;
	std::cout << "|___________________________________________________|" << std::endl;
	std::cout << "|  1-> Add Contact                                  |" << std::endl;
	std::cout << "|___________________________________________________|" << std::endl;
	std::cout << "|  2-> Search Contact                               |" << std::endl;
	std::cout << "|___________________________________________________|" << std::endl;
	std::cout << "|  3-> View all Contacts                            |" << std::endl;
	std::cout << "|___________________________________________________|" << std::endl;
	std::cout << "|  4-> Exit                                         |" << std::endl;
	std::cout << "|___________________________________________________|" << std::endl;
	std::cout << "Type your option : ";
}

Contact	ft_create_contact()
{
	Contact temp;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;

	std::cout << "Add Contact : "<< std::endl;
	std::cout << std::endl << "First Name : ";
	std::cin >> firstname;
	temp.set_first_name(firstname);
	std::cout << std::endl << "Last Name : ";
	std::cin >> lastname;
	temp.set_last_name(lastname);
	std::cout << std::endl << "Phone Number : ";
	std::cin >> phone;
	temp.set_phone_number(phone);
	std::cout << std::endl << "NickName : ";
	std::cin >> nickname;
	temp.set_nickname(nickname);
	std::cout << std::endl << "Darkest Secret : ";
	std::cin >> secret;
	temp.set_darkest_secret(secret);
	return (temp);
}
int	main()
{
	Phonebook phonebook;
	Contact jao;
	int	option = 1;

	while (1)
	{
		do
		{
			// std::cout << "\033[2J";
			ft_display();
			std::cin >> option;
			if (option == 1)
			{
				Contact temp;
				temp = ft_create_contact();
				phonebook.add(temp);
			}
			if (option == 2)
			{
				std::string temp;
				std::cout << "Search : ";
				std::cin >> temp;
				std::cout << std::endl;
				std::cout << " ______________________________________________________ " << std::endl;
				std::cout << "|  Results found                                       |" << std::endl;
				phonebook.search(temp);
				std::cout << "Press Enter key to continue ..." << std::endl;

			}
			if (option == 3)
			{
				std::string temp;
				std::cout << " _______________________________________________________ " << std::endl;
				std::cout << "|  Show all results                                    |" << std::endl;
				std::cout << "|______________________________________________________|" << std::endl;
				std::cout << "Showing all contacts : " << std::endl;
				for (int i = 0; i < 8; i++)
					phonebook.search(phonebook.get_contact(i).get_first_name());

			}
			if (option == 4){std::cout << "Exiting.. Thank you!" << std::endl; return (0);}
		} while (option == 1 || option == 2 || option == 3 || option == 4);
	}
	// jao.set_first_name("Joao");
	// jao.set_last_name("Barbosa");
	// jao.set_phone_number("917325972");
	// phonebook.add(jao);
	// phonebook.search("Joao");

}
