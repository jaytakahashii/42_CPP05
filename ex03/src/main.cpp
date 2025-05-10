#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"

int main() {
  try {
    std::cout << BLUE "\n--- Bureaucrat ---\n" RESET << std::endl;

    Bureaucrat bob("Bob", 1);
    std::cout << bob << std::endl;

    std::cout << BLUE "\n--- Forms ---\n" RESET << std::endl;

    ShrubberyCreationForm shrubForm("garden");
    RobotomyRequestForm roboForm("Bender");
    PresidentialPardonForm pardonForm("Ford Prefect");

    std::cout << shrubForm << std::endl;
    std::cout << roboForm << std::endl;
    std::cout << pardonForm << std::endl;

    std::cout << BLUE "\n--- Signing Forms ---\n" RESET << std::endl;

    bob.signForm(shrubForm);
    bob.signForm(roboForm);
    bob.signForm(pardonForm);

    std::cout << shrubForm << std::endl;
    std::cout << roboForm << std::endl;
    std::cout << pardonForm << std::endl;

    std::cout << BLUE "\n--- Executing Forms ---\n" RESET << std::endl;

    shrubForm.execute(bob);
    roboForm.execute(bob);
    pardonForm.execute(bob);

    std::cout << YELLOW "\n--- fin ---\n" RESET << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
