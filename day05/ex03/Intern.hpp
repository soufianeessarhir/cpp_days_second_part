/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:37:18 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 22:16:14 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
	static AForm* createShrubberyForm(std::string target);
    static AForm* createRobotomyForm(std::string target);
    static AForm* createPresidentialForm(std::string target);
public:
	Intern();
	Intern(const Intern& intern);
	Intern & operator=(const Intern & intern);
	~Intern();
	static AForm* makeForm(std::string name, std::string target);
};

