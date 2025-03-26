#include "PmergeMe.hpp"
#include <ctime>
#include <sys/types.h>
#include <utility>
#include <vector>

////CANONICAL FORM
PmergeMe::PmergeMe() {};
PmergeMe::PmergeMe(char** argv) : _level(1) , _size(0) {
	if (!this->parseInput(argv))
		throw PmergeMe::InputException();
	printall();
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

//// PARSING
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
			_original.push_back(value);
			_size++;
		}
		argv++;
	}
	return true;
}

///EXECUTION
clock_t PmergeMe::sortVector(void) {

	if (_vector.size() < 2 || isSorted(_vector)) {
		std::cout << "Sorted!" << std::endl;
		return clock();
	}
	int oddElement = -1;
	if (_vector.size() % 2 == 1){
		oddElement = _vector.back();
		_vector.pop_back();
	}
	std::vector<std::pair<int, int> > _pairs;
	for (std::vector<int>::iterator ite = _vector.begin(); ite != _vector.end(); ite += 2)
		_pairs.push_back(std::make_pair(*ite, *(ite + 1)));

	for (std::vector<std::pair<int, int> >::iterator itep = _pairs.begin(); itep != _pairs.end(); itep++)
		if (itep->first > itep->second)
			std::swap(itep->first, itep->second);
	if (_vector.size() % 2 == 1)
		_pairs.push_back(std::make_pair(oddElement, -1));
	return clock();
};

clock_t PmergeMe::sortDeque(void) {

	return clock();
};

void PmergeMe::execute(void) {
	//timer start
	clock_t startVector = clock();
	//vector start
	clock_t timeVector = this->sortVector() - startVector;
	clock_t startDeque = clock();
	clock_t timeDeque = this->sortDeque() - startDeque;


	std::cout << "Vector time: " << timeVector << std::endl;
	std::cout << "Deque time: "  << timeDeque  << std::endl;
	
	//timer end
	//timer start
	//deque start
	//timer end
}




//// HELPERS
void PmergeMe::printall() {
	std::cout << "Vector" << std::endl;
	print(_vector);
	std::cout << "Deque" << std::endl;
	print(_deque);
	std::cout << "Original" << std::endl;
	print(_original);
}
//// EXCEPTIONS
const char* PmergeMe::InputException::what() const throw() {
	return "Invalid Input!";
}
