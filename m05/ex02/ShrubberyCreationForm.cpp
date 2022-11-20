/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 22:27:20 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("ShrubberyCreation", 145, 137), target_("Company")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreation", 145, 137), target_(target)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
	: Form(obj), target_(obj.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	if (this != &obj)
	{
		Form::operator=(obj);
		std::cout << "ShrubberyCreationForm Copy assignment operator called" \
			<< std::endl;
		target_ = obj.getTarget();
	}
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (target_);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkFormForExec(executor);
	std::ofstream	out_file;
	out_file.open(target_ + "_shrubbery", std::ios_base::out);
	if (out_file.is_open() == false)
	{
		std::cerr << target_ << ": failed to open output file" << std::endl;
		return ;
	}
	out_file << "                                              ." << std::endl \
		<< "                                   .         ;" << std::endl \
		<< "      .              .              ;%     ;;" << std::endl \
		<< "        ,           ,                :;%  %;" << std::endl \
		<< "         :         ;                   :;%;'     .," << std::endl \
		<< ",.        %;     %;            ;        %;'    ,;" << std::endl \
		<< "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl \
		<< "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl \
		<< "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl \
		<< "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl \
		<< "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl \
		<< "         `:%;.  :;bd%;          %;@%;'" << std::endl \
		<< "           `@%:.  :;%.         ;@@%;'" << std::endl \
		<< "             `@%.  `;@%.      ;@@%;" << std::endl \
		<< "               `@%%. `@%%    ;@@%;" << std::endl \
		<< "                 ;@%. :@%%  %@@%;" << std::endl \
		<< "                   %@bd%%%bd%%:;" << std::endl \
		<< "                     #@%%%%%:;;" << std::endl \
		<< "                     %@@%%%::;" << std::endl \
		<< "                     %@@@%(o);  . '" << std::endl \
		<< "                     %@@@o%;:(.,'" << std::endl \
		<< "                 `.. %@@@o%::;" << std::endl \
		<< "                    `)@@@o%::;" << std::endl \
		<< "                     %@@(o)::;" << std::endl \
		<< "                    .%@@@@%::;" << std::endl \
		<< "                    ;%@@@@%::;." << std::endl \
		<< "                   ;%@@@@%%:;;;." << std::endl \
		<< "               ...;%@@@@@%%:;;;;,.." << std::endl;
	out_file.close();
	return ;
}
