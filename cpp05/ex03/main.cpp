/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:59 by Degef             #+#    #+#             */
/*   Updated: 2023/10/05 11:04:25 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/Intern.hpp"

void makeTestes(std::string formName, std::string target, Bureaucrat b1)
{
	try
	{
		Intern someRandomIntern = Intern();
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm(formName, target);
		
		std::cout << *rrf;
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception& e)
	{
		std::cout << R << e.what() << reset << std::endl;
	}
}

int main()
{
	std::cout << Y << "#Test1" << "ShrubberyCreationForm" << reset << std::endl;
	try {
		Bureaucrat b3 = Bureaucrat("B3", 100);
		makeTestes("shrubbery creation", "school", b3);
	} catch (std::exception& e) {
		std::cout << R << e.what() << reset << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << Y << "#Test2" << "PresidentialPardonForm" << reset << std::endl;
	try {
		Bureaucrat b2 = Bureaucrat("B2", 10);
		makeTestes("Form doesn't exist", "Bender", b2);
	} catch (std::exception& e) {
		std::cout << R << e.what() << reset << std::endl;
	}
	std::cout << std::endl;
	
	// std::cout << Y << "#Test3" << "RobotomyRequestForm" << reset << std::endl;
	// try
	// {
	// 	Bureaucrat b1 = Bureaucrat("B1", 70);
	// 	makeTestes("robotomy request", "Bender", b1);
	// }
	// catch (std::exception& e)
	// {
	// 	std::cout << R << e.what() << reset << std::endl;
	// }
	// std::cout << std::endl;
	
	return 0;
}
