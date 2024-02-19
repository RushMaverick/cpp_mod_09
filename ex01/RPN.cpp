/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:20:45 by rrask             #+#    #+#             */
/*   Updated: 2024/02/19 18:34:46 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

// static int stackPeek(std::stack<int> _operandStack){
// 	int valInStack1;
// 	int valInStack2;
// 	try {
// 		int valInStack1 = _operandStack.top(); _operandStack.pop();
// 	}
// 	catch (std::exception &e){
// 		std::cout << e.what() << std::endl;
// 	}
// 	try {
// 		int valInStack2 = _operandStack.top(); _operandStack.pop();
// 	}
// 	catch (std::exception &e){
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << valInStack2 << std::endl;
// 	if (valInStack1 && valInStack2)
// 		return 1;
// 	else
// 		return 0;
// }

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
			if (val2 == 0)
				throw std::out_of_range("Error: Value out of range.");
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

// void RPN::evaluateAndCalculate(std::string &input){
// 	std::istringstream iss(input);
// 	std::string token;
// 	char ch;
// 	while (iss >> ch){
// 		if (ch >= '0' && ch <= '9'){
// 			int num = ch - '0';
// 			_operandStack.push(num);
// 		}
// 		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
// 			if (_operandStack.size() < 2){
// 				std::cout << "Not enough numbers in stack to calculate." << std::endl;
// 				exit (EXIT_FAILURE);
// 			}
// 			int val1 = _operandStack.top(); _operandStack.pop();
// 			int val2 = _operandStack.top(); _operandStack.pop();
// 			int res = mathOperator(ch, val1, val2);
// 			_operandStack.push(res);
// 			std::cout << res << std::endl;
// 		}
// 		else {
// 			std::cout << "Invalid character." << std::endl;
// 			exit (EXIT_FAILURE);
// 		}
// 	}
// }

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
		else if (token[0] == '+'){
			if (_operandStack.size() < 2){
				std::cout << "Not enough numbers in stack to calculate." << std::endl;
				exit (EXIT_FAILURE);
			}
				int val1 = _operandStack.top(); _operandStack.pop();
				int val2 = _operandStack.top(); _operandStack.pop();
				int res = mathOperator(token[0], val1, val2);
				_operandStack.push(res);
				std::cout << res << std::endl;
		}
	}
	}