/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:09:24 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/25 11:16:20 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
template <typename T>
T min(T a , T b)
{
	if (a > b)
		return b;
	else 
		return a;
}

template <typename T>

T max(T a , T b)
{
	if (a < b)
		return b;
	else 
		return a;
}

#endif