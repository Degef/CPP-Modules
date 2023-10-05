#include "./includes/Bureaucrat.hpp"

int main() {
	std::cout << Y << "#1 Test: Creating Form " << reset << std::endl;
	try {
		Form form("Form1", 3, 5);
		std::cout << form;
	} catch (std::exception& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
	// catch (const Form::GradeTooHighException& e) {
	// 	std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	// } catch (const Form::GradeTooLowException& e) {
	// 	std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	// }
	std::cout << std::endl;

	std::cout << Y << "#2 Test: Signing a form with a bureaucrat" << reset << std::endl;
	try {
		Form form("Form1", 19, 5);
		std::cout << form;
		Bureaucrat bureaucrat("Tony", 12);
		std::cout << bureaucrat;
		bureaucrat.signForm(form);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	}
	// catch (const Form::GradeTooHighException& e) {
	// 	std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	// }
	// catch (const Form::GradeTooLowException& e) {
	// 	std::cerr << R << "Exception: " << e.what() << reset << std::endl;
	// }
    return 0;
}
