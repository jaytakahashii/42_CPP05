#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"

int main() {
  AForm *rrf;
  try {
    std::cout << YELLOW << "=== Intern ===" << RESET << std::endl;
    Intern someRandomIntern;

    std::cout << YELLOW << "\n=== ShrubberyCreationForm ===" << RESET
              << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << *rrf << std::endl;

    std::cout << YELLOW << "\n=== Bureaucrat ===" << RESET << std::endl;
    Bureaucrat bender("Bender", 1);
    std::cout << bender << std::endl;

    std::cout << YELLOW << "\n=== Signing Form ===" << RESET << std::endl;
    bender.signForm(*rrf);
    std::cout << *rrf << std::endl;

    std::cout << YELLOW << "\n=== Executing Form ===" << RESET << std::endl;
    bender.executeForm(*rrf);

    std::cout << YELLOW << "\n=== Deleting Form ===" << RESET << std::endl;
    delete rrf;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
