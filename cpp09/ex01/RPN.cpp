/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:49:59 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/25 15:34:37 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void check_overflow(int a, int b, int ope)
{
    long long   test;
    long long   temp;
    long long x;
    long long y;
    int         result;
    
    x = static_cast<long long>(a);
    y = static_cast<long long>(b);
    temp = 0;
    test = 0;
    result = 0;
    switch (ope)
    {
        case 1:
            test = x + y;
            result = a + b;
            temp = static_cast<long long>(result);
            break;
        case 2:
            test = x - y;
            result = a - b;
            temp = static_cast<long long>(result);
            break;
        case 3:
        {
            test = x / y;
            result = a / b;
            temp = static_cast<long long>(result);
            break;
        }
        default:
            test = x * y;
            result = a * b;
            temp = static_cast<long long>(result);
            break;
    }
    if (test != temp)
    {
        std::cerr << "Error overflow." << std::endl;
        exit(1);
    }
    return;
}

int get_oper(char c)
{
    if (c == '+')
        return(1);
    if (c == '-')
        return(2);
    if (c == '/')
        return (3);
    if (c == '*')
        return(4);
    return (0);
}
int wrong_format(const char *input)
{
    int i;
    int nb;
    int op;
    i = 0;
    nb = 0;
    op = 0;
    while (input[i] != '\0')
    {
        if (isdigit(input[i]) || isspace(input[i]) || get_oper(input[i]))
            i++;
        else
            return (1);
    }
        i = 0;
    while (input[i] != '\0')
    {
        if (isdigit(input[i]))
            nb++;
        i++;
    }
    i = 0;
    while (input[i] != '\0')
    {
        if (get_oper(input[i]))
            op++;
        i++;
    }
    if (op != nb - 1)
        return (1);
    return(0);
    
}


int RPN(const char *input)
{
    if (wrong_format(input))
    {
        std::cerr << "Error wrong format try using only number 0 to 9 and have nb - 1 operator" << std::endl;
        exit(1);
    }
    std::stack<int> rpn;
    int i;
    int temp;
    int temp2;
    int ope;

    i = 0;
    ope = 0;
    temp = 0;
    temp2 = 0;
    while (input[i] != '\0')
    {
        if (isdigit(input[i]))
        {
            rpn.push(input[i] - 48);
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
        {
            ope = get_oper(input[i]);
            if (!ope)
            {
                std::cerr << "Error invalid operator." << std::endl;
                exit(1);
            }
            temp = rpn.top();
            rpn.pop();
            temp2 = rpn.top();
            rpn.pop();
            switch (ope)
            {
                case 1:
                    check_overflow(temp2, temp, ope);
                    rpn.push(temp2 + temp);
                    break;
                case 2:
                    check_overflow(temp2, temp, ope);
                    rpn.push(temp2 - temp);
                    break;
                case 3:
                {
                    if (temp2 == 0)
                    {
                        std::cerr << "Error cannot divide by 0." << std::endl;
                        exit(1);
                    }
                    check_overflow(temp2, temp, ope);
                    rpn.push(temp2 / temp);
                    break;
                }
                default:
                    check_overflow(temp2, temp, ope);
                    rpn.push(temp2 * temp);
                    break;
            }
        }
        i++;
    }
    if (rpn.size() != 1)
    {
        std::cerr << "Error invalid operation." << std::endl;
        exit(1);
    }
    return(rpn.top());
}