/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:55:12 by Degef             #+#    #+#             */
/*   Updated: 2023/10/04 16:29:43 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form",
		ShrubberyCreationForm::gradeToSign, 
		ShrubberyCreationForm::gradeToExecute), 
		_target("Unknown") {
	std::cout << "Shrubbery Creation Form default constructor" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form",
		ShrubberyCreationForm::gradeToSign, 
		ShrubberyCreationForm::gradeToExecute), 
		_target(target) {
	std::cout << "Shrubbery attribute constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : 
		AForm(other), _target(other._target) {
	std::cout << "Shrubbery copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << M << "Shrubbery destructor called" << reset << std::endl;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	this->_target = other._target;
	return (*this);
}

std::string ShrubberyCreationForm::get_target() {
	return _target;
}

void ShrubberyCreationForm::getExecuted() const {
	std::string fileName = _target + "_shrubbery.txt";
    std::ofstream outputFile(fileName.c_str());

    if (outputFile.is_open()) {
        outputFile << _shrubberyArt << std::endl;
        outputFile.close();
        std::cout << "Shrubbery created in file: " << fileName << std::endl;
    } else {
        std::cerr << "Error creating file: " << fileName << std::endl;
    }}
	
std::string const ShrubberyCreationForm::_shrubberyArt = 
"              ,@@@@@@@,\n"
"      ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
"   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
"  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
"  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
"  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"  `&%\\ ` /%&'    |.|        \\ '|8'\n"
"      |o|        | |         | |\n"
"      |.|        | |         | |\n"
"........ ..... ..... ... ............. ..........\n"
"@@@@@@@@@ @@@@@@@@@@ @@@@@@@@@@@@@ @@@ @@@@@@@@\n"
"\n"
"					  .\n"
"			  .\n"
"	           *   * *    \n"
"           *    *  *	*\n"
"      *  *    *     *  *\n"
"     *     *    *  *    *\n"
" * *   *    *    *    *   *\n"
" *     *  *    * * .#  *   *\n"
" *   *     * #.  .# *   *  *\n"
"  *      #.  #: # * *    *\n"
" *   * *  #. ##        *  *\n"
"   *       ###\n"
"            ,##\n"
"              ##.\n"
"              .##:\n"
"              :###\n"
"               ####\n"
"            ,#####\n"
"          .########\n"
"       .%###########\n"
"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";