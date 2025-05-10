#pragma once

#include <string>

#include "AForm.hpp"

/**
 * PresidentialPardonForm class
 * Required grades: sign 25, exec 5
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.
 */
class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 public:
  // === OCF ===

  PresidentialPardonForm();
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

  // === Constructors ===

  PresidentialPardonForm(const std::string& target);

 protected:
  // === Execute ===

  void execute(Bureaucrat const& executor) const;
};
