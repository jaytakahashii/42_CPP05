#pragma once

#include <string>

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  // === OCF ===

  Bureaucrat();
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat &operator=(const Bureaucrat &src);

  // === Constructors ===

  Bureaucrat(const std::string &name, int grade);

  // === Getters ===

  const std::string &getName() const;
  int getGrade() const;

  // === Operators ===

  void incrementGrade();
  void decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
