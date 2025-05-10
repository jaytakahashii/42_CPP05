#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "color.hpp"

int main() {
  try {
    std::cout << BLUE "\n--- Bureaucrat ---" RESET << std::endl;
    Bureaucrat bob("Bob", 1);
    std::cout << bob << std::endl;

    std::cout << BLUE "\n--- Forms ---" RESET << std::endl;
    ShrubberyCreationForm shrubForm("tree");
    RobotomyRequestForm roboForm("robot");
    PresidentialPardonForm pardonForm("pardon");

    std::cout << shrubForm << std::endl;
    std::cout << roboForm << std::endl;
    std::cout << pardonForm << std::endl;

    std::cout << BLUE "\n--- Signing Forms ---" RESET << std::endl;

    bob.signForm(shrubForm);
    bob.signForm(roboForm);
    bob.signForm(pardonForm);

    std::cout << shrubForm << std::endl;
    std::cout << roboForm << std::endl;
    std::cout << pardonForm << std::endl;

    std::cout << BLUE "\n--- Executing Forms ---" RESET << std::endl;
    bob.executeForm(shrubForm);
    bob.executeForm(roboForm);
    bob.executeForm(pardonForm);

    std::cout << YELLOW "\n--- fin ---" RESET << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
