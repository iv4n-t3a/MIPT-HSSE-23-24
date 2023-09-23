#include <iostream>

int main() {
  int heigth = 0;
  int up_distance = 0;
  int down_distance = 0;
  std::cin >> heigth >> up_distance >> down_distance;
  int first_height = heigth - up_distance;

  int step = up_distance - down_distance;
  std::cout << 1 + first_height / step + (first_height % step + step - 1) / step
            << std::endl;

  return 0;
}
