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
			// check the bigger one
			res = val1 - val2;
			break;
		}
		case '/': {
			//check for zero
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
	char ch;

	while (iss >> ch){
		if (ch >= '0' && ch <= '9'){
			int num = ch - '0';
			_operandStack.push(num);
			//identify the number and pop to the stack.
		}
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			int val1 = _operandStack.top(); _operandStack.pop();
			int val2 = _operandStack.top(); _operandStack.pop();
			int res = mathOperator(ch, val1, val2);
			_operandStack.push(res);
			std::cout << _operandStack.top() << std::endl;
		}
	}
}