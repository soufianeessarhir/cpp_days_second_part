/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:36:24 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 11:59:28 by sessarhi         ###   ########.fr       */
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
	// uint_64 key;
	if(file.is_open())
	{
		while(getline(file,tmp))
		{
			std::stringstream os(tmp);
			if (os>>year>>dash>>month>>dash1>>day>>del>>strval)
			{
				if (dash == '-' || dash1 == '-' || del == '|')
				{
					errno = 0;
					char *end = NULL;
					value = strtod(strval.c_str(),&end);
					if (*end || std::isinf(value) || std::isnan(value))
						std::cout << "bad input\n";
					else if (errno || value > 1000)
						std::cerr<<"too large a numbe\n";
					else if (value < 0)
						std::cout << "not a positive number.\n";
					else
					{
						std::cout<< "ok\n";
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