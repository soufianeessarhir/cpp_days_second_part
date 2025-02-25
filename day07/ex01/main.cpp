/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:42:05 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/25 12:02:15 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void printInt(int x) {
    std::cout << x << " ";
}

void squareDouble(double &x) {
    x *= x;
}

void toUpperCase(std::string &str) {
    for (std::string::iterator it = str.begin(); it != str.end();++it)
        *it = std::toupper(*it);
}

template <typename T>
void printElement(const T &x) {
    std::cout << x << " ";
}

int main() {

    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Int Array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArray, 4, squareDouble);
    std::cout << "Doubles squared: ";
    iter(doubleArray, 4, printElement<double>);
    std::cout << std::endl;
    std::string strArray[] = {"hello", "world", "test"};
    iter(strArray, 3, toUpperCase);
    std::cout << "Uppercase Strings: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;
    return 0;
}
