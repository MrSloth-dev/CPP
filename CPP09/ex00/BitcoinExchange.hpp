
#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>

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

	class NoDatabaseException :  public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidDateException :  public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidValueException :  public std::exception {
		virtual const char* what() const throw();
	};

};

