#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form",
		ShrubberyCreationForm::gradeToSign, 
		ShrubberyCreationForm::gradeToExecute), 
		_target("Unknown") {
	std::cout << "Shrubbery Creation Form default constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form",
		ShrubberyCreationForm::gradeToSign, 
		ShrubberyCreationForm::gradeToExecute), 
		_target(target) {
	std::cout << "Shrubbery attribute constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : 
		AForm(other), _target(other._target) {
	std::cout << "Shrubbery copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	this->_target = other._target;
	return (*this);
}

std::string ShrubberyCreationForm::get_target() {
	return _target;
}

void ShrubberyCreationForm::getExecuted() const {
	std::cout << G  << "Shrubbery Form Executed  " << reset << std::endl;
}
