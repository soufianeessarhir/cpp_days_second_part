/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:45:35 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 22:46:31 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}
void RPN::execute(std::stack<int> &st, std::string &_operator)
{
	if (st.size() < 2)
		std::cerr<<"error\n" , exit(1);
	int op1 = st.top();
	st.pop();
	int op2 = st.top();
	st.pop();
	switch (_operator[0])
	{
		case '+':
			st.push(op1 + op2);
			break;
		case '-':
			st.push(op2 - op1);
			break;
		case '*':
			st.push(op1 * op2);
			break;
		case '/':
			if (op1 == 0)
				std::cout<< "devision by zero \n", exit(1);
			st.push(op2 / op1);
			break;	
		default:
			break;
	}
}
void RPN::rpn(std::string expression)
{
	std::stringstream os(expression);
	std::string token;
	while (os >> token)
	{
		if (token == "+" || token == "-" || token == "/" || token == "*")
			execute(st,token);
		else 
		{
			errno = 0;
			char *end;
			int64 value = strtol(token.c_str(),&end,10);
			if (errno || *end || value > 10 || value < 0)
				std::cout<< "incorrect number \n", exit(1);
			else
				st.push(value);
			
		}
	}
	
}