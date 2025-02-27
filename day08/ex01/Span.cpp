/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:02 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/27 18:00:37 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():size(0),capacity(0)
{
	
}
Span::Span(unsigned int N):vect(N),size(0),capacity(N)
{
	
}

Span::~Span()
{
}
Span::Span(const Span & oth)
{
	*this = oth;
}

Span& Span::operator=(const Span& oth)
{
	
	if (this == &oth)
		return *this;
	this->capacity = oth.capacity;
	this->size = oth.size;
	this->vect = oth.vect;
	return *this;
}
void Span::addNumber(unsigned int num)
{
	if (size < capacity)
	{
		this->vect[size] = num;
		size++;
	}
	else
		throw std::out_of_range("span is full there is no place to add any new number");
}

unsigned int Span::shortestSpan(void)
{
	if (size <= 1)
		throw std::runtime_error("not enough numbers to calculate the shortestspan");	
	int distance;
	distance = vect[1] - vect[0];
	for (size_t i = 1; i < size; i++)
	{
		if (vect[i] - vect[i - 1] < distance)
			distance = vect[i] - vect[i - 1];
	}
	return distance;
}

unsigned int Span::longestSpan(void)
{
	if (size <= 1)
		throw std::runtime_error("not enough numbers to calculate the longest span");
	
	std::vector<int> tmp(vect.begin(), vect.begin() + size);
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	int rem = this->capacity - this->size;
	int dis = std::distance(first,last);
	if (dis > rem)
		throw std::runtime_error("not enough space to insert more numbers");
	for(size_t i = size;i < capacity && first != last;++i,++first)
	{
		vect[i] = *first;
		size++;
	}
	std::cout<<std::endl;
}