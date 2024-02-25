#include <iostream>

int main() {
  // Add your code below  
  //declare + init variables
  double weightitem = 0.0;
  double weightmars = 0.0;

  //ask for input
  std::cout << "Enter the weight of your item in Kilograms: ";

  //get input 
  std::cin >> weightitem;

  //maths 
  weightmars = (weightitem * 0.378);

  //output weight of item on mars
  std::cout << "The weight of your item on Mars is " << weightmars << "kilograms.\n";

}