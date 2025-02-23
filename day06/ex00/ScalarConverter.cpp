/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:35:54 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/23 11:06:53 by sessarhi         ###   ########.fr       */
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