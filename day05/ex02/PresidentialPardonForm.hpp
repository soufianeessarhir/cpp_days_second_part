/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:52:42 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 15:33:55 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP 
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& pr);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& pr);
	void action() const;
};

#endif