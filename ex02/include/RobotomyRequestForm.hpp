#pragma once

#include <string>

#include "AForm.hpp"

/**
 * Required grades: sign 72, exec 45
 * Makes some drilling noises, then informs that <target> has been robotomized
 * successfully 50% of the time. Otherwise, it informs that the robotomy failed.
 */
class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 public:
  // === Constructors ===

  RobotomyRequestForm(const std::string& target);

  // === execute ===

  virtual void execute(Bureaucrat const& executor) const;
};
