/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:28:17 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/08 11:32:01 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


int main()
{
    std::cout << "\n ---Base identifier ex02----- \n\n";
    
    std::cout << "generating object \n";
    Base* obj = generate();

    std::cout << "\n -------------------- \n\n";
    std::cout << "identifying by pointer \n";
    identify(obj);
    std::cout << "\n -------------------- \n\n";
    std::cout << "identifying by reference \n";
    identify(*obj);

    std::cout << "deleting objects \n";
    delete obj;
    return 0;
}