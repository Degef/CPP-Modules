#ifndef Bureaurat_HPP
#define Bureaurat_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

const std::string reset = "\033[0m";
const std::string R = "\033[31m";
const std::string G = "\033[32m";
const std::string Y = "\033[33m";
const std::string B = "\033[34m";
const std::string M = "\033[35m";
const std::string C = "\033[36m";

class Form;

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
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
	
	class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signForm(Form &form);
};

#endif