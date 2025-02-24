/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:02:04 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 13:42:48 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#ifndef  SERIALIZER_CPP
#define SERIALIZER_CPP
#include <iostream>

typedef unsigned long uintptr_t;

typedef struct 
{
	int a;
	float b;
	std::string c;
} Data;
class Serializer
{
private:
	
public:
	Serializer();
	Serializer(const Serializer & Sr);
	Serializer & operator =(const Serializer & sr);
	virtual ~Serializer()= 0;
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	
};




#endif