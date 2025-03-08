/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:15:31 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/06 14:36:54 by sessarhi         ###   ########.fr       */
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

void PmergeMe::jacobsthalsequence(size_t len)
{
    Jseq.clear();
    Jseq.push_back(0);
    Jseq.push_back(1);
    size_t i = 2;
    while (Jseq.back() < len)
    {
        Jseq.push_back(Jseq[i-1] + 2*Jseq[i-2]);
        i++;
    }
}




void PmergeMe::sort()
{
	MergeInertionSort(dq);
	for (size_t i = 0; i < dq.size(); i++)
		std::cout<<dq[i]<<" ";
	std::cout<<std::endl;
	MergeInertionSort(vc);
	for (size_t i = 0; i < vc.size(); i++)
		std::cout<<vc[i]<<" ";
	std::cout<<std::endl;
}