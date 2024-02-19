/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:20:45 by rrask             #+#    #+#             */
/*   Updated: 2024/02/19 20:06:55 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

int RPN::mathOperator(char ch, int val1, int val2){
	int res;
	switch(ch){
		case '+': {
			res = val1 + val2;
			break;
		}
		case '-': {
			res = std::abs(val1 - val2);
			break;
		}
		case '/': {
			if (val2 == 0){
				std::cout << "Error: Cannot divide by zero." << std::endl;
				exit (EXIT_FAILURE);
			}
			res = val1 / val2;
			break;
		}
		case '*': {
			res = val1 * val2;
			break;
		}
	}
	return res;
}

void RPN::evaluateAndCalculate(std::string &input){
	std::istringstream iss(input);
	std::string token;
	double num;

	while (iss >> token){
		if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1]))){
			num = std::stod(token);
			if (std::abs(num) >= 10){
				std::cout << "Error: Value cannot be more than 9." << std::endl;
				exit (EXIT_FAILURE);
			}
			else {
				_operandStack.push(static_cast<int>(num));
			}
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'){
			if (_operandStack.size() < 2){
				std::cout << "Not enough numbers in stack to calculate." << std::endl;
				exit (EXIT_FAILURE);
			}
				int val1 = _operandStack.top(); _operandStack.pop();
				int val2 = _operandStack.top(); _operandStack.pop();
				int res = mathOperator(token[0], val1, val2);
				_operandStack.push(res);
		}
		else {
			std::cout << "Error: Character " << token[0] << " is invalid." << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	std::cout << "Result is " << _operandStack.top() << std::endl;
	}