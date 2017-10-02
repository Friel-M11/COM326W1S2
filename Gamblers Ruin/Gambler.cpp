/*
* Gambler.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:25/09/2017
* Description: Solution to week 1 Gambler's Ruin challenge
*
* Copyright notice
*/

#include <iostream>
#include <random>

/*Function prototype - The function is below the main so the compiler won't know what the function is unless
* you declare it in advance. There isn't a function body however
* see: http://www.learncpp.com/cpp-tutorial/17-forward-declarations/ */
float GenerateRandomNumber();

int main(int argc, const char * argv[]) {

	//int stake{ 0 };
	int goal{ 0 };
	int num_games{ 0 };
	int cash{ 0 };

	int bets{ 0 };
	int wins{ 0 };

	char playAgain{ 'y' };

	do{
		num_games++;
		std::cout << "Please enter the players initial cash: ";
		std::cin >> cash;

		std::cout << "\nPlease enter the goal: ";
		std::cin >> goal;

		std::cout << "Game: "<< num_games << std::endl;

		while (cash > 0 && cash < goal) {
			bets++;
			if (GenerateRandomNumber() < 0.5)
				cash++;
			else
				cash--;
			std::cout << " cash: " << cash << std::endl;
		}
		if (cash == goal)
			wins++;
		else if (cash == 0)
			cash = 10;

		std::cout << "\nDo you want to play again? Y/N: "; 
		std::cin >> playAgain;
		std::cout << std::endl;
	} while (playAgain == 'y');

	std::cout << "\n" << "The total number of bets: " << bets / num_games; 
	std::cout << "\nwins: " << wins;
	std::cout << "\n" << (100 * wins / num_games) << " % wins" << std::endl;
	

	return 0;
}


float GenerateRandomNumber() {

	/* Some of you asked how this works. You really need to read the documentation for the deep dive explanation.
	* If you want to know what is happening here I have added some comments
	* This will become clearer when we talk about classes and objects in week 3
	*/


	//Taken from: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	//Define an instance (aka an object) of the random_device Class and call the object rd
	std::random_device rd; //The random number device. Will be used to obtain a seed for the random number engine
						   //Call the constructor of the object rd and use the RD engine to create a mersenne_twister_engine
						   //The mersenne_twister_engine is based on the Mersenne twister algorithm
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
							//Create a new distribution object with min and max values. So the range the random number should fall between
	std::uniform_real_distribution<> dis(0, 1);

	//Generate the randome number passing in the mersenne_twister_engine generator
	float outcome = dis(gen);
	std::cout << " outcome " << outcome;

	return outcome;
}


