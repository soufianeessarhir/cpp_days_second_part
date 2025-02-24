/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:18:14 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 20:20:25 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include "Classes.hpp"
#include <ctime>
Base::~Base(){}

Base *generate(void)
{
	srand(time(0));
	Base *base;
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		base = new A;
		break;
	case 1:
		base = new B;
		break;
	case 2:
		base =  new C;
		break;
	}
	return base;
}
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout<<" the base pointer type is A\n";
	else if (dynamic_cast<B*>(p))
		std::cout<<" the base pointer type is B\n";
	else if (dynamic_cast<C*>(p))
		std::cout<<" the base pointer type is C\n";
	else
		std::cout << "unknown type !!!!!!!!!!!!!\n";
}
void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout<<" the base reference type is A\n";
		return;
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout<<" the base reference type is B\n";
			return;
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout<<" the base reference type is C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "unknown type !!!!!!!!!!!!!\n";
				return ;
			}
			
		}
		
	}
	
}