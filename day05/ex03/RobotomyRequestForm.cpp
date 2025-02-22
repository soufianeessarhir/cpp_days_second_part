/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:49:53 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 20:31:01 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm",false,72,45),_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& Ro):AForm(Ro)
{
	(void)Ro;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& Ro)
{
	(void)Ro;
	return *this;
}
void RobotomyRequestForm::action()const
{
	std::cout<< "BZZZZT... VRRRR... DRRRRRR"<<std::endl;
	std::srand(std::time(0));
	int random = std::rand();
	if(random % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
		std::cout << "Robotomy failed for " << _target << std::endl;
	
}

