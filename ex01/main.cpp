/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:30:02 by rrask             #+#    #+#             */
/*   Updated: 2024/02/19 11:35:24 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char**av){
	RPN calculator;
	if (ac == 2){
		std::string input(av[1]);
		calculator.evaluateAndCalculate(input);
	}
	return 0;
}