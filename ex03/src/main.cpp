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
    Intern someRandomIntern;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
      Bureaucrat bender("Bender", 1);
      bender.signForm(*rrf);
      rrf->execute(bender);
      delete rrf;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    delete rrf;
  }

  return 0;
}
