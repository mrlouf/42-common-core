/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:48:50 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/27 14:42:14 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "Default AForm created" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), \
	_signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	std::cout << "AForm " << other.getName() << " copied" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade) \
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
}

AForm::~AForm() {
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

std::string const &AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() >= _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::UnsignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	if (f.getIsSigned())
		out << f.getName() << ", is signed, sign grade " << f.getSignGrade() << ", exec grade " << f.getExecuteGrade();
	else
		out << f.getName() << ", not signed, sign grade " << f.getSignGrade() << ", exec grade " << f.getExecuteGrade();
	return out;
}
