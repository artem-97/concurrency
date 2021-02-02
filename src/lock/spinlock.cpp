#include "spinlock.h"

void Spinlock::lock() {
  while (is_locked_.exchange(true))
    ;
}

void Spinlock::unlock() { is_locked_.store(false); }
