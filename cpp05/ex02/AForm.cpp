/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:50 by Degef             #+#    #+#             */
/*   Updated: 2023/10/05 13:58:42 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), 
		_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), 
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << M << "AForm destructor called" << reset << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
	os << "Name: " << Aform.getName() << "  |Signed: " << Aform.getSigned()
	<< "  |Grade to sign: " << Aform.getGradeToSign()
	<< "  |Grade to execute: " << Aform.getGradeToExecute() << std::endl;
	return os;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (_signed)
		throw AForm::AlreadySignedException();
	if ( _gradeToSign < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << G << bureaucrat.getName() << " signed " << _name << reset << std::endl;
	_signed = true;
}

void AForm::execute(const Bureaucrat & executor) const{
	if (!this->getSigned())
		throw AForm::NotSignedException();
	else if (this->_gradeToExecute < executor.getGrade())
		throw AForm::GradeTooLowException();
	this->getExecuted();
	return ;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Can't be executed because form is not signed!";
}
