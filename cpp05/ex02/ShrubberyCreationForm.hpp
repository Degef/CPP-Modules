#ifndef ShrubberyCreationForm_hpp
#define ShrubberyCreationForm_hpp

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	static int const	gradeToSign = 145;
	static int const	gradeToExecute = 137;

	std::string 	get_target();
	void			getExecuted() const;
};

#endif