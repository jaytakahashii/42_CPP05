#include "Intern.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"

// === OCF ===

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
  std::cout << "Intern copy constructor called" << std::endl;
  *this = other;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "Intern copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}

Intern::~Intern() {
  std::cout << "Intern destructor called" << std::endl;
}

// === Form creation ===

static AForm *makeShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

static AForm *makePresidential(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  struct FormPair {
    const char *name;
    AForm *(*make)(const std::string &target);
  };

  const FormPair formPairs[] = {
      {SHRUB_FORM, &makeShrubbery},
      {ROBO_FORM, &makeRobotomy},
      {PRES_FORM, &makePresidential},
  };

  for (size_t i = 0; i < sizeof(formPairs) / sizeof(FormPair); ++i) {
    if (formName == formPairs[i].name) {
      std::cout << "Intern creates " << formName << std::endl;
      return formPairs[i].make(target);
    }
  }
  throw FormNotFoundException();
}

// === Exceptions ===

const char *Intern::FormNotFoundException::what() const throw() {
  return RED "Intern: Form not found" RESET;
}
