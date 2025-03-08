/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:14 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 20:39:33 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat():_name("default"),_grade(150){}

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

std::string Bureaucrat::getname(void)const
{
	return _name;
}
int Bureaucrat::getgrade(void)const
{
	return this->_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("grade is too hight")
{
	
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("grade  is too low")
{
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too hight";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade  is too low";
}
std::ostream &operator<<(std::ostream &os, Bureaucrat &br)
{
	os <<br.getname()<<" >, bureaucrat grade " <<" "<<br.getgrade()<<".";
	return os;
}

void Bureaucrat::signForm(AForm &fr)
{
	if (fr.getIsSigned() == true)
		std::cout<<" form " << fr.getName() << " is already signed\n";
	else
	{
		fr.beSigned(*this);
		if (fr.getIsSigned() == true)
			std::cout<< this->getname() << " signed " << fr.getName() << std::endl;
		else
			std::cout<< this->getname() << " couldn’t sign " 
			<<fr.getName()<< " because " << " he doesn't have the required grade "
			<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)const
{
	if (form.getToExecuteGrade() < this->getgrade())
		std::cout<< this->getname() << " can't execute "<< form.getName()<<std::endl;
	else
		std::cout<< this->getname() << " executed " << form.getName()<<std::endl;
}
