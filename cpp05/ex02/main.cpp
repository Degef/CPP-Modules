#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat	lowlyBureaucrat("High Hank", 142);
	Bureaucrat	averageBureaucrat("Average Alice", 65);
	Bureaucrat	highBureaucrat("Low Lucy", 6);

	std::cout << Y << "Bureaucrats for testing " << reset << std::endl;
	std::cout << lowlyBureaucrat;
	std::cout << averageBureaucrat;
	std::cout << highBureaucrat;

	ShrubberyCreationForm	shrubbery("home");
	RobotomyRequestForm		robotomy("office");
	PresidentialPardonForm	pardonform("Citizen");

	std::cout << Y << "Forms for testing " << reset << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardonform;

	std::cout << Y << "#1 Test testing shrubbery form " << reset << std::endl;
	lowlyBureaucrat.signForm(shrubbery);
	lowlyBureaucrat.executeForm(shrubbery);
	averageBureaucrat.signForm(shrubbery);
	averageBureaucrat.executeForm(shrubbery);

	std::cout << Y << "#2 TestTesting robotomy form " << reset << std::endl;
	averageBureaucrat.signForm(robotomy);
	averageBureaucrat.executeForm(robotomy);
	highBureaucrat.signForm(robotomy);
	highBureaucrat.executeForm(robotomy);

	std::cout << Y << "#3 Test testing pardon form " << reset << std::endl;
	averageBureaucrat.signForm(pardonform);
	averageBureaucrat.executeForm(pardonform);
	highBureaucrat.signForm(pardonform);
	highBureaucrat.executeForm(pardonform);

	std::cout << std::endl;
    return 0;
}
