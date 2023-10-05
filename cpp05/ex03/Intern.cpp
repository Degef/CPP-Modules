#include "./includes/Intern.hpp"
#include "./includes/AForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return (*this);
}

Intern::~Intern() {
	std::cout << M << "Intern destructor called" << reset << std::endl;
}

static AForm* createRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
}

static AForm* createPresidentialPardonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
}

static AForm* createShrubberyCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string target) {
	AForm*	form = NULL;

	static formList const forms[] = {
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm},
		{"shrubbery creation", createShrubberyCreationForm}
	};

	std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	int i = -1;
	while (++i < 3) {
		if (formName == formNames[i]) {
			form = forms[i].function(target);
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
	}
	throw FormNotFound();
}
