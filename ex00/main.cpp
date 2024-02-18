/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:32:17 by rrask             #+#    #+#             */
/*   Updated: 2024/02/18 14:30:34 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char **av){
	BitcoinExchange btc;

	try {
		btc.parseFile();
		btc.processData(av[1]);
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
		return (1);
	}
	return 0;
}