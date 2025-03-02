/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:35:22 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 19:41:56 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>

void execute(std::stack<int> &st, std::string &_operator)
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
			st.push(op1 - op2);
			break;
		case '*':
			st.push(op1 * op2);
			break;
		case '/':
			st.push(op1 / op2);
			break;
		default:
			break;
	}
}
void rpn(std::string expression)
{
	std::stringstream os(expression);
	std::stack<int> st;
	std::string token;
	while (os >> token)
	{
		if (token == "+" || token == "-" || token == "/" || token == "*")
			execute(st,token);
		else 
		{
			
		}
	}
	
}
int main(int ac, char **av)
{
	if (ac != 2)
		return std::cout<< "incorrect number of arguments\n",1;
	rpn(av[1]);
}