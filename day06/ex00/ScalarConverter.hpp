/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:34:14 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 10:09:25 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef  SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cerrno>  
#include <climits> 
#include <cmath>
#include <sstream>
#include <iomanip> 

class ScalarConverter
{
private:
	static bool IsInt(std::string val);
	static bool IsFloat(std::string val);
	static bool IsDouble(std::string val);
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& scal);
	ScalarConverter & operator=(const ScalarConverter& scal);
	virtual ~ScalarConverter() = 0;
	static void convert(std::string val);
	static std::string toString(float val);
	static std::string toString(double val);
};

#endif
