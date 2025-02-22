/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:49:38 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/22 20:20:13 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm()
{
	
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm",false,145,137),_target(target) 
{
	
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shr):AForm(shr)
{
	(void)shr;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shr)
{
	(void)shr;
	return *this;
}

void ShrubberyCreationForm::action() const
{
	std::string filename =this->_target + "_shrubbery";
	std::ofstream  outfile(filename.c_str());
	if (!outfile) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return ;
    }
	outfile << "     *     " << std::endl;
    outfile << "    ***    " << std::endl;
    outfile << "   *****   " << std::endl;
    outfile << "  *******  " << std::endl;
    outfile << " ********* " << std::endl;
    outfile << "    ***    " << std::endl;
    outfile << "    ***    " << std::endl;
    outfile << std::endl;
    outfile << "      *      " << std::endl;
    outfile << "     ***     " << std::endl;
    outfile << "    *****    " << std::endl;
    outfile << "   *******   " << std::endl;
    outfile << "  *********  " << std::endl;
    outfile << " *********** " << std::endl;
    outfile << "     ***     " << std::endl;
    outfile << "     ***     " << std::endl;
    outfile << std::endl;
    outfile << "       *       " << std::endl;
    outfile << "      ***      " << std::endl;
    outfile << "     *****     " << std::endl;
    outfile << "    *******    " << std::endl;
    outfile << "   *********   " << std::endl;
    outfile << "  ***********  " << std::endl;
    outfile << " ************* " << std::endl;
    outfile << "      ***      " << std::endl;
    outfile << "      ***      " << std::endl;
	outfile.close();
    
}

