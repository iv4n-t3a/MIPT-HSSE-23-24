#include <cstring>
#include <iostream>

int main() {
  const int kArraySize = 5;
  int* first_array = new int[kArraySize];
  int* second_array = new int[kArraySize];

  for (int idx = 0; idx < kArraySize; ++idx) {
    *(first_array + idx) = idx;
  }

  memcpy(second_array, first_array, sizeof(int) * kArraySize);

  for (size_t idx = 0; idx < kArraySize; ++idx) {
    std::cout << *(first_array + idx) << " : " << *(second_array + idx)
              << std::endl;
  }

  delete[] first_array;
  delete[] second_array;

  return 0;
}
