/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:04:29 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/24 13:45:10 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int main()
{
	Data data;
	
	data.a = 1;
	data.b = 0.5f;
	data.c = "hello world";
	Data *ptr = Serializer::deserialize(Serializer::serialize(&data));
	std::cout<< ptr << "    " << &data <<std::endl;
	std::cout<<data.a<< " " << data.b << " "<< data.c <<std::endl;
}