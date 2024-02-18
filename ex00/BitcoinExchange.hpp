/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:57:59 by rrask             #+#    #+#             */
/*   Updated: 2024/02/18 21:25:08 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <chrono>

class BitcoinExchange {
	private:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		std::map<std::string, double> _database;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void parseFile();
		void processData(const std::string& inputFile);
		bool isLeapYear(int year);
		int daysInMonth(int year, int month);
		bool validDate(const std::string &dateStr);

	class failedToOpen : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class invalidDataHeader : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif