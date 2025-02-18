/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:43 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/18 16:44:12 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	Bureaucrat a("hamid",150);
	a--;
	Bureaucrat b("b",1);
	b++;
	Bureaucrat c("c",5);
	std::cout<< c.getname() <<" "<<c.getgrade() <<std::endl;
	Bureaucrat d("d",0);
	Bureaucrat e("e",151);
}