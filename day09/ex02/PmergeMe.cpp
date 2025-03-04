/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:15:31 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/04 14:49:01 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(char** arg,int size)
{
	long long value;
	char* end = NULL;
	for (int i = 1; i < size;++i)
	{
		errno = 0;
		value = strtol(arg[i], &end,10);
		if (errno || *end || value < 0)
			std::cout<<"invalid number\n",exit(1);
		vc.push_back(value);
		dq.push_back(value);
	}
}
PmergeMe::PmergeMe(const PmergeMe & rhs)
{
	(void)rhs;
}
PmergeMe & PmergeMe::operator=(const PmergeMe &rhs)
{
	(void)rhs;
	return *this;
}