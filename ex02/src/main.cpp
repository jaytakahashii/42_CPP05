#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Bureaucrat bob("Bob", 1);
    Bureaucrat jim("Jim", 140);
    Bureaucrat alice("Alice", 50);

    ShrubberyCreationForm shrubForm("garden");
    RobotomyRequestForm roboForm("Bender");
    PresidentialPardonForm pardonForm("Ford Prefect");

    std::cout << "\n--- Signing Forms ---\n" << std::endl;

    bob.signForm(shrubForm);
    bob.signForm(roboForm);
    bob.signForm(pardonForm);

    std::cout << "\n--- Executing Forms with Insufficient Grade ---\n"
              << std::endl;

    shrubForm.execute(jim);
    roboForm.execute(jim);
    pardonForm.execute(jim);

    std::cout << "\n--- Executing Forms with Sufficient Grade ---\n"
              << std::endl;

    shrubForm.execute(bob);
    roboForm.execute(bob);
    pardonForm.execute(bob);

    std::cout << "\n--- Executing Forms with Intermediate Grade ---\n"
              << std::endl;

    shrubForm.execute(alice);
    roboForm.execute(alice);
    pardonForm.execute(alice);

    std::cout << "\n--- Attempting to Sign Forms with Insufficient Grade ---\n"
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
