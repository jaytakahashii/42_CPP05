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
  std::cout << CYAN << "Intern default constructor called" << RESET
            << std::endl;
}

Intern::Intern(const Intern &other) {
  std::cout << CYAN << "Intern copy constructor called" << RESET << std::endl;
  *this = other;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << CYAN << "Intern copy assignment operator called" << RESET
            << std::endl;
  (void)other;
  return *this;
}

Intern::~Intern() {
  std::cout << CYAN << "Intern destructor called" << RESET << std::endl;
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
      std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
      return formPairs[i].make(target);
    }
  }

  throw FormNotFoundException();
}

// === Exceptions ===

const char *Intern::FormNotFoundException::what() const throw() {
  return "Intern: Form not found";
}
