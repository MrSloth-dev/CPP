#include "PmergeMe.hpp"

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

PmergeMe::PmergeMe(char** argv) {
	if (!this->parseInput(argv))
		throw PmergeMe::InputException();
}
PmergeMe::PmergeMe(const PmergeMe& copy) : _vector(copy._vector), _deque(copy._deque) { }

PmergeMe::~PmergeMe() {}

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
		}
		argv++;
	}
	return true;
}
const char* PmergeMe::InputException::what() const throw() {
	return "Error";
}
