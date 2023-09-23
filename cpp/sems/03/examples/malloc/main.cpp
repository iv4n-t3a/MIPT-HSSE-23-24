#include <stdio.h>
#include <stdlib.h>

const int kArraySize = 10;

int main() {
  int* ptr = static_cast<int*>(malloc(sizeof(int) * kArraySize));
  int* saved_ptr = ptr;

  for (int idx = 0; idx < kArraySize; ++idx) {
    *ptr = idx;
    ++ptr;
  }

  printf("\n");

  ptr = saved_ptr;
  for (int idx = 0; idx < kArraySize; ++idx) {
    printf("%i ", *ptr);
    ++ptr;
  }

  free(saved_ptr);

  return 0;
}