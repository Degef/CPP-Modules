/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:53 by Degef             #+#    #+#             */
/*   Updated: 2023/10/04 16:31:03 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
		std::cout << "Bureaucrat constructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat copy assignment operator overload called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << M << "Bureaucrat destructor called" << reset << std::endl;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	std::cout << "trying to incrementing bureaucrat " << _name << " with grade " << _grade << std::endl;
	if (_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		_grade--;
		std::cout << "Bureaucrat " << _name << " incremented to grade " << _grade << std::endl;
	}
}

void Bureaucrat::decrementGrade() {
	std::cout << "Trying to decrement bureaucrat " << _name << " with grade " << _grade << std::endl;
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		_grade++;
		std::cout << "Bureaucrat " << _name << " decremented to grade " << _grade << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(AForm &form) {
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << R << _name << " couldn’t sign " << form.getName() 
					<< " because " << e.what() << reset << '\n';
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try
	{
		form.execute(*this);
		std::cout << C << _name << " executed " << form.getName() << reset << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << R << _name << " can't execute form because " << e.what() << reset << '\n';
	}
}
