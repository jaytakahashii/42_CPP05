#include "PresidentialPardonForm.hpp"

#include <iostream>

// === OCF ===

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Default") {
  std::cout << "PresidentialPardonForm: Default constructor called"
            << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {
  std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other) {
  std::cout << "PresidentialPardonForm: Copy assignment operator called"
            << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// === Constructors ===

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm: Parameterized constructor called"
            << std::endl;
}

// === Execute ===

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->isSigned()) {
    throw NotSignedException();
  }
  if (executor.getGrade() > this->getExecGrade()) {
    throw GradeTooLowException();
  }
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
