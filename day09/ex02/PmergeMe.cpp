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
	jacobsthalsequence(vc.size());
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

// Generate proper Jacobsthal numbers (t_k sequence in the pseudocode)
void PmergeMe::jacobsthalsequence(size_t len)
{
    Jseq.clear();
    Jseq.push_back(0);
    Jseq.push_back(1);
    
    size_t i = 2;
    while (Jseq.back() < len)
    {
        // Correct Jacobsthal formula: J(n) = J(n-1) + 2*J(n-2)
        Jseq.push_back(Jseq[i-1] + 2*Jseq[i-2]);
        i++;
    }
}
// void PmergeMe::jacobsthalsequence(int len) {
//     Jseq.clear();
//     Jseq.push_back(0);
//     Jseq.push_back(1);
    
//     int i = 2;
//     while (Jseq.back() < len) {
//         Jseq.push_back(Jseq[i-1] + 2*Jseq[i-2]);
//         i++;
//     }
// }

std::deque<int>& PmergeMe::dequeMergeInertionSort(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return deq;
    
    std::deque<std::pair<int, int> > pairs;
    int leftover = -1;
    
    if (deq.size() % 2) {
        leftover = deq.back();
        deq.pop_back();
    }
    
    for (size_t i = 0; i < deq.size(); i += 2) {
        int a = std::max(deq[i], deq[i+1]);
        int b = std::min(deq[i], deq[i+1]);
        pairs.push_back(std::make_pair(a, b));
    }
    
    std::deque<int> a_values;
    for (std::deque<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        a_values.push_back(it->first);
    }
    
    a_values = dequeMergeInertionSort(a_values);
    
    std::deque<int> b_values;
    for (std::deque<int>::const_iterator a_it = a_values.begin(); a_it != a_values.end(); ++a_it) {
        for (std::deque<std::pair<int, int> >::const_iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
            if (pair_it->first == *a_it) {
                b_values.push_back(pair_it->second);
                break;
            }
        }
    }
    
    std::deque<int> result;
    if (!b_values.empty()) {
        result.push_back(b_values[0]);
    }
    for (std::deque<int>::const_iterator a_it = a_values.begin(); a_it != a_values.end(); ++a_it) {
        result.push_back(*a_it);
    }
    
    jacobsthalsequence(b_values.size());
    
    size_t k = 2;
    
    while (k < Jseq.size() && Jseq[k-1] < b_values.size()) {
        size_t m = std::min(Jseq[k], (size_t)b_values.size());
        
        for (size_t i = m; i > Jseq[k-1]; i--) {
            if (i-1 < b_values.size()) {
                int element = b_values[i-1];
                std::deque<int>::iterator insertPos = std::lower_bound(result.begin(), result.end(), element);
                result.insert(insertPos, element);
            }
        }
        
        k++;
    }
    
    if (leftover != -1) {
        std::deque<int>::iterator insertPos = std::lower_bound(result.begin(), result.end(), leftover);
        result.insert(insertPos, leftover);
    }
    
    deq = result;
    return deq;
}

// void PmergeMe::vectorMergeInertionSort(std::vector<int>& vec)
// {
//     if (vec.size() <= 1)
//         return;
	
//     std::vector<std::pair<int, int> > pairs;
//     int leftover = -1;
//     if (vec.size() % 2)
// 	{
//         leftover = vec.back();
//         vec.pop_back();
//     }

//     for (size_t i = 0; i < vec.size(); i += 2)
// 	{
//         if (vec[i] > vec[i + 1])
//             pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
//         else
//             pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
//     }
//     std::vector<int> largeelements;
//     for (size_t i = 0; i < pairs.size(); i++)
//         largeelements.push_back(pairs[i].second);
//     vectorMergeInertionSort(largeelements);
//     std::vector<int> smallerelements;
//     for (size_t i = 0; i < largeelements.size(); i++)
// 	{
//         for (size_t j = 0; j < pairs.size(); j++)
// 		{
//             if (largeelements[i] == pairs[j].second)
// 			{
//                 smallerelements.push_back(pairs[j].first);
//                 break;
//             }
//         }
//     }
//     if (!smallerelements.empty())
// 	{
//         largeelements.insert(largeelements.begin(), smallerelements[0]);
//         smallerelements.erase(smallerelements.begin()); 
//     }
//     for (size_t i = 1; i < Jseq.size() - 1; i++)
// 	{
//         size_t start = Jseq[i - 1];
//         size_t end = Jseq[i];
//         for (size_t j = end; j > start; j--)
// 		{
//             if (j - 1 < smallerelements.size())
// 			{
//                 int element = smallerelements[j - 1];
//                 std::vector<int>::iterator insertPos = std::lower_bound(largeelements.begin(), largeelements.end(), element);
//                 largeelements.insert(insertPos, element);
//             }
//         }
//     }

//     if (leftover != -1)
// 	{
//         std::vector<int>::iterator insertPos = std::lower_bound(largeelements.begin(), largeelements.end(), leftover);
//         largeelements.insert(insertPos, leftover);
//     }
//     vec = largeelements;
// }



void PmergeMe::sort()
{
	dequeMergeInertionSort(dq);
	for (size_t i = 0; i < dq.size(); i++)
		std::cout<<dq[i]<<" ";
	std::cout<<std::endl;
	// vectorMergeInertionSort(vc);
	// for (size_t i = 0; i < vc.size(); i++)
	// 	std::cout<<vc[i]<<" ";
	// std::cout<<std::endl;
}