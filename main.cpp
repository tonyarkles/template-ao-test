#include <iostream>
#include "activeobject.h"
#include <unistd.h>

class AO1 {
public:
  void run(bool* keep_running);
};

class AO2 {
public:
  void run(bool* keep_running);
};


void AO1::run(bool* keep_running) {
  while(*keep_running) {
    sleep(1);
    std::cout << "AO1" << std::endl;
  }
  std::cout << "AO1 done" << std::endl;
}

void AO2::run(bool* keep_running) {
  while(*keep_running) {
    sleep(1);
    std::cout << "AO2" << std::endl;
  }
  std::cout << "AO2 done" << std::endl;
}

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  auto ao1 = make_ao<AO1>();
  auto ao2 = make_ao<AO2>();

  sleep(5);
  std::cout << "main done" << std::endl;
}
