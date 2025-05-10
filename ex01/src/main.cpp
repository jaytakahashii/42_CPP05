#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "color.hpp"

int main() {
  try {
    std::cout << YELLOW << "=== Bureaucrat ===" << RESET << std::endl;
    Bureaucrat b1("Alice", 50);
    std::cout << b1 << std::endl;

    std::cout << YELLOW << "\n=== Form ===" << RESET << std::endl;
    Form f1("tokyo", 45, 30);
    std::cout << f1 << std::endl;

    std::cout << YELLOW << "\n=== signForm ===" << RESET << std::endl;
    b1.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << YELLOW << "\n=== incrementGrade ===" << RESET << std::endl;
    for (int i = 0; i < 10; ++i)
      b1.incrementGrade();
    std::cout << b1 << std::endl;

    std::cout << YELLOW << "\n=== signForm ===" << RESET << std::endl;
    b1.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << YELLOW << "\n=== fin ===" << RESET << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
