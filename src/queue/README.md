## Condvar based concurrent queue

```cpp
Channel<std::function<void(void)>> channel;
channel.send([](){std::cout << 1;})
```