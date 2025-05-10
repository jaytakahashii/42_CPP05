#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

// === OCF ===

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
  std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
  std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
  std::cout << "RobotomyRequestForm: Copy assignment operator called"
            << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// === Constructors ===

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm: Parameterized constructor called"
            << std::endl;
}

// === Execute ===

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->isSigned()) {
    throw NotSignedException();
  }
  if (executor.getGrade() > this->getExecGrade()) {
    throw GradeTooLowException();
  }
  std::cout << "Drilling noises..." << std::endl;
  if (rand() % 2 == 0) {
    std::cout << _target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Robotomy failed for " << _target << "." << std::endl;
  }
}
