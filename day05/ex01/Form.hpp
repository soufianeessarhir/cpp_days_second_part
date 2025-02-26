/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:39:42 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 15:23:52 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const int _sign_grade;
	const int _exec_grade;
public:
	Form();
	Form(const Form &fr);
	Form & operator=(const Form & fr);
	Form(std::string name,bool is_signed,int sing_grade,int exec_grade);
	~Form();
	std::string getName(void)const;
	bool getIsSigned(void)const;
	int getToSignedGrad(void)const;
	int getToExecuteGrade(void)const;
	void beSigned(Bureaucrat & br);
};

std::ostream & operator<<(std::ostream &os, Form &fr);
#endif

