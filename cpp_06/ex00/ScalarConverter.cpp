/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:01:12 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/09 12:02:27 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"




void ScalarConverter::convert(const std::string &literal) 
{
    char c;
    int i;
    float f;
    double d;
    bool found = false;

    if (literal.empty())
    {
        std::cout << "Empty literal is not valid." << std::endl;
        return;
    }
    for (std::string::const_iterator it = literal.begin(); it != literal.end(); ++it)
    {
        if (!std::isprint(static_cast<unsigned char>(*it)))
        {
            std::cout << "Non-printable character detected: ASCII " << static_cast<int>(*it) << std::endl;
            return;
        }
    }
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) 
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } 
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf") 
    {
        f = std::strtof(literal.c_str(), NULL);
        d = static_cast<double>(f);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    } 
    else if (literal == "-inf" || literal == "+inf" || literal == "nan") 
    {
        d = std::strtod(literal.c_str(), NULL);
        f = static_cast<float>(d);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    else if (literal.find('.') != std::string::npos || literal.find('f') != std::string::npos)
    {
        try
        {
            f = std::strtof(literal.c_str(), NULL);
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            c = static_cast<char>(i);
        } catch (...)
        {
            std::cout << "Invalid literal" << std::endl;
            return;
        }
    }
    else
    {
        try
        {
            i = std::strtol(literal.c_str(), NULL, 10);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        } catch (...)
        {
            std::cout << "Invalid literal" << std::endl;
            return;
        }
    }
    for (size_t i = 0; i < literal.length() - 1; ++i)
    {
        if (!std::isdigit(literal[i]) && !std::isdigit(literal[i + 1]))
        {
            found = true;
            break;
        }
    }
    if (found == true)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
//////////////////add this
ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}