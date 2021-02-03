#include <iostream>
#include <string>
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

class AO3 {
public:
  AO3(std::string name);
  void run(bool* keep_running);
private:
  std::string name;
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

AO3::AO3(std::string name) : name(name) {

}

void AO3::run(bool* keep_running) {
  while(*keep_running) {
    sleep(1);
    std::cout << "AO3 named: " << name << std::endl;
  }
  std::cout << "AO3 done" << std::endl;
}

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  auto ao1 = make_ao<AO1>();
  auto ao2 = make_ao<AO2>();
  auto ao3 = make_ao<AO3>("Charlie");
  sleep(5);
  std::cout << "main done" << std::endl;
}
