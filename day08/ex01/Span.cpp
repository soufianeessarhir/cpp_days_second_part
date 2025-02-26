/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:02 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/26 16:52:17 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
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
	std::sort(vect.begin(),vect.end());
	int distance;
	distance = *(vect.begin() + 1) - *(vect.begin());
	for (std::vector<int>::iterator it = vect.begin() + 1;it != vect.end(); ++it)
	{
		if (*it - *(it - 1) < distance)
			distance = *it - *(it - 1);
	}
	return distance;
}

unsigned int Span::longestSpan(void)
{
	if (size <= 1)
		throw std::runtime_error("not enough numbers to calculate the longestspan");
	std::sort(vect.begin(),vect.end());
	return (*(vect.rbegin()) - *(vect.begin()));
}