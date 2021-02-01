#include "queue.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

int main() {
  constexpr int N_threads = 10;

  Queue<int> queue;
  // queue.push_back(1);
  // queue.push_back(2);
  // queue.push_back(3);

  auto push_back = [&](auto e) { queue.push_back(e); };
  std::vector<std::thread> threads(N_threads);
  std::ranges::for_each(
      threads, [&](auto& t) { t = std::thread(push_back, std::rand() % 10); });
  std::ranges::for_each(threads, [&](auto& t) { t.join(); });
  while (!queue.empty()) std::cout << queue.pop_front() << " ";
}