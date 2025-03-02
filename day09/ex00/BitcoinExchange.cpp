/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:36:24 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 14:31:31 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <errno.h>
#include <cmath>
#include <ctime>
#include <cstring> 

BitcoinExchange::BitcoinExchange()
{
	std::ifstream  file("data.csv");
	std::string tmp;
	int year,month,day;
	char dash,dash1,comma;
	double value;
	uint_64 key;
	if(file.is_open())
	{
		while(getline(file,tmp))
		{
			std::stringstream os(tmp);
			os>>year>>dash>>month>>dash1>>day>>comma>>value;
			key = year * 10000 + month * 100 + day;
			data[key] = value;
		}
	}
	else
		std::cerr<<"can't open data file";
	
}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & rhs)
{
	(void)rhs;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	(void)rhs;
	return *this;
}

void BitcoinExchange::processipute(std::string FileName)
{
	std::ifstream file(FileName.c_str());
	std::string tmp;
	int year,month,day;
	char dash,dash1,del;
	std::string strval;
	double value;
	uint_64 key;
	if(file.is_open())
	{
		while(getline(file,tmp))
		{
			std::stringstream os(tmp);
			if (parsedate(tmp) == false)
				continue;
		 	else if (os>>year>>dash>>month>>dash1>>day>>del>>strval)
			{
				if (dash == '-' && dash1 == '-' && del == '|')
				{
					errno = 0;
					char *end = NULL;
					value = strtod(strval.c_str(),&end);
					if (*end || std::isinf(value) || std::isnan(value))
						std::cout << "Error: bad input => 2001-42-42\n";
					else if (errno || value > 1000)
						std::cerr<<"Error: too large number\n";
					else if (value < 0)
						std::cout << "Error: not a positive number.\n";
					else
					{
						key = year * 10000 + month * 100 + day;
						std::map<uint_64, double>::iterator it = data.lower_bound(key);
						if (it != data.end())
							std::cout<<tmp.substr(0,tmp.find(' ')) + " => "<< value << " = " <<it->second * value << std::endl;
					}
				}
				else
					std::cout << "Error: bad input => 2001-42-42\n";
			}
			else
				std::cout << "Error: bad input => 2001-42-42\n";
		}
	}
	else
		std::cerr<<"Error: can't open data file";
	
}

bool BitcoinExchange::parsedate(std::string token)
{
        std::string date;
		uint_64 key;
        size_t spacePos = token.find(' ');
        if (spacePos != std::string::npos)
            date = token.substr(0, spacePos);
        else
		return std::cerr << "Error: Bad input \n",false;
        if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
           return std::cerr << "Error: Incorrect date format \n", false;
        int year, month, day;
        char dash1, dash2;
        std::stringstream ss(date);
        if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
           return std::cerr << "Error: Incorrect date format \n", false;
        if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
            return std::cerr << "Error: Invalid date values.\n", false;
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        int maxDay = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11)
            maxDay = 30;
        else if (month == 2)
            maxDay = isLeapYear ? 29 : 28;
        if (day > maxDay)
           return std::cerr << "Error: Invalid day \n", false;
        key = static_cast<uint_64>(year * 10000 + month * 100 + day);
        if (key < data.begin()->first || key > data.rbegin()->first)
           return std::cerr << "Error: Date not included in the database.\n" , false;
	return true;
}
