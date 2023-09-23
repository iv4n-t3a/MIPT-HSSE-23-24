#include <iostream>

int main() {
  const int kNumberBase = 10;
  int number = 0;
  const short int kMaxRegister = 100;
  const short int kMiddleRegister = 100;
  std::cin >> number;

  int first_digit = number / kMaxRegister;
  number -= first_digit * kMaxRegister;

  int second_digit = number / kMiddleRegister;
  number -= second_digit * kMiddleRegister;

  std::cout << first_digit + second_digit + number << std::endl;

  return 0;
}
