/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:29:21 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/02 14:46:16 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

    std::cout << "\n ---bureaucrat ex02----- \n\n";
	/* try creating 3 forms and 3 Bureaucrats */

	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Problematic individual");
	PresidentialPardonForm pardon("Balkani");
	Bureaucrat billy("Billy", 150);
	Bureaucrat timothee("Timothee", 120);
	Bureaucrat einstein("Einstein", 3);
	
	/* Try to execute forms without being signed */
	{
		try
		{
			std::cout << billy << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			billy.executeForm(shrubbery);
			billy.executeForm(robotomy);
			billy.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign form and try to execute with grade too low */
	{
		try
		{
			std::cout << billy << std::endl;
			std::cout << timothee << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(timothee);
			billy.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign forms and execute them with grade high enough */
	{
		try
		{
			robotomy.beSigned(einstein);
			pardon.beSigned(einstein);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n --------------------- \n\n";
			einstein.executeForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			einstein.executeForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			einstein.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";


	return (0);
}