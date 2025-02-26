/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:16:57 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/26 14:23:36 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
class Span
{
private:
	std::vector<int> vect;
	unsigned int size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& oth);
	Span& operator=(const Span& oth);
	~Span();
};

#endif