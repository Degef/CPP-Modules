/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:08 by Degef             #+#    #+#             */
/*   Updated: 2023/10/04 16:29:02 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Creation Form",
		RobotomyRequestForm::gradeToSign, 
		RobotomyRequestForm::gradeToExecute), 
		_target("Unknown") {
	std::cout << "Robotomy Creation Form default constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Creation Form",
		RobotomyRequestForm::gradeToSign, 
		RobotomyRequestForm::gradeToExecute), 
		_target(target) {
	std::cout << "Robotomy attribute constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : 
		AForm(other), _target(other._target) {
	std::cout << "Robotomy copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout<< M << "Robotomy destructor called" << reset << std::endl;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->_target = other._target;
	return (*this);
}

std::string RobotomyRequestForm::get_target() {
	return _target;
}

void RobotomyRequestForm::getExecuted() const {
	std::cout << "* kzzzzt... drilling noises... bip bip bip... clang! *" << std::endl;
	std::srand(static_cast<unsigned>(std::time(0)));
	if (std::rand() % 2 == 0) {
		std::cout << C << _target << " has been robotomized successfully!" << reset << std::endl;
	}
	else {
		std::cout << C << _target << " robotomization failed!" << reset << std::endl;
	}
}
