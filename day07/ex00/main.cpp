/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:10:44 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/25 11:21:13 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main()
{
	int a = 2;
	int b = 3;

	swap<int>(a,b);
	std::cout<< "a = "<< a << " b = "<< b << std::endl;
	std::cout<< "min = "<< min<int>(a,b)<< std::endl;
	std::cout<< "max = "<< max<int>(a,b)<< std::endl;
	
}