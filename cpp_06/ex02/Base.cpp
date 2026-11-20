/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:25:50 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/08 11:38:50 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate()
{
    std::srand(std::time(0));
    int rand = std::rand() % 3;

    switch (rand)
    {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A;
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B;
        default:
            std::cout << "Generated C" << std::endl;
            return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified as: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified as: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified as: C" << std::endl;
    else
        std::cout << "No identification possible" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified as: A" << std::endl;
        return;
    } catch (...)
    {
        std::cout << "Base is not A" << std::endl;
    }

    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified as: B" << std::endl;
        return;
    } catch (...)
    {
        std::cout << "Base is not B" << std::endl;
    }

    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified as: C" << std::endl;
        return;
    } catch (...)
    {
        std::cout << "Base is not C" << std::endl;
    }
    std::cout << "No identification possible" << std::endl;
}
