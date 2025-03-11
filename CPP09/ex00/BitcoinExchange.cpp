
#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>

BitcoinExchange& BitcoinExchange::getInstance() {
	if (_instance == NULL)
		_instance = new BitcoinExchange();
	return *_instance;
}

BitcoinExchange* BitcoinExchange::_instance = NULL;

BitcoinExchange::BitcoinExchange() {
	if (!this->checkDatabase())
		throw BitcoinExchange::InvalidDateException();
	std::string file = "./data.csv";
	std::ifstream input;
	input.open(file.c_str(), std::ios::in);
	std::string line;
	while (std::getline(input, line)) {
		if (line.find(',') == line.npos || line == "date,exchange_rate")
			continue;
		line.replace(line.find(','), 1, " ");
		std::istringstream iss(line);
		std::string dates;
		float value;
		iss >> dates >> value;
		_DB[dates] = value;
	}
}

BitcoinExchange::~BitcoinExchange() {
	delete _instance;
}

bool BitcoinExchange::checkDate(std::string date) {
	char sep1, sep2;
	unsigned int year, month, day;
	std::istringstream iss(date);
	std::string creation = "2009-01-02";
	std::time_t t = time(0);
	std::tm* now = std::localtime(&t);

	if (date.length() != 10)
		return false;

	iss >> year >> sep1 >> month >> sep2 >> day;

	if (sep1 != sep2 || (sep1 != '-' && sep1 != '/'))
		return false;
	if (month == 2) {
		if (year % 4 == 0 && day > 29)
			return false;
		if (year % 4 == 0 && year % 100 == 0 && day > 28)
			return false;
	}
	if (month == 1 || month == 3|| month == 5|| month == 7|| month == 8|| month == 10|| month == 12)
		if (day > 31)
			return false;
	if (month == 4 || month == 6|| month == 9|| month == 11)
		if (day > 30)
			return false;

	std::tm then = {};
	then.tm_year = year - 1900;
	then.tm_mon = month - 1;
	then.tm_mday = day;
	if (date < creation || std::difftime( std::mktime(now), std::mktime(&then)) < 0)
		return false;
	return true;
}


bool BitcoinExchange::checkDatabase() {
	std::string file = "./data.csv";
	std::ifstream input;
	int countLine = 0;
	input.open(file.c_str(), std::ios::in);
	try {
		if (! input.is_open() || input.fail())
			throw BitcoinExchange::NoDatabaseException();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		input.close();
		return false;
	}
	std::string line;
	while (std::getline(input, line)) {
		countLine++;
		if (line.find(',') == line.npos || line == "date,exchange_rate")
			continue;
		line.replace(line.find(','), 1, " ");
		std::istringstream iss(line);
		std::string dates;
		int value;
		std::string remainder;
		iss >> dates >> value;
		try {
		if (!this->checkDate(dates))
			throw BitcoinExchange::InvalidDateException();
		if (value < 0)
			throw BitcoinExchange::InvalidValueException();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			std::cerr << "Error in Database line "<< countLine << " -> " << line << std::endl;
			input.close();
			return false;
		}
	}
	input.close();
	return true;
}

bool BitcoinExchange::checkInput(std::string argv) {
	std::ifstream input;
	std::string line;
	try {
		if (argv.length() < 5
			|| argv.find('.') == argv.npos
			|| argv.substr(argv.find_last_of('.')) != ".txt") {
			std::cerr << "Error: only '.txt' extension is valid." << std::endl;
			return false;
		}
		input.open(argv.c_str(), std::ios::in);
		if (!input.is_open() || input.fail())
			throw BitcoinExchange::NoInputException();
		input.close();
	}
	catch(BitcoinExchange::NoInputException &e) {
		input.close();
		std::cerr << "Error reading Input!" << std::endl;
		return false;

	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Error in Input -> " << line << std::endl;
		input.close();
		return false;
	}
	return true;
}
double BitcoinExchange::getRate(std::string date) {
	if (_DB.find(date) != _DB.end())
		return _DB[date];
	return -1;
	

}
void BitcoinExchange::parseInput(std::string argv) {
	BitcoinExchange& btc = BitcoinExchange::getInstance();
	std::ifstream input;
	std::string line;
	input.open(argv.c_str(), std::ios::in);
	getline(input, line);
	line.erase(std::remove_if(line.begin(), line.end(), std::ptr_fun<int, int>(isspace)), line.end());
	if (line != "date|value") {
		std::cerr << "Error: wrong header." << std::endl;
		return ;
	}
	while (getline(input, line)) {
		if (line.length() == 0 || line == "date | value")
			continue;
		std::istringstream iss(line);
		std::string date;
		std::string sep;
		double value;
		iss >> date >> sep >> value;
		if (checkDate(date) == false)
			std::cerr << "Error: bad input => " << date << std::endl;
		else if (value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cerr << "Error: too large a number." << std::endl;
		else if (btc.getRate(date) != -1) {

			std::cout << date << " => " << value << " = " << value * btc.getRate(date) << std::endl;
		}
			//rate not found
		else {
			std::map<std::string, float>::iterator less = _DB.begin();
			for (std::map<std::string, float>::iterator ite = less; ite != _DB.end(); ++ite) {
				if (ite->first < date)
					less = ite;
				else
					break;
			}
			std::cout << date << " => " << value << " = " << value * less->second << std::endl;
		}

	}
	input.close();
}




// Exceptions

const char* BitcoinExchange::NoDatabaseException::what() const throw() {
	return "Error reading Database!";
}
const char* BitcoinExchange::NoInputException::what() const throw() {
	return "Error reading Input!";
}
const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return "Invalid Date!";
}
const char* BitcoinExchange::InvalidValueException::what() const throw() {
	return "Invalid Value!";
}
