/*Name: - Nirmal Patel &  Megh Patel
 *Group 2
 *Subject OOps 
 *Lab 4 
 */
#include <iostream>     
#include <stdexcept>
#include <sstream>
#include "PlayingCard.h"
#include <ctime>
#include "StandardDeck.h"


using namespace std;
int main()
{

    srand(time(NULL));

    StandardDeck myDeck, num2;

    char option = '0';

	while (option != '5')
	{
		

		cout << "\n\tStart the card game\t" << endl;
		cout << "===========================\t\n" << endl;
		cout << "Select from following option" << endl;

		cout << "Enter 1 for drawing the next card\n"
			<< "Enter 2 for drawing a Random card\n"
			<< "Enter 3 for remaining cards\n"
			<< "Enter 4 to Shuffle\n" << endl
			<< "Enter 5 to quit\n" << endl

			<< "Your Option: ";

		std::cin >> option;



		switch (option)
		{

		case '1':
		{

			myDeck.DrawNextCard();

			break;

		}

		case '2':
		{

			myDeck.DrawRandomCard();

			break;

		}



		case '3':
		{
			std::cout << myDeck.Remaining();

			myDeck.Remaining();

			break;

		}



		case '4':
		{
			

			myDeck.Shuffle();
			std::cout << "Card has been Shuffled";
			break;

		}

		case '5':
		{

			std::cout << "Exit";
			break;

		}
		}

	}

	return 0;


}


