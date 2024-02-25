#include <iostream>

int main() {

  // Write a for loop here:
  
  for (int i = 99; i > 0; i--)
  {
    std::cout << i << " bottles of pop on the wall.\n";
    std::cout << "Take one down and pass it around.\n";
    int ii = i - 1;
    std::cout << ii << " bottles of pop on the wall.\n";
    std::cout << "\n";
  }
  
}