#include "activeobject.h"

/* template<class AOT>
ActiveObject<AOT>(std::shared_ptr<AOT> handler) : handler(handler) {
  runnable = std::make_unique<std::thread>(&AOT::run, handler);
  } */

// template<class AOT, class... Args>
// std::shared_ptr<ActiveObject<AOT>> make_ao(Args&&... args) {
//   std::shared_ptr<AOT> handler = std::make_shared<AOT>(args...);
//   return std::make_shared<ActiveObject<AOT>>(handler);
// }

// template<class AOT>
// std::shared_ptr<ActiveObject<AOT>> make_ao() {
//   std::shared_ptr<AOT> handler = std::make_shared<AOT>();
//   return std::make_shared<ActiveObject<AOT>>(handler);  
// }
