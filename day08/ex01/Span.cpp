/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:02 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/26 15:18:32 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	
}
Span::Span(unsigned int N):vect(N),size(N)
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
	this->size = oth.size;
	this->vect = oth.vect;
	return *this;
}
