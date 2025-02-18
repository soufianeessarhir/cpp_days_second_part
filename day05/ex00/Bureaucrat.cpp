/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:14 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/18 16:45:25 by sessarhi         ###   ########.fr       */
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
	try
	{
		if (grade > 150)
		throw "Bureaucrat::GradeTooHighException";
		else if (grade < 1)
			throw "Bureaucrat::GradeTooLowException";
		_grade = grade;
		
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	
}
Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp = *this;
	try
	{
		if (getgrade() == 150)
			throw "Bureaucrat::GradeTooHighException";
		_grade++;
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	return tmp;
}
Bureaucrat& Bureaucrat::operator--()
{
	try
	{
		if (getgrade() == 150)
			throw "Bureaucrat::GradeTooHighException";
		_grade++;
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	return *this;
}
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp = *this;
	try
	{
		if (getgrade() == 1)
			throw "Bureaucrat::GradeTooLowException";
		_grade--;
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	return tmp;
}
Bureaucrat& Bureaucrat::operator++()
{
	try
	{
		if (getgrade() == 1)
			throw "Bureaucrat::GradeTooLowException";
		_grade--;
	}
	catch(const char* msg)
	{
		std::cerr << msg << '\n';
	}
	return *this;
}

std::string Bureaucrat::getname(void)const{return _name;}
int Bureaucrat::getgrade(void)const{return this->_grade;}