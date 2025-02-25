/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:12:15 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/25 15:17:10 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int _size;
public:
	Array():arr(NULL),_size(0){}
	~Array(){delete[] arr;}
	Array(unsigned int n):arr(new T[n]()),_size(n){}
	Array(const Array& ar) : arr(new T[ar._size]()), _size(ar._size) {
		for (unsigned int i = 0; i < _size; ++i)
			arr[i] = ar.arr[i];
	}
	Array & operator=(const Array & ar)
	{
		if (this == &ar)
			return *this;
		delete[] arr;
		this->_size = ar._size;
		this->arr = new T[ar._size]();
		for(unsigned int i = 0;i < this->_size ; ++i)
			this->arr[i] = ar.arr[i];
		return *this;
	}
	T & operator[](unsigned int idx)
	{
		if (idx >= _size)
			throw std::out_of_range("trying to access non existing element");
		return arr[idx];
	}
	unsigned int size()const{return this->_size;}
};

#endif