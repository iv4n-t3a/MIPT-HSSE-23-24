#include <iostream>

int main() {
  int first_number = 0;
  int second_number = 0;
  std::cin >> first_number >> second_number;
  std::cout << ((second_number % first_number) *
                (first_number % second_number)) +
                   1
            << std::endl;

  return 0;
}
