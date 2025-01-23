/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:21:56 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/23 13:00:05 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	(void)argc;
	if (argc < 4)
		return 1;
	std::string old_str = argv[2];
	std::string new_str = argv[3];
	std::string file_name(argv[1]);
	std::ifstream file(argv[1]);
	if (!file.is_open())
		return 2;
	std::string line;
	while (std::getline(file, line))
	{
		size_t start = line.find(old_str);
		while (start != line.npos)
		{
			line.erase(start, old_str.length());
			line.insert(start, new_str);
			start = line.find(old_str);
		}
		std::cout << line << std::endl;
	}
}
