/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:35:54 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 10:16:19 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cfloat>

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
ScalarConverter::~ScalarConverter()
{
}
bool ScalarConverter::IsInt(std::string val)
{
	std::string::iterator it = val.begin();
	if (*it == '-' && isdigit(*(it + 1)))
		it++;
	for(; it != val.end();it++)
		if (!isdigit(*it))
		return false;
	return !val.empty();
}

bool ScalarConverter::IsFloat(std::string val)
{
    if (val.empty() || val.length() == 1)
        return false;
        
    if (val[val.length() - 1] != 'f' && val[val.length() - 1] != 'F')
        return false;
    std::string numPart = val.substr(0, val.length() - 1);
    bool hasDigit = false;
    bool hasDecimal = false;
    size_t i = 0;
    if (i < numPart.length() && (numPart[i] == '-'  && isdigit(*(numPart.begin() + 1))))
        i++;
    for (; i < numPart.length(); i++) {
        if (isdigit(numPart[i]))
            hasDigit = true;
        else if (numPart[i] == '.' && !hasDecimal)
            hasDecimal = true;
        else
            return false;
    }
    return hasDigit && hasDecimal;
}
bool ScalarConverter::IsDouble(std::string val)
{
	bool point = false;
	std::string::iterator it = val.begin();
	if (*it == '-' && isdigit(*(it + 1)))
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

std::string ScalarConverter::toString(double val)
{
    std::stringstream ss;
    ss << val;
    std::string str = ss.str();
    if (str.find('e') == std::string::npos && str.find('.') == std::string::npos)
        str += ".0";
    return str;
}
std::string ScalarConverter::toString(float val)
{
    std::stringstream ss;
    ss << val;
    std::string str = ss.str();
    if (str.find('e') == std::string::npos && str.find('.') == std::string::npos)
        str += ".0";
    str += "f";
    return str;
}

void ScalarConverter::convert(std::string val)
{
	if (IsInt(val))
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
		if (var >= 0 && var <= 127 )
		{
			if (isprint(static_cast<char>(var)))
				std::cout<<"char: \'" <<static_cast <char>(var)<<"\'"<< std::endl;
			else
				std::cout<<"char: Non displayable\n";
		}
		else
			std::cout<<"char: impossible\n";
		std::cout<<"int: " <<static_cast <int>(var)<< std::endl;
		std::cout<<"float: " << toString(static_cast <float>(var))<< std::endl;
		std::cout<<"double: " << toString(static_cast <double>(var))<< std::endl;
	}
	else if(val.length() == 1)
	{
		if (isprint(val[0]))
			std::cout<<"char: \'" <<static_cast<char>(val[0]) << "\'"<< std::endl;
		else
			std::cout<<"char: Non displayable\n";
		std::cout<<"int: " <<static_cast <int>(val[0])<< std::endl;
		std::cout<<"float: " << toString(static_cast <float>(val[0]))<< std::endl;
		std::cout<<"double: " << toString(static_cast <double>(val[0]))<< std::endl;
	}
	 
	else if (IsFloat(val))
	{
		char *invalid;
		errno = 0;
		double num = strtod(val.c_str(),&invalid);
		if (errno == ERANGE || num > FLT_MAX || num < -FLT_MAX)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return ;
		}
		if (std::isinf(num) || std::isnan(num))
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		}
		else 
		{
			int toint = num;
			if (toint >= 0 && toint <= 127)
			{
				if (isprint(static_cast<char>(toint)))
				{
					std::cout<<"char: \'" <<static_cast <char>(toint)<<"\'"<< std::endl;
				}
				else
					std::cout<<"char: Non displayable\n";
			}
			else
				std::cout<<"char: impossible\n";
			
		}
		if (num <= INT_MAX && num >= INT_MIN)
			std::cout<<"int: " <<static_cast <int>(num)<< std::endl;
		else
			std::cout<<"int: impossible\n";
		std::cout<<"float: " <<toString(num)<< std::endl;
		std::cout<<"double: " <<toString(static_cast <double>(num))<< std::endl;
	}	
	else if(IsDouble(val))
	{
		char *invalid;
		errno = 0;
		double num = strtod(val.c_str(), &invalid);
		if (errno == ERANGE)
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return ;
		}
		if (std::isinf(num) || std::isnan(num))
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		}
		else if (num <= INT_MAX && num >= INT_MIN)
		{
			int toint = num;
			if (toint >= 0 && toint <= 127)
			{
				if (isprint(static_cast<char>(toint)))
					std::cout<<"char: \'" <<static_cast <char>(toint)<<"\'"<< std::endl;
				else
					std::cout<<"char: Non displayable\n";
			}
			else
				std::cout<<"char: impossible\n";
			
			std::cout<<"int: " <<static_cast <int>(num)<< std::endl;
		}
		else
		{
			std::cout<<"char: impossible\n";
			std::cout<<"int: impossible\n";
		}
		if (num <= FLT_MAX && num >= -FLT_MAX)
			std::cout<<"float: " <<toString(static_cast <float>(num))<< std::endl;
		else
			std::cout<<"float: impossible\n";
		std::cout<<"double: " <<toString(num)<< std::endl;
	}
	else if (val == "-inf" || val == "inf" || val == "+inf" || val == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << val + "f\n";
		std::cout << "double: " << val + "\n";
	}
	else if (val == "-inff" || val == "inff" || val == "+inff" || val == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << val << "\n"; 
		std::cout << "double: " << val.erase(3,1) << "\n";
	}
	else
		std::cout << "incorrect input\n";
	
}