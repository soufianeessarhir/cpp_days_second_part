/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:14 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/18 18:48:25 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("default"),_grade(0){}
Bureaucrat::Bureaucrat(const Bureaucrat& br){*this = br;}
Bureaucrat::~Bureaucrat(){}
Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& br)
{
	if(this == &br)
	return *this;
	_grade = br._grade;
	return *this;
}
Bureaucrat::Bureaucrat(const std::string name , int grade):_name(name)
{
	if (grade > 150)
	throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}
Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp = *this;
	if (getgrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	return tmp;
}
Bureaucrat& Bureaucrat::operator--()
{
	if (getgrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	return *this;
}
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp = *this;
	if (getgrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	return tmp;
}
Bureaucrat& Bureaucrat::operator++()
{
	if (getgrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;

	return *this;
}

std::string Bureaucrat::getname(void)const{return _name;}
int Bureaucrat::getgrade(void)const{return this->_grade;}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("grade is less than 1 which is too hight"){}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("grade is greater than 150 which is too low"){}