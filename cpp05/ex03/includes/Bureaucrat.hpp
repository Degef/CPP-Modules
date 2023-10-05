/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:32 by Degef             #+#    #+#             */
/*   Updated: 2023/10/05 17:59:30 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaurat_HPP
#define Bureaurat_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

const std::string reset = "\033[0m";
const std::string R = "\033[31m";
const std::string G = "\033[32m";
const std::string Y = "\033[33m";
const std::string B = "\033[34m";
const std::string M = "\033[35m";
const std::string C = "\033[36m";

class AForm;

class Bureaucrat {
private:
    std::string const _name;
	int _grade;

public:
    Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
	
	class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high! can't outrank the president!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low! you cannot be lower than intern!";
        }
    };

	class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form can't be executed because it is not signed";
        }
	};

    std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form);
	void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif