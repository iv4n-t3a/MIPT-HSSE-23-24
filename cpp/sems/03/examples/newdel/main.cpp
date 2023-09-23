#include <iostream>

int main() {
  int* ptr = new int;
  const int kMyFavoriteMagicConst = 42;
  *ptr = kMyFavoriteMagicConst;
  std::cout << "Addr: " << ptr << "; Value: " << *ptr << std::endl;
  delete ptr;

  const int kArraySize = 5;
  int* aptr = new int[kArraySize];
  for (int idx = 0; idx < kArraySize; ++idx) {
    *(aptr + idx) = idx;
  }

  for (int idx = 0; idx < kArraySize; ++idx) {
    std::cout << "Addr: " << (ptr + idx) << "; Value: " << *(ptr + idx)
              << std::endl;
  }

  delete[] aptr;

  return 0;
}