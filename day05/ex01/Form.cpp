/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:39:46 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 12:27:22 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_name("default"),_is_signed(false),_sign_grade(150),_exec_grade(150)
{
	
}

Form::~Form()
{
}
Form & Form::operator=(const Form &fr)
{
	if (this == &fr)
		return *this;
	this->_is_signed = fr._is_signed;
	return *this;
}

Form::Form(const Form &fr):_name(fr._name),_is_signed(fr._is_signed),_sign_grade(fr._is_signed),_exec_grade(fr._exec_grade)
{
	
}
Form::Form(std::string name,bool is_signed,int sing_grade,int exec_grade):_name(name),_is_signed(is_signed),_sign_grade(sing_grade),_exec_grade(exec_grade)
{
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
	else if (_exec_grade < 1 || _sign_grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
}
std::ostream & operator<<(std::ostream &os, Form &fr)
{
	os<<fr.getName()<<" is signed "<< fr.getIsSigned()<<
	" signed grade " << fr.getToSignedGrad()<<" execute grade " <<
	fr.getToExecuteGrade();
	return os;
}
std::string Form::getName(void)const
{
	return _name;
}
bool Form::getIsSigned(void)const
{
	return _is_signed;
}
int Form::getToSignedGrad(void)const
{
	return _sign_grade;
}
int Form::getToExecuteGrade(void)const
{
	return _exec_grade;
}

void Form::beSigned(Bureaucrat & br)
{
	if (this->_sign_grade < br.getgrade())
		throw Bureaucrat::GradeTooLowException("Grade too low");
	this->_is_signed = true;
}