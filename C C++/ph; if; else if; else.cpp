#include <iostream>

int main() {
  
  double ph = 7;
  
  // Write the if, else if, else here:
  
  if (ph > 7) {

    std::cout << "Basic\n";
  }

  else if (ph < 7) {

    std::cout << "Acidic\n";
  }
  else {
    std::cout << "Neutral\n";
  }
  
}