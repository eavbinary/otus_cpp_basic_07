#include <iostream>

#include "serial_container.hpp"
#include "line_container.hpp"

template <typename T>
void demoContainer(T &cnt, std::string message)
{
  std::cout << message << std::endl;
  std::cout << "Add 0...9" << std::endl;
  for (int i = 0; i < 10; i++)
  {
    cnt.push_back(i);
  }
  cnt.show();
  std::cout << "Size: " << cnt.size() << std::endl;
  std::cout << "Delete item 3, 5, 7" << std::endl;
  for (int i = 3; i < 6; i++)
    cnt.erase(i);
  cnt.show();
  std::cout << "Add item to begin(10)" << std::endl;
  cnt.insert(0, 10);
  cnt.show();
  std::cout << "Delete item to middle(20)" << std::endl;
  cnt.insert(cnt.size() / 2, 20);
  cnt.show();
  std::cout << "Delete item to end(30)" << std::endl;
  cnt.push_back(30);
  cnt.show();
}

int main()
{
  LineContainer<int> a;
  SerialContainer<int> scnt;
  demoContainer(scnt, "=== Serial container ===");

  LineContainer<int> lcnt;
  demoContainer(lcnt, "=== Line container ===");
  return (0);
}
