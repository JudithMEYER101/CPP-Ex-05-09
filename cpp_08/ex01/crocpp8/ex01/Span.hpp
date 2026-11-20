/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:22:05 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/07 11:15:38 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
    
        void addNumber(int num);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    
        int shortestSpan() const;
        int longestSpan() const;
};
    

#endif
