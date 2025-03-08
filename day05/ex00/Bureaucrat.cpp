/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:14 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 12:11:12 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("default"),_grade(150)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& br):_name(br._name),_grade(br._grade)
{

}

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
		throw Bureaucrat::GradeTooLowException("Grade too low");
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	_grade = grade;
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp = *this;

	if (getgrade() == 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
	_grade++;
	return tmp;
}
Bureaucrat& Bureaucrat::operator--()
{
	if (getgrade() == 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
	_grade++;
	return *this;
}
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp = *this;
	if (getgrade() == 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	_grade--;
	return tmp;
}
Bureaucrat& Bureaucrat::operator++()
{
	if (getgrade() == 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	_grade--;
	return *this;
}

std::string Bureaucrat::getname(void)const
{
	return _name;
}

int Bureaucrat::getgrade(void)const
{
	return this->_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const &msg) : _msg(msg)
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const &msg) : _msg(msg)
{

}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{

}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{

}

std::ostream &operator<<(std::ostream &os, Bureaucrat &br)
{
	os <<br.getname()<<" ,bureaucrat grade " <<" "<<br.getgrade()<<".";
	return os;
}

