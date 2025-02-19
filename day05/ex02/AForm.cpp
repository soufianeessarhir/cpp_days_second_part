/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:39:46 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 20:58:41 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_name("default"),_is_signed(false),_sign_grade(150),_exec_grade(150)
{
	
}

AForm::~AForm()
{
}
AForm & AForm::operator=(const AForm &fr)
{
	if (this == &fr)
		return *this;
	this->_is_signed = fr._is_signed;
	return *this;
}

AForm::AForm(const AForm &fr):_name(fr._name),_is_signed(fr._is_signed),_sign_grade(fr._is_signed),_exec_grade(fr._exec_grade)
{
	
}
AForm::AForm(std::string name,bool is_signed,int sing_grade,int exec_grade):_name(name),_is_signed(is_signed),_sign_grade(sing_grade),_exec_grade(exec_grade)
{
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_exec_grade < 1 || _sign_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}
std::ostream & operator<<(std::ostream &os, AForm &fr)
{
	os<<fr.getName()<<" is signed "<< fr.getIsSigned()<<
	" signed grade " << fr.getToSignedGrad()<<" execute grade " <<
	fr.getToExecuteGrade();
	return os;
}
std::string AForm::getName(void)const
{
	return _name;
}
bool AForm::getIsSigned(void)const
{
	return _is_signed;
}
int AForm::getToSignedGrad(void)const
{
	return _sign_grade;
}
int AForm::getToExecuteGrade(void)const
{
	return _exec_grade;
}

void AForm::beSigned(Bureaucrat & br)
{
	if (this->_sign_grade < br.getgrade())
		throw Bureaucrat::GradeTooLowException();
	this->_is_signed = true;
}