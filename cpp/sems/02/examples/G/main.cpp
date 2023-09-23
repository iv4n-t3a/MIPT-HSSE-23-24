#include <iostream>

int main() {
  int current_second = 0;
  const int kSecondsInHour = 3600;
  const short kHoursInDay = 24;
  const short kSecondsInMinute = 60;
  const short int kMultiplier = 10;

  std::cin >> current_second;
  int hour = (current_second / kSecondsInHour) % kHoursInDay;
  int minute = ((current_second - (hour * kSecondsInHour)) / kSecondsInMinute) %
               kSecondsInMinute;
  int second =
      (current_second - (hour * kSecondsInHour) - (minute * kSecondsInMinute)) %
      kSecondsInMinute;
  std::cout << hour << ":" << minute / kMultiplier;
  std::cout << minute % kMultiplier << ":" << second / kMultiplier
            << second % kMultiplier;

  return 0;
}
