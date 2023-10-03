#include "Bureaucrat.hpp"

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
	std::cout << "Bureaucrat destructor called" << std::endl;
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

// Overload of << operator for output
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
