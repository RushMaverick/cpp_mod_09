/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:20:53 by rrask             #+#    #+#             */
/*   Updated: 2024/02/19 18:20:57 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cmath>

class RPN {
	private:
		std::stack<int> _operandStack;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	public:
		RPN();
		~RPN();
		void evaluateAndCalculate(std::string &input);
		int mathOperator(char ch, int val1, int val2);
};

#endif

/*
 2 8 * 3 - 6 +
*/