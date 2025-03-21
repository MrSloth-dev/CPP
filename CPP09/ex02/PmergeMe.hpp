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
	std::vector<int> _vector;
	std::deque<int> _deque;
	uint _level;
	uint _size;
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);

	public:
	PmergeMe(char** argv);
	~PmergeMe();
	bool IsNumber(std::string str);
	std::vector<std::pair<int, int> > pairUp(std::vector<int> vec, uint level);
	bool parseInput(char** argv);
	void executeVector();
	void executeDeque();
	void printall();
	std::vector<int> sortFordJohnson(std::vector<int> vec);

	class InputException :  public std::exception {
		virtual const char* what() const throw();
	};
};

template <typename T>
void print(const T &container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
