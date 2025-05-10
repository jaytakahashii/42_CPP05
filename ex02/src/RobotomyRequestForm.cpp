#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"

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
  if (executor.getGrade() > this->getExecuteGrade()) {
    throw GradeTooLowException();
  }
  std::cout << "Drilling noises..." << std::endl;
  if (rand() % 2 == 0) {
    std::cout << _target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Robotomy failed for " << _target << "." << std::endl;
  }
}
