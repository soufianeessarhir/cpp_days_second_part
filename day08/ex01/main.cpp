/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:07 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/27 18:17:38 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() 
{ 
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
    try {
        Span sp(5);

        sp.addNumber(10);
        sp.addNumber(3);
        sp.addNumber(20);
        sp.addNumber(6);
        sp.addNumber(15);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        sp.addNumber(100);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Span emptySp(2);
        emptySp.addNumber(1);
        std::cout << "Shortest Span: " << emptySp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	Span span1(3);
    std::vector<int> numbers1 = {1, 2, 3};
    span1.addNumber(numbers1.begin(), numbers1.end());
	std::cout<<span1.longestSpan()<<"\n";
	std::cout<<span1.shortestSpan()<<"\n";
    return 0;
}
