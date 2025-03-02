/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:45:22 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 22:43:09 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <errno.h>
typedef long long int64;
class RPN
{
private:
	std::stack<int> st;
public:
	RPN();
	~RPN();
	void rpn(std::string expression);
	void execute(std::stack<int> &st, std::string &_operator);
};

#endif
