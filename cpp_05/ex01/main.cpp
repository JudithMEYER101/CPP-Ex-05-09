/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:29:21 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/02 11:50:14 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "\n ---bureaucrat ex01----- \n\n";
    
    /* Create an average bureaucrat and an average form*/
    
    Bureaucrat kevin("Kevin", 15);
    std::cout << kevin << std::endl;
    Form form0("AverageForm", 60, 70);
    std::cout << form0 << std::endl;
    
    std::cout << "\n -------------------- \n\n";
    
	/* /Try to create form but grade is too high */
	{
		try
		{
			Form form1("form1", 0, 5);
			std::cout << form1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n ------------------ \n\n";

	/* Create bureaucrat, create form and sign it */
	{
		try
		{
			Bureaucrat joe("Joe", 18);
			Form form2("A31", 31, 42);
			std::cout << joe << std::endl;
			std::cout << form2 << std::endl;
			joe.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n ------------------- \n\n";

	/* Create form and try to sign it but grade is too low */
	{
		try
		{
			Bureaucrat einstein("Einstein", 35);
			Form form3("A200", 5, 40);
			std::cout << einstein << std::endl;
			std::cout << form3 << std::endl;
			einstein.signForm(form3);
			std::cout << form3 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}