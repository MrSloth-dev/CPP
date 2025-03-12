#pragma once
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <sys/types.h>


class PmergeMe {
	private:
	std::vector<unsigned int> _vector;
	std::deque<unsigned int> _deque;
	PmergeMe();
	public:
	PmergeMe(char** argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();
	bool IsNumber(std::string str);
	bool parseInput(char** argv);
	void executeVector();
	void executeDeque();
	void print() {
		std::cout << "Vector" << std::endl;
		for (std::vector<unsigned int>::iterator ite = _vector.begin(); ite != _vector.end(); ite++)
			std::cout << *ite << std::endl;
		std::cout << "Deque" << std::endl;
		for (std::deque<unsigned int>::iterator ite = _deque.begin(); ite != _deque.end(); ite++)
			std::cout << *ite << std::endl;
		}

	class InputException :  public std::exception {
		virtual const char* what() const throw();
	};
};
