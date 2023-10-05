#include "./includes/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), 
		_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), 
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
	std::cout<< M << "Form destructor called" << reset << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form name: " << form.getName() << "  |Form signed: " << form.getSigned()
	<< "  |Form grade to sign: " << form.getGradeToSign()
	<< "  |Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	std::cout << "Trying to sign form " << _name << " with bureaucrat " << bureaucrat.getName() << std::endl;
	if (_signed)
		throw Form::AlreadySignedException();
	if ( _gradeToSign < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	std::cout << C << bureaucrat.getName() << " signed " << _name << reset << std::endl;
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high! ";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Form is already signed!";
}
