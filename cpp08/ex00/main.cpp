/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:03:22 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/24 11:56:06 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    
    std::cout << "\n---------easyfind ex00----------\n\n" << std::endl;
    std::cout << "creating vector [-10,10,20,30]" << std::endl;
    std::vector<int> vec;
    vec.push_back(-10);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    std::cout << "creating list [-5,5,15,25]" << std::endl;
    std::list<int> lst;
    lst.push_back(-5);
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    std::cout << "\ntry to find '-10' in vector" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, -10);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception& e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }
    std::cout << "\n\ntry to find '20' in vector" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception& e)
    {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    std::cout << "\n\ntry to find '-5' in list" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, -5);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception& e)
    {
        std::cout << "List: " << e.what() << std::endl;
    }
    std::cout << "\n\ntry to find '15' in list" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception& e)
    {
        std::cout << "List: " << e.what() << std::endl;
    }

    std::cout << "\n\ntry to find '100' in vector (doesn't exist)" << std::endl;
    try
    {
        easyfind(vec, 100);
    } catch (std::exception& e)
    {
        std::cout << "Vector (not found): " << e.what() << std::endl;
    }
    std::cout << "\n\ntry to find '-80' in list (doesn't exist)" << std::endl;
    try
    {
        easyfind(lst, -80);
    } catch (std::exception& e)
    {
        std::cout << "Vector (not found): " << e.what() << std::endl;
    }
    return 0;
}