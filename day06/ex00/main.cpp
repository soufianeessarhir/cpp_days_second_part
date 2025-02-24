/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:02:50 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 09:53:54 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int ac , char **av)
{
	if (ac != 2)
	  return std::cout<< " incorrect number of arguments\n",1;
	ScalarConverter::convert(av[1]);
}