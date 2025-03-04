
#include "BitcoinExchange.hpp"
#include <sstream>

#include <ctime>
/*
class BitcoinExchange {
	private:
	static BitcoinExchange* _instance;
	std::map<std::string, float> _map;
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	BitcoinExchange();
	public:
	~BitcoinExchange();
	static BitcoinExchange& getInstance();
	bool checkDate(std::string date);
	bool checkValue(std::string value);
	bool addLine(std::string value, float fvalue);

	class InvalidDateException :  public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidValueException :  public std::exception {
		virtual const char* what() const throw();
	};

};
*/

BitcoinExchange& BitcoinExchange::getInstance() {
	if (_instance == NULL)
		_instance = new BitcoinExchange();
	return *_instance;
}
BitcoinExchange* BitcoinExchange::_instance = NULL;

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::~BitcoinExchange() {
	delete _instance;
}

bool BitcoinExchange::checkDate(std::string date) {
	std::string creation = "2009-01-02";
	std::time_t t = time(0);
	std::tm* now = std::localtime(&t);
	char sep1;
	char sep2;
	unsigned int year, month, day;
	std::istringstream iss(date);
	iss >> year >> sep1 >> month >> sep2 >> day;
	std::tm then = {};
	then.tm_year = year - 1900;
	then.tm_mon = month - 1;
	then.tm_mday = day;
	if (date < creation || std::difftime( std::mktime(now), std::mktime(&then)) < 0)
		return false;
	if (sep1 != sep2 || (sep1 != '-' && sep1 != '/'))
		return false;
	return true;
}




const char* BitcoinExchange::NoDatabaseException::what() const throw() {
	return "Error reading Database!";
}
const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return "Invalid Date!";
}
const char* BitcoinExchange::InvalidValueException::what() const throw() {
	return "Invalid Value!";
}
