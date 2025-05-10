#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"

// === Constructors ===

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm: Parameterized constructor called"
            << std::endl;
}

// === Execute ===

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->isSigned()) {
    throw NotSignedException();
  }
  if (executor.getGrade() > this->getExecuteGrade()) {
    throw GradeTooLowException();
  }
  std::ofstream file((_target + "_shrubbery").c_str());
  if (!file) {
    throw FileOpenException();
  }
  file << "       _-_\n"
          "    /~~   ~~\\\n"
          " /~~         ~~\\\n"
          "{               }\n"
          " \\             /\n"
          "   \\_________/\n";
  file.close();
  std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;
}
