// TODO(epsilond1)

#include <iostream>

void TypicalPrint(std::string pos, int main_number, int new_number) {
  std::cout << "The " << pos << " number for the number ";
  std::cout << main_number << " is " << new_number << "." << std::endl;
}

void RunTypicalPrint(int cur_number) {
  TypicalPrint("next", cur_number, cur_number + 1);
  TypicalPrint("previous", cur_number, cur_number - 1);
}

int main() {
  int cur_number = 0;
  std::cin >> cur_number;
  RunTypicalPrint(cur_number);

  return 0;
}
