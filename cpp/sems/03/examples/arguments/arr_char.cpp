#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  std::cout << "Count of arguments: " << argc << std::endl;

  std::cout << "arg[0]:" << argv[0] << std::endl;

  if (argc > 1 && argc < 3) {
    std::cout << "arg[1]:" << argv[1] << std::endl;
    std::cout << "arg[2]:" << argv[2] << std::endl;
  }

  return 0;
}
