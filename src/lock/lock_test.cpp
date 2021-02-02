#include "spinlock.h"

#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int main() {
  constexpr int n_threads = 10;
  constexpr int n_iterations = 10000;
  Spinlock spinlock;
  auto counter{0};
  auto inc = [&] {
    for (int i = 0; i < n_iterations; i++) {
      std::lock_guard<Spinlock> lg{spinlock};
      counter++;
    }
  };
  std::vector<std::thread> threads(n_threads);
  std::ranges::for_each(threads, [&](auto &t) { t = std::thread(inc); });
  std::ranges::for_each(threads, [&](auto &t) { t.join(); });
  std::cout << "counter: " << counter
            << "\texpected:" << n_threads * n_iterations << std::endl;
}
