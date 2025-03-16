/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:35:22 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/02 22:38:25 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
		return std::cout<< "incorrect number of arguments\n",1;
	RPN rpn;
	rpn.rpn(av[1]);
}