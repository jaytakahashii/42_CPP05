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
  AForm::execute(executor);
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

// === Destructor ===

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}
