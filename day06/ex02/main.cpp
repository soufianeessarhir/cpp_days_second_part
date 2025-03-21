/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:10:27 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 20:22:31 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Classes.hpp"


int main()
{
	Base *base;

	base = generate();
	identify(base);
	identify(*base);

	Base *base2 = new Base;
	identify(base2);
	identify(*base2);
	delete base2;
	delete base;
	
} 