#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
 private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _executeGrade;

 public:
  // === OCF ===

  AForm();
  ~AForm();
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

  // === Exceptions ===

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };
};

// === Overloads ===

std::ostream &operator<<(std::ostream &os, const AForm &form);
