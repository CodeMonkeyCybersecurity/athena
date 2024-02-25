#include <iostream>

int main() {
  
  double tempf = 0.0;
  double tempc = 0.0;
  
  // Ask the user
  std::cout << "Enter the temperature in Fahrenheit: "; 
  
  std::cin >> tempf;
  
  //calculate tempc from tempf
  tempc = (tempf - 32) / 1.8;
  
  //
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";
  
}