#ifndef _ACTIVEOBJECT_H
#define _ACTIVEOBJECT_H

#include <memory>
#include <thread>
#include <iostream>

template<class AOT>
class ActiveObject {
 public:
  explicit ActiveObject<AOT>(std::shared_ptr<AOT> handler)
    : handler(handler), keep_running(true) {
    runnable = std::make_unique<std::thread>(&AOT::run, handler, &keep_running);
  }
  ~ActiveObject() {
    keep_running = false;
    if (runnable->joinable()) {
      runnable->join();
    }
    std::cout << "ActiveObject done" << std::endl;
  }
 private:
  std::shared_ptr<AOT> handler;
  std::unique_ptr<std::thread> runnable;
  bool keep_running;
};

template<class AOT, class... Args>
std::shared_ptr<ActiveObject<AOT>> make_ao(Args&&... args) {
  std::shared_ptr<AOT> handler = std::make_shared<AOT>(args...);
  return std::make_shared<ActiveObject<AOT>>(handler);
}

template<class AOT>
std::shared_ptr<ActiveObject<AOT>> make_ao() {
  std::shared_ptr<AOT> handler = std::make_shared<AOT>();
  return std::make_shared<ActiveObject<AOT>>(handler);  
}

#endif
