#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
	private:
		std::stack<int> _operandStack;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	public:
		RPN();
		~RPN();
		void evaluateAndCalculate(std::string &input);
};

#endif

/*
 2 8 * 3 - 6 +
*/