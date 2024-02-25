#include <iostream>
#include <vector>

int main() {
  
  std::vector<std::string> grocery = {"Hot Pepper Jam", "Dragon Fruit", "Brussel Sprouts"};
    
  // Add more 
  grocery.push_back("Apples");
  grocery.push_back("Boys");
  grocery.push_back("Depression");

  std::cout << grocery.size() << "\n";
  
  
}