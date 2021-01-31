#pragma once

#include <atomic>

class AtomicCounter {
 private:
  std::atomic<unsigned long> counter_{0ul};
};