/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:37:56 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/25 11:58:57 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
template <typename T, typename FUNC>

void iter(T* arr, int length, FUNC func)
{
	for (int i = 0; i < length ;++i)
	{
		func(arr[i]);
	}
}

#endif