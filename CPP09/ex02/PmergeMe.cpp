#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <sys/types.h>
#include <utility>
#include <vector>

////CANONICAL FORM
PmergeMe::PmergeMe() {};
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

///EXECUTION Vector
void insertPairVector(std::pair<int, int> temp, std::vector<std::pair<int, int> > &pairs, int index) {
	if (index < 0)
		pairs.insert(pairs.begin(),temp);
	else if (temp.first > pairs[index].first)
		pairs.insert(pairs.begin() + (index + 1), temp);
	else
		insertPairVector(temp, pairs, index - 1);
}

void sortPairsVector(std::vector<std::pair<int, int> > &pairs, int index) {
	if (index < 1)
		return ;
	sortPairsVector(pairs, index - 1);
	std::pair<int, int> temp = pairs[index];
	pairs.erase(pairs.begin() + index);
	insertPairVector(temp, pairs, index - 1);
}

std::vector<int> createMainVector(std::vector<std::pair<int, int> > pairs) {
	std::vector<int> main;
	main.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++) {
			main.push_back(pairs[i].first);
	}
	return main;
}
long jacobIndexes(int i) {return round((pow(2, i + 1) - pow(-1, i)) / 3);}

std::vector<int> JacobVector(int pendSize) {
	std::vector<int> result;
	int max_index = 0;
	while (pendSize > jacobIndexes(max_index))
		max_index++;
	for (int i = 0; i < max_index; i++) {
		int curr = jacobIndexes(i + 1);
		if (pendSize < curr)
			curr = pendSize;

		while(curr > jacobIndexes(i)) {
			result.push_back(curr--);
			if (curr <= 0)
				break;
		}
	}
	return result;
}

clock_t PmergeMe::sortVector(void) {

	if (_vector.size() < 2 || isSorted(_vector)) {
		std::cout << "No operation needed!" << std::endl;
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

	sortPairsVector(pairs, pairs.size()- 1);

	std::vector<int> main = createMainVector(pairs);
	std::vector<int> pend;
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);
	if (isOddSize)
		pend.push_back(oddElement);
	std::vector<int> jacobSeq = JacobVector(pend.size());
	//inserting with binary search
	for (size_t i = 0; i < jacobSeq.size(); i++) {
		size_t pendIndex = jacobSeq[i] - 1;
		if (pendIndex >= 0 && pendIndex < pend.size()) {
			int elementToInsert = pend[pendIndex];
			std::vector<int>::iterator insertPos = std::upper_bound(
				main.begin(),
				main.end(),
				elementToInsert
			);
			main.insert(insertPos, elementToInsert);
		}
	}
	_vector = main;
	return clock();
};
///EXECUTION Deque
void insertPairDeque(std::pair<int, int> temp, std::deque<std::pair<int, int> > &pairs, int index) {
	if (index < 0)
		pairs.insert(pairs.begin(),temp);
	else if (temp.first > pairs[index].first)
		pairs.insert(pairs.begin() + (index + 1), temp);
	else
		insertPairDeque(temp, pairs, index - 1);
}

void sortPairsDeque(std::deque<std::pair<int, int> > &pairs, int index) {
	if (index < 1)
		return ;
	sortPairsDeque(pairs, index - 1);
	std::pair<int, int> temp = pairs[index];
	pairs.erase(pairs.begin() + index);
	insertPairDeque(temp, pairs, index - 1);
}

std::deque<int> createMainDeque(std::deque<std::pair<int, int> > pairs) {
	std::deque<int> main;
	main.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++) {
			main.push_back(pairs[i].first);
	}
	return main;
}

std::deque<int> JacobDeque(int pendSize) {
	std::deque<int> result;
	int max_index = 0;
	while (pendSize > jacobIndexes(max_index))
		max_index++;
	for (int i = 0; i < max_index; i++) {
		int curr = jacobIndexes(i + 1);
		if (pendSize < curr)
			curr = pendSize;

		while(curr > jacobIndexes(i)) {
			result.push_back(curr--);
			if (curr <= 0)
				break;
		}
	}
	return result;
}

clock_t PmergeMe::sortDeque(void) {

	if (_deque.size() < 2 || isSorted(_deque)) {
		std::cout << "No operation needed!" << std::endl;
		return clock();
	}
	int oddElement = -1;
	bool isOddSize = _deque.size() % 2 == 1;
	if (isOddSize){
		oddElement = _deque.back();
		_deque.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (std::deque<int>::iterator ite = _deque.begin(); ite != _deque.end(); ite += 2)
		pairs.push_back(std::make_pair(*ite, *(ite + 1)));

	for (std::deque<std::pair<int, int> >::iterator itep = pairs.begin(); itep != pairs.end(); itep++)
		if (itep->first < itep->second)
			std::swap(itep->first, itep->second);

	sortPairsDeque(pairs, pairs.size()- 1);

	std::deque<int> main = createMainDeque(pairs);
	std::deque<int> pend;
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);
	if (isOddSize)
		pend.push_back(oddElement);
	std::deque<int> jacobSeq = JacobDeque(pend.size());
	//inserting with binary search
	for (size_t i = 0; i < jacobSeq.size(); i++) {
		size_t pendIndex = jacobSeq[i] - 1;
		if (pendIndex >= 0 && pendIndex < pend.size()) {
			int elementToInsert = pend[pendIndex];
			std::deque<int>::iterator insertPos = std::upper_bound(
				main.begin(),
				main.end(),
				elementToInsert
			);
			main.insert(insertPos, elementToInsert);
		}
	}
	_deque = main;
	return clock();
};

void PmergeMe::execute(void) {
	//timer start
	clock_t startVector = clock();
	//vector start
	double timeVector = (this->sortVector() - startVector)/ (double)CLOCKS_PER_SEC;
	clock_t startDeque = clock();
	double timeDeque = (this->sortDeque() - startDeque) / (double)CLOCKS_PER_SEC;
  std::cout << "Before: ";
	print(_original);
  std::cout << "After:  ";
	print(_vector);

	displayTime("vector", timeVector);
	displayTime("deque", timeDeque);
}

//// HELPERS
void PmergeMe::displayTime(std::string typeContainer, double time) {
	std::cout << std::fixed << std::setprecision(6) << "Time to process a range of " << _original.size()
	<< " elements with std::"<< typeContainer<< ": " << time << " s " << std::endl;
}
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
