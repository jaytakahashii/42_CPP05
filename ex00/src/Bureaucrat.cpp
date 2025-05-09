#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

#include "color.hpp"

// === OCF ===

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
  std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {
  std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  std::cout << "Copy assignment operator called" << std::endl;
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
  std::cout << "Parameterized constructor called" << std::endl;
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

// === Exceptions ===

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return RED "Grade too high" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return RED "Grade too low" RESET;
}

// === Overloads ===

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}
