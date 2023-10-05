/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:54:27 by Degef             #+#    #+#             */
/*   Updated: 2023/10/05 17:58:21 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_hpp
#define AForm_hpp

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high! ";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	std::string		getName() const;
	bool 			getSigned() const;
	int 			getGradeToSign() const;
	int 			getGradeToExecute() const;

	void 			beSigned(Bureaucrat& bureaucrat);
	void			execute(Bureaucrat const & executor) const;
protected:
	virtual void	getExecuted() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif