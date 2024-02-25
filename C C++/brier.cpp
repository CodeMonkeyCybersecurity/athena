#include <iostream>

int main () {
    //defn + init variables
    double prior = 0.0;
    double likelihood = 0.0;
    double posterior = 0.0;
    double normalising_constant = 0.0;


    //"What is the probability of rain (A) occuring given that there are clouds (B) in the sky?"
    //pA|B = (pAB)/pB
    // https://www.quantstart.com/articles/Bayesian-Statistics-A-Beginners-Guide/



    std::cout << "enter prior probability: ";
    std::cin >> prior;

    std::cout << "enter likelihood of data being correct, given out hypothesis: ";
    std::cin >> likelihood;

    std::cout << "probability of hypothesis being correct from evidence given: ";
    std::cin >> posterior;

    //normalising_constant = likelihood * prior
    //std::cout << normalising constant



}