#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	static int const	gradeToSign = 72;
	static int const	gradeToExecute = 45;

	std::string 	get_target();
	void			getExecuted() const;
};

#endif