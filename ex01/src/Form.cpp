#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"
#include "color.hpp"

// === OCF ===

Form::Form()
    : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
  std::cout << "Form: Default constructor called" << std::endl;
}

Form::~Form() {
  std::cout << "Form: Destructor called" << std::endl;
}

Form::Form(const Form &src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _signGrade(src._signGrade),
      _executeGrade(src._executeGrade) {
  std::cout << "Form: Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src) {
  std::cout << "Form: Copy assignment operator called" << std::endl;
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  return *this;
}

// === Constructors ===

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name),
      _isSigned(false),
      _signGrade(signGrade),
      _executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1) {
    throw GradeTooHighException();
  } else if (signGrade > 150 || executeGrade > 150) {
    throw GradeTooLowException();
  }
  std::cout << "Form: Parameterized constructor called" << std::endl;
}

// === Getters ===

const std::string &Form::getName() const {
  return _name;
}

bool Form::isSigned() const {
  return _isSigned;
}

int Form::getSignGrade() const {
  return _signGrade;
}

int Form::getExecuteGrade() const {
  return _executeGrade;
}

// === Operators ===

void Form::beSigned(const Bureaucrat &bureaucrat) {
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

const char *Form::GradeTooHighException::what() const throw() {
  return RED "Form: Grade is too high!" RESET;
}

const char *Form::GradeTooLowException::what() const throw() {
  return RED "Form: Grade is too low!" RESET;
}

// === Overloads ===

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form: " << form.getName() << ", "
     << "Signed: " << (form.isSigned() ? "Yes" : "No") << ", "
     << "Sign Grade: " << form.getSignGrade() << ", "
     << "Execute Grade: " << form.getExecuteGrade();
  return os;
}
