/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:04 by Degef             #+#    #+#             */
/*   Updated: 2023/10/04 16:29:18 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form",
		PresidentialPardonForm::gradeToSign, 
		PresidentialPardonForm::gradeToExecute), 
		_target("Unknown") {
	std::cout << "Presidential Pardon Form default constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form",
		PresidentialPardonForm::gradeToSign, 
		PresidentialPardonForm::gradeToExecute), 
		_target(target) {
	std::cout << "Presidential Pardon form attribute constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : 
		AForm(other), _target(other._target) {
	std::cout << "Presidential Pardon form copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << M << "Presidential Pardon form destructor called" << reset << std::endl;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	this->_target = other._target;
	return (*this);
}

std::string PresidentialPardonForm::get_target() {
	return _target;
}

void PresidentialPardonForm::getExecuted() const {
	std::cout << C << _target << " has been pardoned by Zaphod Beeblebrox. " << reset << std::endl;
}
