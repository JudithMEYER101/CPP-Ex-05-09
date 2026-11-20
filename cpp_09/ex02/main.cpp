/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:36:24 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/29 12:58:02 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: wrong number of argument." << std::endl;
        return 1;
    }
    if (wrong_format(argv))
    {
        std::cerr << "Error: wrong format, use only positive integers and spaces." << std::endl;
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        if (!is_duplicate(num, input))
            input.push_back(num);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    // Sort with std::vector
    std::vector<int> vecCopy(input.begin(), input.end());
    clock_t start = clock();
    ford_johnson_sort_vector(vecCopy);
    clock_t end = clock();
    double vectorDuration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "After with vector: ";
    for (size_t i = 0; i < vecCopy.size(); ++i)
        std::cout << vecCopy[i] << " ";
    std::cout << std::endl;
    std::cout << "Time taken for std::vector: " << vectorDuration << " seconds" << std::endl;

    // Sort with std::deque
    std::deque<int> dequeCopy(input.begin(), input.end());
    start = clock();
    ford_johnson_sort_deque(dequeCopy);
    end = clock();
    double dequeDuration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "After with deque: ";
    for (size_t i = 0; i < dequeCopy.size(); ++i)
        std::cout << dequeCopy[i] << " ";
    std::cout << std::endl;
    std::cout << "Time taken for std::deque: " << dequeDuration << " seconds" << std::endl;

    return 0;
}