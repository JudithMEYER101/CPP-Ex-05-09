/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:34:24 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/02 15:55:27 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Bureaucrat;

class Intern
{
	private:

	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
        Intern const	&operator=(Intern const &copy);
        AForm	*makeForm(std::string const &type, std::string const &target);
		
};