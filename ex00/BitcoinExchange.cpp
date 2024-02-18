/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:31:56 by rrask             #+#    #+#             */
/*   Updated: 2024/02/18 21:24:50 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::daysInMonth(int year, int month) {
	static const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days = daysPerMonth[month];
	if (month == 2 && isLeapYear(year)) {
		days++;
	}
	return days;
}

bool BitcoinExchange::validDate(const std::string& dateStr) {
	int year, month, day;
	char dash;
	std::istringstream dateStream(dateStr);
	if (dateStream >> year >> dash >> month >> dash >> day) {
		if (month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth(year, month)) {
			return true;
		}
	}
	return false;
}


void BitcoinExchange::parseFile(){
	std::string line;
	std::ifstream inputFile("data.csv");

	if (!inputFile.is_open())
		throw failedToOpen();

	while (std::getline(inputFile, line)){
		double rate;
		std::string date;
		std::istringstream ls(line);

		if (std::getline(ls, date, ',')){
			ls >> rate;
			if (!ls.fail())
				this->_database[date] = rate;
		} else {
			std::cout << "Wrong format for line: " << line << std::endl;
 		}
	}
	inputFile.close();
}

void BitcoinExchange::processData(const std::string& inputFile){
	std::ifstream input(inputFile.c_str());

	if (!input.is_open())
		throw failedToOpen();

	std::string line;
	bool firstLine = true;
	while (std::getline(input, line)){
		if (firstLine == true){
			firstLine = false;
			if (line != "date | value")
				throw invalidDataHeader();
			continue;
		}

		std::istringstream ls(line);
		std::string dateStr;
		double value;

		if (std::getline(ls, dateStr, '|') && ls >> value){
			if (!validDate(dateStr)){
				std::cout << "Error: invalid date format => " << dateStr << std::endl;
			}
			std::map<std::string, double>::iterator it = this->_database.lower_bound(dateStr);
			if (it == _database.begin() && dateStr < it->first)
				std::cout << "Error: Exhange rate for " << dateStr << " is not valid." << std::endl;
			else {
				if (it != _database.begin() && it->first != dateStr)
					--it;
			}
			if (value < 0)
				std::cout << "Error: Value in not positive." << std::endl;
			else if (value > 1000)
				std::cout << "Error: Value is over bounds." << std::endl;
			else {
				double exchangeRate = it->second;
				double res = value * exchangeRate;
				std::cout << dateStr << " => " << value << " = " << res << std::endl;
			}
		}
		else
			std::cout << "Error: Bad input at: " << line << std::endl;
	}
	input.close();
	// getline(ls, dateStr, '|');
	// //for each iteration of line, check if the date is valid.
	// std::cout << line << std::endl;
	// std::cout << dateStr << std::endl;
	//Check validity of input file.
	//Take data from _database 
}

const char* BitcoinExchange::failedToOpen::what() const throw() {
	return "Error: could not open file";
}

const char* BitcoinExchange::invalidDataHeader::what() const throw() {
	return "Error: Data header in input.txt is invalid.";
}

