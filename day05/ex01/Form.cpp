/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:39:46 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/19 09:37:04 by sessarhi         ###   ########.fr       */
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
	
}