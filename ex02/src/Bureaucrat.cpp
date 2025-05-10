#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

#include "AForm.hpp"
#include "color.hpp"

// === OCF ===

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
  std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat: Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {
  std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
  if (this != &src) {
    _grade = src._grade;
  }
  return *this;
}

// === Constructors ===

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
  std::cout << "Bureaucrat: Parameterized constructor called" << std::endl;
}

// === Getters ===

const std::string &Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

// === Operators ===

void Bureaucrat::incrementGrade() {
  if (_grade <= 1) {
    throw GradeTooHighException();
  }
  --_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150) {
    throw GradeTooLowException();
  }
  ++_grade;
}

void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << _name << " couldn't sign " << form.getName()
              << " because " << e.what() << RESET << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << _name << " couldn't execute " << form.getName()
              << " because " << e.what() << RESET << std::endl;
  }
}

// === Exceptions ===

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return RED "Bureaucrat: Grade too high" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return RED "Bureaucrat: Grade too low" RESET;
}

// === overloads ===

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}
