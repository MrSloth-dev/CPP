#include "PmergeMe.hpp"
#include <algorithm>
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
void insertPair(std::pair<int, int> temp, std::vector<std::pair<int, int> > &pairs, int index) {
	if (index < 0)
		pairs.insert(pairs.begin(),temp);
	else if (temp.first > pairs[index].first)
		pairs.insert(pairs.begin() + (index + 1), temp);
	else
		insertPair(temp, pairs, index - 1);
}

void sortPairs(std::vector<std::pair<int, int> > &pairs, int index) {
	if (index < 1)
		return ;
	sortPairs(pairs, index - 1);
	std::pair<int, int> temp = pairs[index];
	pairs.erase(pairs.begin() + index);
	insertPair(temp, pairs, index - 1);
}

std::vector<int> createMain(std::vector<std::pair<int, int> > pairs) {
	std::vector<int> temp;
	for (std::vector<std::pair<int, int> >::iterator ite = pairs.begin(); ite != pairs.end(); ite++) {
		if (ite == pairs.begin()) {
			temp.push_back(ite->second);
			temp.push_back(ite->first);
			// temp.push_back(ite->second);
		}
		else {
			temp.push_back(ite->first);
		}
	}
	return temp;
}

std::vector<int> returnJacob(std::vector<std::pair<int, int> > &pairs) {
	std::vector<int> result;
	int max_index = 0;
	int sizePairs = pairs.size();
	int JacobIndexes[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	while (sizePairs >= JacobIndexes[max_index])
		max_index++;
	for (int i = 0; i < sizePairs; i++) {
		int curr = JacobIndexes[i + 1];
		if (sizePairs < curr)
			curr = sizePairs;
		while(curr > JacobIndexes[i])
			result.push_back(curr--);
	}
	return result;
}

clock_t PmergeMe::sortVector(void) {

	if (_vector.size() < 2 || isSorted(_vector)) {
		std::cout << "Sorted!" << std::endl;
		return clock();
	}
	int oddElement = -1;
	bool isOddSize = _vector.size() % 2 == 1;
	if (isOddSize){
		oddElement = _vector.back();
		_vector.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;

	for (std::vector<int>::iterator ite = _vector.begin(); ite != _vector.end(); ite += 2)
		pairs.push_back(std::make_pair(*ite, *(ite + 1)));

	for (std::vector<std::pair<int, int> >::iterator itep = pairs.begin(); itep != pairs.end(); itep++)
		if (itep->first < itep->second)
			std::swap(itep->first, itep->second);
	sortPairs(pairs, pairs.size()- 1);
	std::vector<int> result = createMain(pairs);
	std::vector<int> jacobSeq = returnJacob(pairs);
	if (isOddSize)
		pairs.push_back(std::make_pair(-1 ,oddElement));

	for (std::vector<int>::iterator jacobIte = jacobSeq.begin(); jacobIte != jacobSeq.end(); jacobIte++) {
		std::vector<int>::iterator resultIte = result.begin();
		while(*resultIte < pairs[*jacobIte - 1].second)
			resultIte++;
		result.insert(resultIte,pairs[*jacobIte - 1].second);
	}
	std::cout << "Result" << std::endl;
	print(result);
	std::cout << "Should be" << std::endl;
	std::sort(_original.begin(), _original.end());
	print(_original);
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
	// clock_t startDeque = clock();
	// clock_t timeDeque = this->sortDeque() - startDeque;


	std::cout << "Vector time: " << timeVector << std::endl;
	// std::cout << "Deque time: "  << timeDeque  << std::endl;
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
