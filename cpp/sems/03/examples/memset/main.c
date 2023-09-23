#include <memory.h>
#include <stdio.h>

const int kArraySize = 20;

void PrintArray(char array[]) {
  for (int i = 0; i < kArraySize; ++i) {
    printf("%c ", array[i]);
  }
  printf("%s\n", "EOL");
}

int main() {
  char buffer[kArraySize];
  printf("%s\n", "Before memset: ");
  PrintArray(buffer);

  memset(buffer, 's', sizeof(char) * kArraySize);

  printf("%s\n", "After memset: ");
  PrintArray(buffer);

  return 0;
}