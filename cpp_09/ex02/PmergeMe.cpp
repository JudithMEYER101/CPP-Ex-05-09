/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:36:37 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/29 13:27:32 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void smart_insert(std::vector<int>& container, int value)
{
    std::vector<int>::iterator it = container.begin();
    while (it != container.end() && *it < value)
        ++it;
    container.insert(it, value);
}

void smart_insert(std::deque<int>& container, int value)
{
    std::deque<int>::iterator it = container.begin();
    while (it != container.end() && *it < value)
        ++it;
    container.insert(it, value);
}

void ford_johnson_sort_vector(std::vector<int>& container)
{
    if (container.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> winners;

    std::vector<int>::iterator it = container.begin();
    while (it != container.end())
    {
        int a = *it;
        ++it;
        if (it != container.end())
        {
            int b = *it;
            ++it;
            if (a < b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));
            winners.push_back((a > b) ? a : b);
        } else
        {
            winners.push_back(a);
        }
    }

    ford_johnson_sort_vector(winners);

    std::vector<int> result;
    result.push_back(winners[0]);

    size_t j;
    for (j = 1; j < winners.size(); ++j)
        smart_insert(result, winners[j]);

    for (j = 0; j < pairs.size(); ++j)
        smart_insert(result, pairs[j].first);

    container = result;
}

void ford_johnson_sort_deque(std::deque<int>& container)
{
    if (container.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::deque<int> winners;

    std::deque<int>::iterator it = container.begin();
    while (it != container.end())
    {
        int a = *it;
        ++it;
        if (it != container.end())
        {
            int b = *it;
            ++it;
            if (a < b)
                pairs.push_back(std::make_pair(a, b));
            else
                pairs.push_back(std::make_pair(b, a));
            winners.push_back((a > b) ? a : b);
        }
        else
        {
            winners.push_back(a);
        }
    }

    ford_johnson_sort_deque(winners);

    std::deque<int> result;
    result.push_back(winners[0]);

    size_t j;
    for (j = 1; j < winners.size(); ++j)
        smart_insert(result, winners[j]);

    for (j = 0; j < pairs.size(); ++j)
        smart_insert(result, pairs[j].first);

    container = result;
}