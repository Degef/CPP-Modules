#include "PresidentialPardonForm.hpp"

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
	std::cout << "Presidential Pardon form destructor called" << std::endl;
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
	std::cout << "Presidential Pardon Form Executed " << std::endl;
}
