/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:16:57 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/27 16:33:18 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include<algorithm>
class Span
{
private:
	std::vector<int> vect;
	unsigned int size;
	unsigned int capacity;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& oth);
	Span& operator=(const Span& oth);
	~Span();
	void addNumber(unsigned int num);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	template <typename T>
	void addNumber(T begin, T end)
	{
		if (size + std::distance(begin, end) > capacity)
			throw std::out_of_range("span is full there is no place to add any new number");
		for (T it = begin; it != end; ++it)
		{
			this->vect[size] = *it;
			size++;
		}	
	}
};

#endif