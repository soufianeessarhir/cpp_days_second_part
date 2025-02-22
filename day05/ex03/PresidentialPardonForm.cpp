/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:53:50 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 20:32:49 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm",false,25,5),_target(target)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& pr):AForm(pr)
{
	(void)pr;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& pr)
{
	(void)pr;
	return *this;
}

void PresidentialPardonForm::action()const
{
	std::cout<<_target<< " has been pardoned by Zaphod Beeblebrox."<<std::endl;
}