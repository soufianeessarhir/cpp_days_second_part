/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:39:42 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 20:10:47 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const int _sign_grade;
	const int _exec_grade;
public:
	AForm();
	AForm(const AForm &fr);
	AForm & operator=(const AForm & fr);
	AForm(std::string name,bool is_signed,int sing_grade,int exec_grade);
	virtual ~AForm();
	std::string getName(void)const;
	bool getIsSigned(void)const;
	int getToSignedGrad(void)const;
	int getToExecuteGrade(void)const;
	void beSigned(const Bureaucrat & br);
	void execute(Bureaucrat const & executor) const;
	virtual void action() const = 0;
};

std::ostream & operator<<(std::ostream &os, AForm &fr);

#endif

