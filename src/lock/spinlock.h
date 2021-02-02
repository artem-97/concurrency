#pragma once

#include <atomic>
class Spinlock {
public:
  Spinlock() = default;
  Spinlock(const Spinlock &) = delete;
  Spinlock &operator=(const Spinlock &) = delete;

  void lock();
  void unlock();

private:
  std::atomic_bool is_locked_{false};
};
