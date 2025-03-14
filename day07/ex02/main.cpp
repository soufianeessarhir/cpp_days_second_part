/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:13:28 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/25 15:14:58 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	try {
		Array<int> emptyArray;
		std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
		Array<int> numbers(5);
		std::cout << "Size of numbers array: " << numbers.size() << std::endl;
		for (unsigned int i = 0; i < numbers.size(); ++i)
			numbers[i] = i * 10;
		std::cout << "Numbers array: ";
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
		Array<int> copiedArray(numbers);
		std::cout << "Copied array: ";
		for (unsigned int i = 0; i < copiedArray.size(); ++i)
			std::cout << copiedArray[i] << " ";
		std::cout << std::endl;
		copiedArray[0] = 999;
		std::cout << "Modified copied array: " << copiedArray[0] << std::endl;
		std::cout << "Original numbers array (unchanged): " << numbers[0] << std::endl;
		Array<int> assignedArray;
		assignedArray = numbers;
		std::cout << "Assigned array: ";
		for (unsigned int i = 0; i < assignedArray.size(); ++i)
			std::cout << assignedArray[i] << " ";
		std::cout << std::endl;
		std::cout << "Trying to access index 10..." << std::endl;
		std::cout << numbers[10] << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
