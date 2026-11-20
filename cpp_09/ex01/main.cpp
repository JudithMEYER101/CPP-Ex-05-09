/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:50:11 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/29 11:15:26 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    int result;
    if (argc != 2)
	    {
		    std::cout << "Error, wrong number of argument." << std::endl;
		    exit(1);
	    }
	result = RPN(argv[1]);
    std::cout << "Result: " << result << std::endl;
	return (0);
}