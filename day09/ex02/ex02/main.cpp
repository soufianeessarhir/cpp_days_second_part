/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:15:43 by sessarhi          #+#    #+#             */
/*   Updated: 2025/03/04 19:30:01 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

int main(int ac , char **av)
{
	if (ac < 2)
	{
		std::cout<<"Usage: ./PmergeMe [numbers]\n";
		return 1;
	}
	try {
		PmergeMe mr(av,ac);
		mr.sort();
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;

}