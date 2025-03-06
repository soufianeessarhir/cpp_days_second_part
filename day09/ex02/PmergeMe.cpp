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

void PmergeMe::dequeMergeInertionSort(std::deque<int> deq)
{
	if (deq.size() <= 1)
		return;
	std::deque<std::pair<int,int> > pairs;
	int leftover = -1;
	if (deq.size() % 2)
	{
		leftover = deq.back();
		deq.pop_back();
	}
	
	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i + 1],deq[i]));
		else
			pairs.push_back(std::make_pair(deq[i],deq[i + 1]));
	}
	std::deque<int> largeelements;
	std::deque<int> smallerelements;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		largeelements.push_back(pairs[i].second);
		smallerelements.push_back(pairs[i].first);
	}
	
	dequeMergeInertionSort(largeelements);
	for(size_t i = 0; i < largeelements.size(); i++)
	{
		for(size_t j = 0; i < pairs.size(); j++)
		{
			if (largeelements[i] == pairs[j].second)
				smallerelements.push_back(pairs[j].first);
		}
	}
}
void PmergeMe::vectorMergeInertionSort(std::vector<int> deq)
{
	if (deq.size() <= 1)
		return;
	std::vector<std::pair<int,int> > pairs;
	int leftover = -1;
	if (deq.size() % 2)
	{
		leftover = deq.back();
		deq.pop_back();
	}
	
	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i + 1],deq[i]));
		else
			pairs.push_back(std::make_pair(deq[i],deq[i + 1]));
	}
	std::vector<int> largeelements;
	std::vector<int> smallerelements;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		largeelements.push_back(pairs[i].second);
		smallerelements.push_back(pairs[i].first);
	}
	
	vectorMergeInertionSort(largeelements);
	for(size_t i = 0; i < largeelements.size(); i++)
	{
		for(size_t j = 0; i < pairs.size(); j++)
		{
			if (largeelements[i] == pairs[j].second)
				smallerelements.push_back(pairs[j].first);
		}
	}
}