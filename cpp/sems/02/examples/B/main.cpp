#include <cmath>
#include <iostream>

int main() {
  int first_kathet = 0;
  int second_kathet = 0;
  std::cin >> first_kathet >> second_kathet;
  double result =
      std::sqrt(first_kathet * first_kathet + second_kathet * second_kathet);
  std::cout << result << std::endl;

  return 0;
}
