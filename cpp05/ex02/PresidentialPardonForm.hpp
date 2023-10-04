#ifndef PresidentialPardonForm_hpp
#define PresidentialPardonForm_hpp

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	static int const	gradeToSign = 25;
	static int const	gradeToExecute = 5;

	std::string 	get_target();
	void			getExecuted() const;
};

#endif