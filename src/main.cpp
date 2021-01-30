#include <algorithm>
#include <thread>
#include <vector>

#include "lock-free/stack/stack.h"

int main() {
  constexpr int N_threads = 10;

  LockFree::Stack<int> stack;
  auto push = [&stack](auto e) { stack.push(e); };

  std::vector<std::thread> threads(N_threads);
  std::ranges::for_each(threads, [&](auto& t) { t = std::thread(push, 1); });
  std::ranges::for_each(threads, [&](auto& t) { t.join(); });

  std::cout << stack << std::endl;
}