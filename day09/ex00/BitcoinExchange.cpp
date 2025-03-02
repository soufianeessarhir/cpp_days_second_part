/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:36:24 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 13:12:36 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <errno.h>
#include <cmath>

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
		 	if (os>>year>>dash>>month>>dash1>>day>>del>>strval || !parsedate(tmp) == false)
			{
				if (dash == '-' && dash1 == '-' && del == '|')
				{
					errno = 0;
					char *end = NULL;
					value = strtod(strval.c_str(),&end);
					if (*end || std::isinf(value) || std::isnan(value))
						std::cout << "bad input\n";
					else if (errno || value > 1000)
						std::cerr<<"too large number\n";
					else if (value < 0)
						std::cout << "not a positive number.\n";
					else
					{
						key = year * 10000 + month * 100 + day;
						std::map<uint_64, double>::iterator it = data.lower_bound(key);
						if (it != data.end())
						{
							std::cout<<it->second * value << std::endl;
						}
					}
				}
				else
					std::cout << "bad input\n";
			}
			else
				std::cout << "bad input\n";
		}
	}
	else
		std::cerr<<"can't open data file";
	
}

bool BitcoinExchange::parsedate(std::string token)
{
	std::stringstream os(token);
	std::string date;
	int year,month,day;
	char dash,dash1;
	// bool isleap;
	uint_64 key;
	os >> date;
	if (token.find(' ') != std::string::npos)
		date = token.substr(0,token.find(' '));
	else
		return false;
	if (date.length() != 10)
		return false;
	if (os>>year>>dash>>month>>dash1>>day)
	{
		key = year * 10000 + month * 100 + day;
		if (key > data.rbegin()->first)
			return false;
	}
	return true;
}
