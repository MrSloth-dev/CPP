#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/types.h>
#include <utility>
#include <vector>

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

std::vector<std::pair<int, int> > PmergeMe::pairUp(std::vector<int> vec, uint level) {
	std::vector<std::pair<int, int> > temp;
	(void)level;
	for (uint i = 0; i < vec.size() - 1; i += 2) {
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b) std::swap(a,b);
		temp.push_back(std::make_pair(a,b));
		std::cout << "pair >>" << a << " " << b << std::endl;
	}
	if (vec.size() % 2 == 1) temp.push_back(std::make_pair(vec.back(), -1));
	return temp;
}

std::vector<int> PmergeMe::sortFordJohnson(std::vector<int> vec) {
	if (vec.size() < 2) return vec;
	std::vector<std::pair<int, int> > pairs = this->pairUp(vec, 1);
	std::vector<int> mainS;
	std::vector<int> pendent;
	for (uint i = 0; i < pairs.size() - 1; i++) {
		if (pairs[i].second != -1) {
			mainS.push_back(pairs[i].second);
			pendent.push_back(pairs[i].first);
		}
	}
	if (mainS.size() > 1)
		mainS = sortFordJohnson(mainS);
	return vec;

}

void PmergeMe::executeVector() {
	std::vector<int> temp = this->sortFordJohnson(_vector);
	print(temp);
}
const char* PmergeMe::InputException::what() const throw() {
	return "Error";
}
