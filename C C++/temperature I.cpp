#include <iostream>

int main() {
  
  //initialise variables
  double tempf = 85.0;
  double tempc = 0.0;
  
  //C to F formula
  tempc = (tempf - 32) / 1.8;
  
  //output 
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";
  
}