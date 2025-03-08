/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:46:38 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 21:01:22 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main()
{
	try
	{
		AForm* form = new ShrubberyCreationForm("home");
		Bureaucrat br("br", 1);
		br.signForm(*form);
		br.executeForm(*form);
		form->execute(br);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm* form = new PresidentialPardonForm("home");
		Bureaucrat br("br", 1);
		br.signForm(*form);
		br.executeForm(*form);
		form->execute(br);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		AForm* form = new RobotomyRequestForm("home");
		Bureaucrat br("br", 1);
		br.signForm(*form);
		br.executeForm(*form);
		form->execute(br);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Intern intern;
	AForm *form = intern.makeForm("shrubbery creation", "home");
	Bureaucrat br("br", 1);
	br.signForm(*form);
	br.executeForm(*form);
	form->execute(br);
	delete form;
	form = intern.makeForm("robotomy request", "home");
	br.signForm(*form);
	br.executeForm(*form);
	form->execute(br);
	delete form;
	form = intern.makeForm("presidential pardon", "home");
	br.signForm(*form);
	br.executeForm(*form);
	form->execute(br);
	delete form;
}
