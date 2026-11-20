/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:24:27 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/02 14:22:53 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const		_name;
        bool                _isSigned;
		int					_gradeToSign;
        int					_gradeToExec;
        
        virtual void	beExecuted(void) const = 0;
        
	public:
		AForm(void);
		AForm(std::string const &name, int const &gradeToSign, int const &gradeToExec);
		AForm(AForm const &copy);
		~AForm(void);
		AForm const	&operator=(AForm const &copy);
		std::string const	&getName(void) const;
        bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExec(void) const;
		void	            beSigned(Bureaucrat &bureaucrat);
        void			    execute(const Bureaucrat &executor) const;

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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what(void) const throw();
            
        };
        
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);