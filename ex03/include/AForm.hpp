#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

#define SHRUB_FORM "shrubbery creation"
#define ROBO_FORM "robotomy request"
#define PRES_FORM "presidential pardon"

class AForm {
 private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _executeGrade;

 public:
  // === OCF ===

  AForm();
  virtual ~AForm();
  AForm(const AForm &src);
  AForm &operator=(const AForm &src);

  // === Constructors ===

  AForm(const std::string &name, int signGrade, int executeGrade);

  // === Getters ===

  const std::string &getName() const;
  bool isSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  // === Operators ===

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  // === Exceptions ===

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };

  class NotSignedException : public std::exception {
   public:
    const char *what() const throw();
  };
};

// === Overloads ===

std::ostream &operator<<(std::ostream &os, const AForm &form);
