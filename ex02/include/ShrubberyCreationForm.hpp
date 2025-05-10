#pragma once

#include <string>

#include "AForm.hpp"

/**
 * ShrubberyCreationForm class
 * Required grades: sign 145, exec 137
 * Creates a file <target>_shrubbery in the working directory and writes ASCII
 * trees inside it.
 */
class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

 public:
  // === OCF ===

  ShrubberyCreationForm();
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

  // === Constructors ===

  ShrubberyCreationForm(const std::string& target);

 protected:
  void execute(Bureaucrat const& executor) const;

 public:
  // === Exceptions ===

  class FileOpenException : public std::exception {
   public:
    const char* what() const throw() {
      return "Error: Could not open file for writing";
    }
  };
};
