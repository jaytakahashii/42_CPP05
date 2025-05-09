#include <iostream>

#include "Bureaucrat.hpp"
#include "color.hpp"

int main() {
  std::cout << YELLOW << "=== increment ===" << RESET << std::endl;
  try {
    Bureaucrat bureaucrat("John Doe", 1);
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << YELLOW << "=== decrement ===" << RESET << std::endl;
  try {
    Bureaucrat bureaucrat("Jane Doe", 150);
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
