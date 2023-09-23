#include <bitset>
#include <iostream>

int main() {
  const short int kWordSize = 8;

  int number;
  std::cin >> number;

  std::cout << std::bitset<kWordSize>(number) << std::endl;
  int negative_number = -number;
  std::cout << std::bitset<kWordSize>(negative_number) << " = "
            << negative_number << std::endl;

  return 0;
}
