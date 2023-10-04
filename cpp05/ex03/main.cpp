/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:59 by Degef             #+#    #+#             */
/*   Updated: 2023/10/04 19:40:10 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/Intern.hpp"

int main()
{
	{
		Intern someRandomIntern = Intern();
		Bureaucrat b1 = Bureaucrat("B1", 1);
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		delete rrf;
	}
	return 0;
}
