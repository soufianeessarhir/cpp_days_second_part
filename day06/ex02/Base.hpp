/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:11:45 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 19:55:11 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>


class Base
{
	public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif