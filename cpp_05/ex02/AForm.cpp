/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:29:34 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/02 14:16:33 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("default"), _isSigned(0), _gradeToSign(50), _gradeToExec(25) {}

AForm::AForm(std::string const &name, int const &gradeToSign, int const &gradeToExec): _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_gradeToSign > 150)
		throw (AForm::GradeTooLowException());
    if (this->_gradeToExec < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_gradeToExec > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	*this = copy;
}

AForm::~AForm(void) {}

AForm const	&AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

int const	&AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const	&AForm::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

bool const  &AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_isSigned = 1;
		std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
	}
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::GradeTooLowException();
	else if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	else
		this->beExecuted();
}



char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("The form has not been signed.");
}


std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
    return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExec());
}