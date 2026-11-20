/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:04:04 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/29 13:04:26 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int is_oper(char c)
{
    return (c == '+' || c == '-');
}

int wrong_format(char **input)
{
    int i = 1;
    while (input[i])
    {
        int j = 0;
        while (input[i][j])
        {
            if (isdigit(input[i][j]) || isspace(input[i][j]) || is_oper(input[i][j]))
            {
                if (is_oper(input[i][j]) && !isdigit(input[i][j + 1]))
                    return 1;
                ++j;
            }
            else
                return 1;
        }
        ++i;
    }
    return 0;
}

bool is_duplicate(int n, const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == n)
            return true;
    }
    return false;
}

bool is_valid_number(const std::string& str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::vector<int> parse_input(int argc, char** argv)
{
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        std::stringstream ss(arg);
        std::string token;
        while (ss >> token)
        {
            if (!is_valid_number(token))
                throw std::runtime_error("Error: invalid input '" + token + "'");
            int num = std::atoi(token.c_str());
            if (num < 0)
                throw std::runtime_error("Error: negative numbers not allowed");
            numbers.push_back(num);
        }
    }
    return numbers;
}