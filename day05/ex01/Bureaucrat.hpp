/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:17 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 12:34:32 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
// #include "Form.hpp"
class Form;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &br);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &br);
	std::string getname(void) const;
	int getgrade(void)const;
	Bureaucrat & operator++();
	Bureaucrat  operator++(int);
	Bureaucrat & operator--();
	Bureaucrat  operator--(int);
	void signForm(Form &fr);
	class  GradeTooHighException: public std::runtime_error
	{
		public:
		GradeTooHighException();
	};
	class GradeTooLowException: public std::runtime_error
	{
		public:
		GradeTooLowException();
	};
};
std::ostream &operator<<(std::ostream &os, Bureaucrat &br);

#endif