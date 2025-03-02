/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:36:24 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 10:54:55 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream  file("data.csv");
	std::string tmp;
	int year,month,day;
	char dash,dash1,comma;
	double value;
	uint_64 key;
	if(file)
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
		std::cout<<"can't open data file";
	
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
}