#pragma once

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Intern {
 public:
  // === OCF ===

  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  // === makeForm ===

  AForm *makeForm(const std::string &formName, const std::string &target) const;

  // === Exceptions ===

  class FormNotFoundException : public std::exception {
    const char *what() const throw();
  };
};
