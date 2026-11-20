/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:38:29 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/08 12:04:36 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    std::cout << "\n-----------Whatever ex00-----------\n\n"<< std::endl;
    std::cout << "\n-----------Int-----------\n\n"<< std::endl;
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "Swapping value :\n" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Searching for minimum and maximum :\n" << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    int a2 = 5;
    int b2 = 5;
    std::cout << "Trying with identical value :\n" << std::endl;
    std::cout << "min( a, b ) = " << ::min( a2, b2 ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a2, b2 ) << std::endl;
    std::cout << "\n-----------Float-----------\n\n"<< std::endl;
    float x = 42.0f;
    float y = 25.5f;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    ::swap( x, y );
    std::cout << "Swapping value :\n" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "Searching for minimum and maximum :\n" << std::endl;
    std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
    std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
    std::cout << "\n-----------String-----------\n\n"<< std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "Swapping value :\n" << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "Searching for minimum and maximum :\n" << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}