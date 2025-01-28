/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:21:56 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/23 14:35:42 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return 1;

	std::string OldStr = argv[2];
	std::string NewStr = argv[3];
	std::string FileName = argv[1];
	std::ifstream File(FileName.c_str());
	if (!File.is_open()) {
		std::cout << "Error: invalid input" << std::endl; return 2;
	}
	std::string NewFileName = FileName + ".replace";
	std::ofstream NewFile(NewFileName.c_str(), std::ofstream::out | std::ofstream::app);
	std::string Line;

	if (!NewFile.is_open()) {
		std::cout << "Error: invalid output" << std::endl; return 3;
	}
	if (OldStr.length() == 0) {
		std::cout << "Error: invalid String to be replaced" << std::endl; return 4;
	}
	while (std::getline(File, Line))
	{
		size_t Start = Line.find(OldStr);
		while (Start != Line.npos)
		{
			Line.erase(Start, OldStr.length());
			Line.insert(Start, NewStr);
			Start = Line.find(OldStr);
		}
		NewFile << Line << std::endl; }
	NewFile.close();
	File.close();
}
