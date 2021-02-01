#include "queue.h"

template <typename T>
void Queue<T>::push_back(T val) {
  std::unique_lock<std::mutex> lock{mutex_};
  queue_.push_back(std::move(val));
  lock.unlock();
  not_empty_.notify_one();
}

template <typename T>
T Queue<T>::pop_front() {
  std::unique_lock<std::mutex> lock{mutex_};
  not_empty_.wait(lock, [&]() { return !queue_.empty(); });
  auto result = queue_.front();
  queue_.pop_front();
  return result;
}

template <typename T>
bool Queue<T>::empty() const {
  return queue_.empty();
}
