/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:49:38 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 20:55:58 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm(){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shr)
{
	(void)shr;
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, bool isSigned,int gradeToSingn , int gradeToexecute)
:AForm(name,isSigned,gradeToSingn,gradeToexecute){}
