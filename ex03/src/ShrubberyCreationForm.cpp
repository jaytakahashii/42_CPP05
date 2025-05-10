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
  AForm::execute(executor);
  std::ofstream file((_target + "_shrubbery").c_str());
  if (!file) {
    throw FileOpenException();
  }
  file << "\n"
          "         ^\n"
          "        ^^^\n"
          "       ^^^^^\n"
          "      ^^^^^^^\n"
          "     ^^^^^^^^^\n"
          "    ^^^^^^^^^^^\n"
          "   ^^^^^^^^^^^^^\n"
          "  ^^^^^^^^^^^^^^^\n"
          "        |||\n"
          "        |||\n"
          "        |||"
       << std::endl;

  file.close();
  std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;
}

// === Destructor ===

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}
