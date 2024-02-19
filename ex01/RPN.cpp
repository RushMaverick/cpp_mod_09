#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

// 2 3 + 8 * 2 - 1
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
			std::cout << val1 << std::endl;
			std::cout << val2 << std::endl;
			break;
		}
	}
}