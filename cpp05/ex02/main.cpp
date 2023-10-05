/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:59 by Degef             #+#    #+#             */
/*   Updated: 2023/10/05 14:53:46 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

int main() {
	try
	{
		std::cout << Y << "Bureaucrats for testing " << reset << std::endl;
		Bureaucrat	lowlyBureaucrat("Low Lucy", 142);
		Bureaucrat	averageBureaucrat("Average Alice", 65);
		Bureaucrat	highBureaucrat("High Hank", 3);

		std::cout << lowlyBureaucrat;
		std::cout << averageBureaucrat;
		std::cout << highBureaucrat;
		std::cout << std::endl;

		std::cout << Y << "Forms for testing " << reset << std::endl;
		ShrubberyCreationForm	shrubbery("home");
		RobotomyRequestForm		robotomy("office");
		PresidentialPardonForm	pardonform("Citizen");

		std::cout << shrubbery;
		std::cout << robotomy;
		std::cout << pardonform;
		std::cout << std::endl;

		std::cout << Y << "#1 Test testing shrubbery form " << reset << std::endl;
		lowlyBureaucrat.signForm(shrubbery);
		lowlyBureaucrat.executeForm(shrubbery);
		averageBureaucrat.signForm(shrubbery);
		averageBureaucrat.executeForm(shrubbery);
		std::cout << std::endl;

		std::cout << Y << "#2 TestTesting robotomy form " << reset << std::endl;
		averageBureaucrat.signForm(robotomy);
		averageBureaucrat.executeForm(robotomy);
		highBureaucrat.signForm(robotomy);
		highBureaucrat.executeForm(robotomy);
		std::cout << std::endl;
		
		std::cout << Y << "#3 Test testing pardon form " << reset << std::endl;
		averageBureaucrat.signForm(pardonform);
		averageBureaucrat.executeForm(pardonform);
		highBureaucrat.signForm(pardonform);
		highBureaucrat.executeForm(pardonform);
		 
	}
	catch(const std::exception& e)
	{
		std::cerr<< R << e.what() << reset << '\n';
	}

	std::cout << std::endl;
    return 0;
}
