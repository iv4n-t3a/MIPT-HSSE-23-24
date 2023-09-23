#include <iostream>

int main() {
  int first_number = 0;
  int second_nuimber = 0;
  int max_number = 0;

  std::cin >> first_number >> second_nuimber;
  max_number = first_number - ((first_number - second_nuimber) &
                               ((first_number - second_nuimber) >>
                                (sizeof(int) * __CHAR_BIT__ - 1)));
  std::cout << max_number << std::endl;

  return 0;
}
