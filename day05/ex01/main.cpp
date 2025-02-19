/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:43 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/18 20:37:16 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	try
	{
		Bureaucrat a("hamid",150);
		a--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		Bureaucrat b("b",1);
		b++;
	}	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		Bureaucrat d("d",0);
		Bureaucrat e("e",151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}		
	Bureaucrat c("c",5);
	std::cout<< c.getname()<<" >, bureaucrat grade " <<" "<<c.getgrade()<<"." <<std::endl;
	
}