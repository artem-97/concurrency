#include "stack.h"

namespace LockFree {

template <typename T>
void Stack<T>::push(T val) {
  auto* new_head = new Node<T>(val);
  new_head->next = head_.load(std::memory_order_relaxed);

  while (!std::atomic_compare_exchange_weak_explicit(
      &head_, &new_head->next, new_head, std::memory_order_release,
      std::memory_order_relaxed))
    ;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
  auto* node = stack.head_.load();
  if (node == nullptr) {
    std::cout << "stack is empty";
    return os;
  }

  while (node->next) {
    os << node->val << " ";
    node = node->next;
  }
  os << node->val;  // last
  return os;
}

}  // namespace LockFree