#include "RobotomyRequestForm.hpp"

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
	std::cout << "Robotomy destructor called" << std::endl;
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
	std::cout << G << "Robotomy Form Executed " << reset << std::endl;
}
