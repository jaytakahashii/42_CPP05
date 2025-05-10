#pragma once

#include <string>

#include "AForm.hpp"

/**
 * Required grades: sign 25, exec 5
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.
 */
class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 public:
  // === Constructors ===

  PresidentialPardonForm(const std::string& target);

  // === Execute ===

  virtual void execute(Bureaucrat const& executor) const;
};
