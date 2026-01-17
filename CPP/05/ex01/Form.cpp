/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:48:50 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 10:21:48 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "Default Form created" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), \
	_signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	std::cout << "Form " << other.getName() << " copied" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade) \
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
}

Form::~Form() {
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string const &Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() >= _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	if (f.getIsSigned())
		out << f.getName() << ", 1, " << f.getSignGrade() << ", " << f.getExecuteGrade();
	else
		out << f.getName() << ", 0, " << f.getSignGrade() << ", " << f.getExecuteGrade();
	return out;
}
