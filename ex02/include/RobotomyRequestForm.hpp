#pragma once

#include <string>

#include "AForm.hpp"

/**
 * RobotomyRequestForm class
 * Required grades: sign 72, exec 45
 * Makes some drilling noises, then informs that <target> has been robotomized
 * successfully 50% of the time. Otherwise, it informs that the robotomy failed.
 */
class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 public:
  // === OCF ===

  RobotomyRequestForm();
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

  // === Constructors ===

  RobotomyRequestForm(const std::string& target);

 protected:
  // === Execute ===

  void execute(Bureaucrat const& executor) const;
};
