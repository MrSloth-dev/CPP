#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/types.h>

/*
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
	bool parseInput(char** argv);
	void executeVector();
	void executeDeque();

	class NoInput :  public std::exception {
		virtual const char* what() const throw();
	};
	class ErrorException :  public std::exception {
		virtual const char* what() const throw();
	};
}; */

bool PmergeMe::IsNumber(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; i < (int)str.length() ;i++)
	{
		if (str.length() > 1 && i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (std::isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

PmergeMe::PmergeMe(char** argv) : _level(1) , _size(0) {
	if (!this->parseInput(argv))
		throw PmergeMe::InputException();
}
PmergeMe::PmergeMe(const PmergeMe& copy) : _vector(copy._vector), _deque(copy._deque), _level(copy._level), _size(copy._size)  { }

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		this->_vector = copy._vector;
		this->_deque = copy._deque;
		this->_level = copy._level;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printall() {
	std::cout << "Vector" << std::endl;
	print(_vector);
	std::cout << "Deque" << std::endl;
	print(_deque);

}

bool PmergeMe::parseInput(char** argv) {
	++argv;
	while (argv && *argv) {
		if (!IsNumber(*argv))
			return false;
		else {
			int value = std::atoi(*argv);
			if (value < 0)
				return false;
			_vector.push_back(value);
			_deque.push_back(value);
			_size++;
		}
		argv++;
	}
	return true;
}

void PmergeMe::pairUp(std::vector<int> vec, uint level) {
	if (level * 2 > vec.size() / 2)
		return ;
	std::cout << "Vector Level :" << level << " =>";
	level++;
	print(vec);
	uint mid = vec.size() / 2;
	std::vector<int> first(vec.begin(), vec.begin() + level);
	std::cout << "first : ";
	print(first);
	this->pairUp(first, level);
	std::vector<int> second(vec.begin() + mid, vec.end());
	std::cout << "second : ";
	print(second);
	this->pairUp(second, level);
}
void PmergeMe::executeVector() {
	this->pairUp(this->_vector, _level);
}
const char* PmergeMe::InputException::what() const throw() {
	return "Error";
}
