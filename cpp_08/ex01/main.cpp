/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:22:07 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/24 12:54:09 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void    fill_numbers(std::vector<int> &numbers)
{
    for (int i = 0; i <= 1000000; ++i)
    {
        numbers.push_back(i);
    }
}

int main() 
{
    std::cout << "\n-----Span ex01-----\n\n" << std::endl;
    try
    {
        std::cout << "\n-----Test Span with positive numbers-----\n" << std::endl;
        Span sp1(10);
        sp1.addNumber(5);
        sp1.addNumber(10);
        sp1.addNumber(3);
        sp1.addNumber(12);
        sp1.addNumber(7);
        sp1.addNumber(18);
        sp1.addNumber(1);
        sp1.addNumber(9);
        sp1.addNumber(15);

        std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp1.longestSpan() << std::endl;

        std::cout << "\n-----Test Span with negative numbers-----\n" << std::endl;
        Span sp2(10);
        sp2.addNumber(-5);
        sp2.addNumber(-10);
        sp2.addNumber(-3);
        sp2.addNumber(-12);
        sp2.addNumber(-7);
        sp2.addNumber(-18);
        sp2.addNumber(-1);
        sp2.addNumber(-9);
        sp2.addNumber(-15);

        std::cout << "Shortest Span (Negative): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span (Negative): " << sp2.longestSpan() << std::endl;

        std::cout << "\n-----Test Span with both posi and nega numbers-----\n" << std::endl;
        Span sp6(10);
        sp6.addNumber(-5);
        sp6.addNumber(10);
        sp6.addNumber(-3);
        sp6.addNumber(12);
        sp6.addNumber(-7);
        sp6.addNumber(18);
        sp6.addNumber(-1);
        sp6.addNumber(9);
        sp6.addNumber(-15);

        std::cout << "Shortest Span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp6.longestSpan() << std::endl;
        
        std::cout << "\n-----Test Span functions with only one element-----\n" << std::endl;
        Span sp3(1);
        sp3.addNumber(5);
        try
        {
            std::cout << "Shortest Span (Single Element): " << sp3.shortestSpan() << std::endl;
        } catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        try
        {
            std::cout << "Longest Span (Single Element): " << sp3.longestSpan() << std::endl;
        } catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n-----Filling a span using a range of iterator-----\n" << std::endl;
        std::vector<int> numbers;
        fill_numbers(numbers);

        Span sp4(numbers.size());
        sp4.addRange(numbers.begin(), numbers.end());

        std::cout << "Shortest Span (Range): " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span (Range): " << sp4.longestSpan() << std::endl;

        std::cout << "\n-----Test Span overflow-----\n" << std::endl;
        Span sp5(3);
        sp5.addNumber(1);
        sp5.addNumber(2);
        sp5.addNumber(3);
        try
        {
            sp5.addNumber(4);
        } catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e)
    {
        std::cout << "General Exception: " << e.what() << std::endl;
    }
    
    return 0;
}