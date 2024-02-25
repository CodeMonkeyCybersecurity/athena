#include <iostream>

int main() {
  //variables + initialise
  int weight = 0;
  int planet = 0;
  double Mercurygrav =	0.38;
  double Venusgrav =	0.91;
  double Marsgrav = 0.38;
  double Jupitergrav =	2.34;
  double Saturngrav = 1.06;
  double Uranusgrav = 0.92;
  double Neptunegrav = 1.19;
  double destwt = 0.0;
  
  //ask earth weight
  std::cout << "Enter your earth is your earth weight in kilograms: ";
  std::cin >> weight;

  //what planet
  std::cout << "What planet are you fighting on? Type [1] Mercury, [2] Venus, [3] Mars, [4] Jupiter, [5] Saturn, [6] Uranus, [7] Neptune\n";
  std::cin >> planet;
  switch (planet) {
    case 1 :
      std::cout << "Mercury\n";
      destwt = weight * Mercurygrav;
      break;
    case 2 :
      std::cout << "Venus\n";
      destwt = weight * Venusgrav;
      break;
    case 3 :
      std::cout << "Mars\n";
      destwt = weight * Marsgrav;
      break;
    case 4 :
      std::cout << "Jupiter\n";
      destwt = weight * Jupitergrav;
      break;
    case 5 :
      std::cout << "Saturn\n";
      destwt = weight * Saturngrav;
      break;
    case 6 :
      std::cout << "Uranus\n";
      destwt = weight * Uranusgrav;
      break;
    case 7 :
      std::cout << "Neptune\n";
      destwt = weight * Neptunegrav;
      break;
    default :
      std::cout << "Incorrect input\n";
      break;
  }
  //weight on destination planet  
  std::cout << "On your destination planet you will weight " << destwt << "kgs.\n";

}




//Optional: Little Mac is an interplanetary space boxer, who is trying to win championship belts for various weight categories on other planets within the solar system.

//Write a space.cpp program that helps him keep track of his target weight by:

//It should ask him what his earth weight is.
//Ask him to enter a number for the planet he wants to fight on.
//It should then compute his weight on the destination planet.
//Here is the table of conversion:

//#	Planet	Relative Gravity
//1	Mercury	0.38
//2	Venus	0.91
//3	Mars	0.38
//4	Jupiter	2.34
//5	Saturn	1.06
//6	Uranus	0.92
//7	Neptune	1.19
