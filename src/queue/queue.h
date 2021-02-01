#pragma once

#include <condition_variable>
#include <deque>
#include <mutex>

template <typename T>
class Queue {
 public:
  void push_back(T val);
  T pop_front();
  bool empty() const;

 private:
  std::mutex mutex_;
  std::condition_variable not_empty_;
  std::deque<T> queue_;
};

#include "queue.hpp"