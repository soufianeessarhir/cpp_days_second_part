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
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <errno.h>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sys/time.h>
class PmergeMe
{
private:
	long long start_parse;
	long long end_parse;
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
	template <typename T>
	T& MergeInertionSort(T& container) 
	{
		if (container.size() <= 1)
		{
			return container;
		}
		T a_values;
		T map(*std::max_element(container.begin(), container.end()) + 1);
		int leftover = -1;
		if (container.size() % 2)
		{
			leftover = container.back();
			container.pop_back();
		}
		for (size_t i = 0; i < container.size(); i += 2)
		{
			int a = std::max(container[i], container[i+1]);
			int b = std::min(container[i], container[i+1]);
			a_values.push_back(a);
			map[a] = b;
		}
		a_values = MergeInertionSort(a_values);
		T b_values = a_values;
		T result;
		if (!b_values.empty())
		{
			result.push_back(map[b_values[0]]);
		}
		for (typename T::const_iterator a_it = a_values.begin(); a_it != a_values.end(); ++a_it)
		{
			result.push_back(*a_it);
		}
		jacobsthalsequence(b_values.size());
		size_t k = 2;
		while (k < Jseq.size() && Jseq[k-1] < b_values.size())
		{
			size_t m = std::min(Jseq[k], (size_t)b_values.size());
			for (size_t i = m; i > Jseq[k-1]; i--)
			{
				if (i-1 < b_values.size()) {
					int element = map[b_values[i-1]];
					typename  T::iterator insertPos = std::lower_bound(result.begin(), result.end(), element);
					result.insert(insertPos, element);
				}
			}
			k++;
		}
		if (leftover != -1) 
		{
			typename  T::iterator insertPos = std::lower_bound(result.begin(), result.end(), leftover);
			result.insert(insertPos, leftover);
		}
		container = result;
		return container;
	}
	void jacobsthalsequence(size_t len);
	long long get_time_in_microseconds();
	template <typename T>
	void print(T& container)
	{
		for (size_t i = 0; i < container.size(); i++)
			std::cout<<container[i]<<" ";
		std::cout<<std::endl;
	}
};

#endif