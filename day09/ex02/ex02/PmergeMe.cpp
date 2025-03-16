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
	start_parse = get_time_in_microseconds();
	for (int i = 1; i < size;++i)
	{
		errno = 0;
		value = strtol(arg[i], &end,10);
		if (errno != 0 || *end || value > INT_MAX || value < 0)
			std::cout<<"invalid number\n",exit(1);
		if(std::find(vc.begin(), vc.end(), value) != vc.end())
			std::cout<<"duplicate number\n",exit(1);
		vc.push_back(value);
		dq.push_back(value);
	}
	end_parse = get_time_in_microseconds();
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
	long long start = get_time_in_microseconds();
	std::cout << "before:   ";
	print(vc);
	MergeInertionSort(vc);
	long long end = get_time_in_microseconds();
	long long start2 = get_time_in_microseconds();
	std::cout << "after:    ";
	MergeInertionSort(dq);
	print(dq);
	long long end2 = get_time_in_microseconds();
	std::cout << "Time to process a range of " << vc.size() << " 0 elements with std::vector: " <<  
	static_cast<double>(end_parse - start_parse + end - start) << " us \n";
	std::cout << "Time to process a range of " << vc.size() << " 0 elements with std::deque: " <<
	static_cast<double>(end_parse - start_parse + end2 - start2) << " us \n";
}

long long PmergeMe::get_time_in_microseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
}