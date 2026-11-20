/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:36:48 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/29 13:05:46 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <set>
#include <iostream>
#include <ctime>

std::vector<int> parse_input(int argc, char** argv);
int wrong_format(char **input);
bool is_valid_number(const std::string& str);
bool is_duplicate(int n, const std::vector<int>& vec);
void ford_johnson_sort_vector(std::vector<int>& container) ;
void ford_johnson_sort_deque(std::deque<int>& container);

template <typename T>
void remove_duplicates(T& container)
{
    std::set<int> seen;
    typename T::iterator it = container.begin();
    while (it != container.end())
    {
        if (seen.find(*it) != seen.end())
        {
            it = container.erase(it);
        }
        else
        {
            seen.insert(*it);
            ++it;
        }
    }
}

#endif