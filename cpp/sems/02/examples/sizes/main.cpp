#include <iostream>
#include <string>

void PrintSize(std::string name, size_t size) {
  std::cout << name << " " << size << std::endl;
}

int main() {
  PrintSize("char", sizeof(char));
  PrintSize("int", sizeof(int));
  PrintSize("float", sizeof(float));
  std::string obj = "Helo!";
  PrintSize("object", sizeof(obj));
  PrintSize("String", sizeof(std::string));

  return 0;
}
