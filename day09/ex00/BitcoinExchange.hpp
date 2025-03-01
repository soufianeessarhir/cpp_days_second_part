/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:35:26 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/01 18:25:50 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> data;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange & operator=(const BitcoinExchange&);
	void processipute(std::string str);
};

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

#endif