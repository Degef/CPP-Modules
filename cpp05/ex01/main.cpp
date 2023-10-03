#include "Bureaucrat.hpp"

void createBureaucrat(std::string name, int grade)
{
	std::cout << "creating a bureaucrat named " << name << " with grade " << grade << std::endl;
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
}

int main() {
	std::cout << Y << "#1 Test: Creating Form " << reset << std::endl;
	try {
		Form form("Form1", 10, 5);
		std::cout << form;
	} catch (const Form::GradeTooHighException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
	std::cout << std::endl;
	std::cout << Y << "#2 Test: Signing a form with a bureaucrat" << reset << std::endl;
	try {
		Form form("Form1", 10, 5);
		std::cout << form;
		Bureaucrat bureaucrat("Bureaucrat1", 10);
		std::cout << bureaucrat;
		bureaucrat.signForm(form);
	}
	catch (const Form::GradeTooHighException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
	std::cout << std::endl;
	std::cout << Y << "#3 Test: Signing a form with a bureaucrat" << reset << std::endl;
	try {
		Form form("Form1", 10, 5);
		std::cout << form;
		Bureaucrat bureaucrat("Bureaucrat1", 5);
		std::cout << bureaucrat;
		form.beSigned(bureaucrat);
	}
	catch (const Form::GradeTooHighException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
    return 0;
}
