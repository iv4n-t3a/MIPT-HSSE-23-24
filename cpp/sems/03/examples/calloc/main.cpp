#include <stdio.h>
#include <stdlib.h>

#include <iostream>

const int kArraySize = 5;

int main() {
  int* ptr = static_cast<int*>(calloc(kArraySize, sizeof(int)));

  for (int i = 0; i < kArraySize; ++i) {
    *(ptr + i) = i;
  }

  for (int i = 0; i < kArraySize; ++i) {
    std::cout << ptr[i] << std::endl;
  }

  free(ptr);

  return 0;
}