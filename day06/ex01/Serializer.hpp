/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:02:04 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 15:10:37 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#ifndef  SERIALIZER_CPP
#define SERIALIZER_CPP
#include <iostream>

typedef unsigned long uintptr_t;

#include "Data.hpp"
class Serializer
{
private:
	Serializer();
public:
	Serializer(const Serializer & Sr);
	Serializer & operator =(const Serializer & sr);
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	
};

#endif