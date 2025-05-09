#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat b1("Alice", 50);
    Form f1("tokyo", 45, 30);

    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;

    b1.signForm(f1);  // 署名失敗（grade不足）
    for (int i = 0; i < 10; ++i)
      b1.incrementGrade();

    std::cout << b1 << std::endl;
    b1.signForm(f1);  // 署名成功
    std::cout << f1 << std::endl;

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
