/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:43 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 12:37:22 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form fr("hamid",false,2,2);
	std::cout<<fr<<std::endl;
	try
	{
		Form a("hamid",false,0,2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form b("hamid",false,2,151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}