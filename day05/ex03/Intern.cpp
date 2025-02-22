/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:41:11 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 22:23:21 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}
Intern::Intern(const Intern& intern)
{
	(void)intern;
}
Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form;
	AForm* (*creatform[])(std::string ) = {&createShrubberyForm,&createRobotomyForm,&createPresidentialForm};

	for(int i = 0 ; i < 3;++i)
	{
		if(name == names[i])
		{
			//add try-catch here
			form = creatform[i](target);
			std::cout << "Intern creates " << name <<std::endl;
			return form;
		}
	} 
	std::cout << "invalid form " << name<<std::endl;
	return NULL;
}
AForm* Intern::createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomyForm(std::string target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}
