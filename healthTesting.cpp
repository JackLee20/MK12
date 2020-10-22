#include <iostream>
//using namespace std;

int main()
{
    int healthAdjustment;
    int health = 100;

	// prompt for user input
	std::cout << "Enter health adjustment: \n" ;
	std::cin >> healthAdjustment;

	// code from player.cpp file
	health = health + healthAdjustment; 
	if (health < 0)
	{
		health = 0;
	}
	
		if (healthAdjustment < 0)
	{
	    std::cout << "Bad input, try again ";
	    std::cin >> healthAdjustment;
	} else {

	// tell the user what was entered and the sum
	std::cout << "healthAdjustment = " << healthAdjustment << std::endl;
	std::cout << "health + healthAdjustment = " << health << std::endl ;
	
	}
	// normal finish - exit with 0
	return 0 ;
}

//   ./test < classTestingInput13.txt | diff - classTestingExpected13.txt # player health