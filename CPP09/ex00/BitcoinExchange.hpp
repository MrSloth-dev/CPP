
#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>

class BitcoinExchange {
	private:
	static BitcoinExchange* _instance;
	std::map<std::string, float> _DB;
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	BitcoinExchange();
	bool checkDate(std::string date);
	bool checkValue(std::string value);
	public:
	~BitcoinExchange();
	static BitcoinExchange& getInstance();
	bool addLine(std::string value, float fvalue);
	bool checkDatabase();
	bool checkInput();

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

