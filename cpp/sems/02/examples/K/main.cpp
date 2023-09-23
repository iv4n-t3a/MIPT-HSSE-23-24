#include <iostream>

int GetMaxNumber(int first_number, int second_number) {
  return ((first_number + second_number) + abs(first_number - second_number)) /
         2;
}

int main() {
  int first_number = 0;
  int second_number = 0;
  std::cin >> first_number >> second_number;
  std::cout << GetMaxNumber(first_number, second_number) << std::endl;

  return 0;
}
