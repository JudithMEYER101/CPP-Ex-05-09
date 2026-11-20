/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:29:21 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/02 16:18:01 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		billy;
	AForm		*form;
	Bureaucrat	einstein("Einstein", 2);

    std::cout << "\n ---bureaucrat ex03----- \n\n";
	// create form, try and create a wrong form
	try
	{
		form = billy.makeForm("robotomy request", "Bender");
		delete form;
		form = billy.makeForm("shrubbery creation", "Johnny");
		delete form;
		form = billy.makeForm("presidential pardon", "Dread");
		delete form;
		form = billy.makeForm("wrong form", "Random guy");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Create and use form
	std::cout << "\n------------------------------------\n" << std::endl;
	form = billy.makeForm("shrubbery creation", "Bulbizar");
	form->beSigned(einstein);
	einstein.executeForm(*form);
	delete form;
	std::cout << "\n------------------------------------\n" << std::endl;
	form = billy.makeForm("presidential pardon", "Balkani");
	einstein.signForm(*form);
	einstein.executeForm(*form);
	delete form;
	return (0);
}