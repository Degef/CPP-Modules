#include "./includes/Bureaucrat.hpp"

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
	// std::cout << Y << "#1 Test: default constructor" << reset << std::endl;
	// {
	// 	Bureaucrat bureaucrat;
	// 	std::cout << bureaucrat;
	// }
	// std::cout << std::endl;
	
	// std::cout << Y << "#2 Test: attributed constructor" << reset << std::endl;
	// createBureaucrat("Tony", 1);
	// createBureaucrat("Jesse", 0);
	// std::cout << std::endl;

	// std::cout << Y << "#3 Test: copy constructor" << reset << std::endl;
	// {
	// 	Bureaucrat bureaucrat("Tony", 1);
	// 	Bureaucrat bureaucrat2(bureaucrat);
	// 	std::cout << bureaucrat2;
	// }
	// std::cout << std::endl;
	// std::cout << Y << "#4 Test: copy assignment operator overload" << reset << std::endl;
	// {
	// 	Bureaucrat bureaucrat("Tony", 1);
	// 	Bureaucrat bureaucrat2("Jesse", 150);
	// 	std::cout << bureaucrat2;
	// 	bureaucrat2 = bureaucrat;
	// 	std::cout << bureaucrat2;
	// }
	// std::cout << std::endl;

	std::cout << Y << "#1 Test: IncrementGrade" << reset << std::endl;
	{
		Bureaucrat bureaucrat("Tony", 2);
		try
		{
			std::cout << bureaucrat;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat;
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cerr << R << "Exception: " << e.what() << reset << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << Y << "#2 Test: DecrementGrade" << reset << std::endl;
	{
		Bureaucrat bureaucrat("Jesse", 149);
		try
		{
			std::cout << bureaucrat;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat;
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cerr << R << "Exception: " << e.what() << reset << std::endl;
		}
	}
    return 0;
}
