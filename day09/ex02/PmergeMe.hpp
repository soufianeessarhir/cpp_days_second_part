/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:14:34 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/05 10:17:41 by sessarhi         ###   ########.fr       */
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
public:
	PmergeMe();
	PmergeMe(char**,int);
	PmergeMe(const PmergeMe &);
	PmergeMe & operator=(const PmergeMe &);
	~PmergeMe();
	void sort();
	template <typename T>
	void RecursiveSortt(T &container)
	{
		int lefover = -1;
		if (container.size() <= 1)
			return;
		if (container.size() % 2 == 1)
		{
			lefover = container.back();
			container.pop_back();
		}
		for(int i = 2; i < container.size(); i *= 2)
		{
			for (int j = i; j < container.size(); j += i)
			{
				if (container[j - 1] < container[j - i / 2 - 1])
				{
					int last = j -1;
					int half = j - i / 2 - 1;
					int iter = i / 2;
					while (iter--)
					{
						std::swap(container[last], container[half]);
						last--;
						half--;
					}
					
				}
			}
		}
	}
	template <typename T>
	void mainandpendgenerator(T &container, int leftover)
	{
		T main;
		T pend;
		
		for(int i = 0; i < container.size(); i += 2)
		{
			main.push_back(container[i]);
			pend.push_back(container[i + 1]);
		}
		if (leftover != -1)
			pend.push_back(leftover);
	}
	
};



#endif