#ifndef Intern_hpp
# define Intern_hpp

#include "AForm.hpp"


class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	class FormNotFound : public std::exception {
	public:
		virtual const char* what() const throw(){
			return ("Form not found");
		}
	};

	AForm*	makeForm(std::string formName, std::string target);
private:
	typedef struct sformList {
		std::string name;
		AForm* (*function)(std::string const &);
	} formList;
};

#endif