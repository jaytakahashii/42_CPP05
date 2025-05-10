#pragma once

#include <string>

#include "AForm.hpp"

/**
 * Required grades: sign 145, exec 137
 * Creates a file <target>_shrubbery in the working directory and writes ASCII
 * trees inside it.
 */
class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

 public:
  // === Constructors ===

  ShrubberyCreationForm(const std::string& target);

  // === execute ===

  void execute(Bureaucrat const& executor) const;

  // === Exceptions ===

  class FileOpenException : public std::exception {
   public:
    const char* what() const throw() {
      return "Error: Could not open file for writing";
    }
  };

  // === destructor ===

  ~ShrubberyCreationForm();
};
