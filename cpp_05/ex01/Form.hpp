/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:24:27 by armeyer           #+#    #+#             */
/*   Updated: 2025/03/31 15:51:07 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const		_name;
        bool                _isSigned;
		int					_gradeToSign;
        int					_gradeToExec;
	public:
		Form(void);
		Form(std::string const &name, int const &gradeToSign, int const &gradeToExec);
		Form(Form const &copy);
		~Form(void);
		Form const	&operator=(Form const &copy);
		std::string const	&getName(void) const;
        bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExec(void) const;
		void	            beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);