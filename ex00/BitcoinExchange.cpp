/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:31:56 by rrask             #+#    #+#             */
/*   Updated: 2024/02/18 15:02:52 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

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
	}
	std::istringstream ls(line);
	std::string dateStr;
	double value;

	std::cout << line << std::endl;
	getline(ls, dateStr, '|');
	//for each iteration of line, check if the date is valid.
	std::cout << line << std::endl;
	std::cout << dateStr << std::endl;
	//Check validity of input file.
	//Take data from _database 
}

const char* BitcoinExchange::failedToOpen::what() const throw() {
	return "Error: could not open file";
}

const char* BitcoinExchange::invalidDataHeader::what() const throw() {
	return "Error: Data header in input.txt is invalid.";
}

