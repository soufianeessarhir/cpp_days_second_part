/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:35:26 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 10:34:44 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
typedef unsigned long long uint_64;
class BitcoinExchange
{
private:
	std::map<uint_64, double> data;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange & operator=(const BitcoinExchange&);
	void processipute(std::string FileName);
};


#endif