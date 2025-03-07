/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:14:34 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/06 14:26:12 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <errno.h>
#include <cstring>
#include <cstdlib>
class PmergeMe
{
private:
	std::vector<int> vc;
	std::deque<int> dq;
	std::vector<size_t> Jseq;
public:
	PmergeMe();
	PmergeMe(char**,int);
	PmergeMe(const PmergeMe &);
	PmergeMe & operator=(const PmergeMe &);
	~PmergeMe();
	void sort();
	void dequeMergeInertionSort(std::deque<int>& deq);
	void vectorMergeInertionSort(std::vector<int>& vec);
	template <typename T>
	size_t binarySearch(T &container, int value)
	{
		size_t left = 0;
		size_t right = container.size();
		size_t mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (container[mid] == value)
				return mid;
			else if (container[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
	void jacobsthalsequence(int len);
};

#endif