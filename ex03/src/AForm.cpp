#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"
#include "color.hpp"

// === OCF ===

AForm::AForm()
    : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
  std::cout << "AForm: Default constructor called" << std::endl;
}

AForm::~AForm() {
  std::cout << "AForm: Destructor called" << std::endl;
}

AForm::AForm(const AForm &src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _signGrade(src._signGrade),
      _executeGrade(src._executeGrade) {
  std::cout << "AForm: Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
  std::cout << "AForm: Copy assignment operator called" << std::endl;
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

// === Constructors ===

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name),
      _isSigned(false),
      _signGrade(signGrade),
      _executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1) {
    throw GradeTooHighException();
  } else if (signGrade > 150 || executeGrade > 150) {
    throw GradeTooLowException();
  }
  std::cout << "AForm: Parameterized constructor called" << std::endl;
}

// === Getters ===

const std::string &AForm::getName() const {
  return _name;
}

bool AForm::isSigned() const {
  return _isSigned;
}

int AForm::getSignGrade() const {
  return _signGrade;
}

int AForm::getExecuteGrade() const {
  return _executeGrade;
}

// === Operators ===

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (_isSigned) {
    std::cout << _name << " is already signed." << std::endl;
    return;
  }
  if (bureaucrat.getGrade() > _signGrade) {
    throw GradeTooLowException();
  }
  _isSigned = true;
}

// === Exceptions ===

const char *AForm::GradeTooHighException::what() const throw() {
  return RED "AForm: Grade is too high!" RESET;
}

const char *AForm::GradeTooLowException::what() const throw() {
  return RED "AForm: Grade is too low!" RESET;
}

const char *AForm::NotSignedException::what() const throw() {
  return RED "AForm: Not signed!" RESET;
}

// === Overloads ===

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form: " << form.getName() << ", "
     << "Signed: " << (form.isSigned() ? "Yes" : "No") << ", "
     << "Sign Grade: " << form.getSignGrade() << ", "
     << "Execute Grade: " << form.getExecuteGrade();
  return os;
}
