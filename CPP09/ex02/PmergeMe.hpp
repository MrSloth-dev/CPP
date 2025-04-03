#pragma once
#include <ctime>
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <sys/types.h>


class PmergeMe {
	private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::deque<int> _original;
	uint _level;
	uint _size;
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	bool IsNumber(std::string str);
	bool parseInput(char** argv);
	void printall();
	clock_t sortVector(void);
	clock_t sortDeque(void);
  void displayTime(std::string typeContainer, double time);

	public:
	void execute(void);
	~PmergeMe();
	PmergeMe(char** argv);
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
template <typename T>
bool isSorted(const T &container) {
	for (typename T::const_iterator it = container.begin(); it != container.end() - 1; it++)
		if (*it > *(it + 1) )
			return false;
	return true;
}
