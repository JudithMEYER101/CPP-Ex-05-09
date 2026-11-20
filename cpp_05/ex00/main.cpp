/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:29:21 by armeyer           #+#    #+#             */
/*   Updated: 2025/03/31 15:20:59 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n ---bureaucrat ex00----- \n\n";
    /* Creating a bureaucrat with average stat and getting it's info*/

    Bureaucrat kevin("Kevin", 75);
    std::cout << kevin << std::endl;

    std::cout << "\n ------------------- \n\n";
    
	/* try to build but Grade is too high */
	try
	{
		Bureaucrat mike("Mike", 0);
		std::cout << mike << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
    }

	std::cout << "\n ------------------ \n\n";

	/* try to build but Grade is too low */
	try
	{
		Bureaucrat jim("Jim", 151);
		std::cout << jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ------------------- \n\n";
	
	/* Grade up until Grade is too high*/
	try 
	{
		Bureaucrat dur("Dur", 3);
		std::cout << dur << std::endl;
		dur.gradeUp();
		std::cout << dur << std::endl;
		dur.gradeUp();
		std::cout << dur << std::endl;
		dur.gradeUp();
		std::cout << dur << std::endl;
        std::cout << "if this text appear no exception where thrown\n" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ------------------- \n\n";

	/*  Grade down until Grade is too low*/
	try 
	{
		Bureaucrat alan("Alan", 149);
		std::cout << alan << std::endl;
		alan.gradeDown();
		std::cout << alan << std::endl;
		alan.gradeDown();
		std::cout << alan << std::endl;
		alan.gradeDown();
		std::cout << alan << std::endl;
        std::cout << "if this text appear no exception where thrown\n" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}