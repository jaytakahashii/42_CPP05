#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

// === OCF ===

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
  std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {
  std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other) {
  std::cout << "ShrubberyCreationForm: Copy assignment operator called"
            << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

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
  if (executor.getGrade() > this->getExecGrade()) {
    throw GradeTooLowException();
  }
  std::ofstream file(_target + "_shrubbery");
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
