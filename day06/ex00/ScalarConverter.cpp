/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:35:54 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 09:47:29 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter & scal)
{
	(void)scal;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & scal)
{
	(void)scal;
	return *this;
}
// ScalarConverter::~ScalarConverter()
// {
// }
bool ScalarConverter::IsInt(std::string val)
{
	std::string::iterator it = val.begin();
	if (*it == '-')
		it++;
	for(; it != val.end();it++)
		if (!isdigit(*it))
		return false;
	return !val.empty();
}

bool ScalarConverter::IsFloat(std::string val)
{
	bool point = false;
	if (*(val.end()) != 'f')
		return false;
	std::string::iterator it = val.begin();
	if (*it == '-')
		it++;
	if(*it == '.')
	{
		point = true;
		it++;
	}
	for(;it != val.end() - 1;it++)
	{
		if (!isdigit(*it))
		{
			if (*it == '.' && point == false)
				point = true;
			else
				return false;
		}
	}
	return !val.empty();
}
bool ScalarConverter::IsDouble(std::string val)
{
	bool point = false;
	std::string::iterator it = val.begin();
	if (*it == '-')
		it++;
	if(*it == '.')
	{
		point = true;
		it++;
	}
	for(;it != val.end();it++)
	{
		if (!isdigit(*it))
		{
			if (*it == '.' && point == false)
				point = true;
			else
				return false;
		}
	}
	return !val.empty();
}

void ScalarConverter::convert(std::string val)
{
	if(val.length() == 1)
	{
		int a = atoi(val.c_str());
		if (isprint(val[0]))
			std::cout<<"char: " <<static_cast <char>(a)<< std::endl;
		else
			std::cout<<"char: Non displayable\n";
		std::cout<<"int: " <<static_cast <int>(a)<< std::endl;
		std::cout<<"float: " <<static_cast <float>(a)<< std::endl;
		std::cout<<"double: " <<static_cast <double>(a)<< std::endl;
	}
	else if (IsInt(val))
	{
		errno = 0;
		char *invalid;
		long var = strtol(val.c_str(),&invalid,10);
		if (errno == ERANGE ||  var > INT_MAX || var < INT_MIN)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return ;
		}
		if (isprint(val[0]))
			std::cout<<"char: " <<static_cast <char>(var)<< std::endl;
		else
			std::cout<<"char: Non displayable\n";
		std::cout<<"int: " <<static_cast <int>(var)<< std::endl;
		std::cout<<"float: " <<static_cast <float>(var)<< std::endl;
		std::cout<<"double: " <<static_cast <double>(var)<< std::endl;
	}
	else if (IsFloat(val))
	{
		float num = atof(val.c_str());
		if (std::isinf(num) || std::isnan(num))
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		}
		else 
		{
			int toint = num;
			if (isprint(toint))
				std::cout<<"char: " <<static_cast <char>(toint)<< std::endl;
			else
				std::cout<<"char: Non displayable\n";
		}
		std::cout<<"int: " <<static_cast <int>(num)<< std::endl;
		std::cout<<"float: " <<static_cast <float>(num)<< std::endl;
		std::cout<<"double: " <<static_cast <double>(num)<< std::endl;
	}
	else if(IsDouble(val))
	{
		double num = strtod(val.c_str(), NULL);
		if (std::isinf(num) || std::isnan(num))
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		}
		else 
		{
			int toint = num;
			if (isprint(toint))
				std::cout<<"char: " <<static_cast <char>(toint)<< std::endl;
			else
				std::cout<<"char: Non displayable\n";
		}
		std::cout<<"int: " <<static_cast <int>(num)<< std::endl;
		std::cout<<"float: " <<static_cast <float>(num)<< std::endl;
		std::cout<<"double: " <<static_cast <double>(num)<< std::endl;
	}
	else if (val == "-inf" || val == "inf" || val == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << val + "f\n";
		std::cout << "float: " << val + "\n";
	}
	else if (val == "-inff" || val == "inff" || val == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << val.erase(3,1) <<std::endl;
		std::cout << "float: " << val + "\n";
	}
	else
		std::cout << "incorrect input\n";
	
}