#pragma once

#include <atomic>
#include <iostream>

namespace LockFree {

template <typename T>
struct Node {
  T val;
  Node* next = nullptr;
  Node(const T& val) : val(val), next(nullptr) {}
};

template <typename T>
class Stack;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack);

template <typename T>
class Stack {
 public:
  Stack() = default;

  // interface
  void push(T val);
  T pop();

  friend std::ostream& operator<<<>(std::ostream& os, const Stack& stack);

 private:
  std::atomic<Node<T>*> head_ = nullptr;
};
}  // namespace LockFree

#include "stack.hpp"