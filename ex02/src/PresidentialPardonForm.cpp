#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"

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
  if (executor.getGrade() > this->getExecuteGrade()) {
    throw GradeTooLowException();
  }
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
