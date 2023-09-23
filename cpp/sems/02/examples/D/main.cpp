// TODO(epsilond1)
#include <iostream>

int main() {
  int v_speed = 0;
  int t_time = 0;
  const int kMkadLength = 109;
  std::cin >> v_speed >> t_time;
  std::cout << ((v_speed * t_time) % kMkadLength + kMkadLength) % kMkadLength
            << std::endl;

  return 0;
}
