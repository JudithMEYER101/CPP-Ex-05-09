/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:50:15 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/08 12:31:45 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
	std::cout << element << std::endl;
}

template <typename T>
void increment(T& element) {
	element += 1;
}

template <typename T>
void toUpperCase(T& str)
{
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

int main()
{
    std::cout << "\n ---Iter ex03----- \n\n";
	int nums[] = {1, 2, 3, 4, 5};
	std::string words[] = {"apple", "banana", "cherry"};

	std::cout << "Original nums:\n";
	iter(nums, 5, printElement<int>);

	std::cout << "\nIncrementing nums:\n";
	iter(nums, 5, increment<int>);

    std::cout << "\n -------------------- \n\n";
	std::cout << "\nNew nums:\n";
	iter(nums, 5, printElement<int>);

	std::cout << "\nPrinting words:\n";
	iter(words, 3, printElement<std::string>);
    std::cout << "\nMaking words uppercase:\n";
    iter(words, 3, toUpperCase<std::string>);
    std::cout << "\nPrinting words:\n";
	iter(words, 3, printElement<std::string>);

	return 0;
}