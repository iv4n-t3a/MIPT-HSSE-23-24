#include <iostream>

int main() {
  std::cout << "Input two numbers throughs a space" << std::endl;
  int first_number = 0;
  int second_number = 0;
  std::cin >> first_number >> second_number;
  std::cout << "Sum of two numbers: " << first_number + second_number
            << std::endl;

  return 0;
}
