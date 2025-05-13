
#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

class BitcoinExchange {
	private:
	std::map<std::string, float> _DB;
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	BitcoinExchange();
	static bool checkDate(std::string date);
	static bool checkValue(std::string value);
	bool addLine(std::string value, float fvalue);
	bool checkDatabase();
	double getRate(std::string date);
	public:
	~BitcoinExchange();
	void printMap();
	static BitcoinExchange& getInstance();
	static bool checkInput(std::string argv);
	void parseInput(std::string argv);

	class NoDatabaseException :  public std::exception {
		virtual const char* what() const throw();
	};
	class NoInputException :  public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidDateException :  public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidValueException :  public std::exception {
		virtual const char* what() const throw();
	};
};

