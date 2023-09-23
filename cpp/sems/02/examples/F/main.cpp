#include <iostream>

int GetNextEventNumber(int current_number) {
  return current_number + (current_number % 2 == 0 ? 2 : 1);
}

int main() {
  int current_number = 0;
  std::cin >> current_number;
  std::cout << current_number + (2 - current_number % 2) << std::endl;
  std::cout << GetNextEventNumber(current_number) << std::endl;

  return 0;
}