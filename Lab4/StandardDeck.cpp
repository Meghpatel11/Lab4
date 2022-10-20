/*Name: - Nirmal Patel &  Megh Patel
 *Group 2
 *Subject OOps
 *Lab 4
 */
#include "StandardDeck.h"

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

StandardDeck::StandardDeck()
{
	my_cards = 0;
	Initialize();
}

StandardDeck::~StandardDeck()
{
	delete[] my_cards;
}


void StandardDeck::Initialize()
{
	// if card value is empty 
	int const MYDACK = 52;
	if (my_cards != 0) {
		
		delete[] my_cards;
	}

	// making new dack
	my_cards = new PlayingCard[MYDACK];

	my_card_size = MYDACK;

	for (int suit = 0; suit < PlayingCard::SUITS; ++suit)
	{
		for (int rank = 0; rank <= PlayingCard::RANKS; ++rank)
		{
			if (rank == 0)
			{

				continue;
			}

			int index = rank + (suit * 13);

			my_cards[index - 1].SetSuit(suit);

			my_cards[index - 1].SetRank(rank);

			m_pCards.push_front(new PlayingCard(PlayingCard::CARD_RANK[rank], PlayingCard::CARD_SUIT[suit], rank, true));
		}
	}
}

PlayingCard StandardDeck::DrawNextCard()
{

	if (my_card_size <= 0)

		throw std::out_of_range(" empty deck. ");

	// preserve the first value

	PlayingCard card = my_cards[0];



	// Shift all cards by value 1:

	for (int moveTo = 0; moveTo < my_card_size - 1; moveTo++)

	{

		my_cards[moveTo] = my_cards[moveTo + 1];

	}

	std::cout << "\n" << (std::string)card << std::endl;

	// updating card size
	my_card_size = my_card_size - 1;

	// return the card
	return card;
}

std::string StandardDeck::Remaining() const // an accessor to show info about the state of the object      
{
	std::stringstream card;

	card << "\n======================================" << std::endl

		<< "myArray: " << std::endl

		<< "my_card_size:  " << my_card_size << std::endl;

	for (int i = 0; i < my_card_size; i++)

	{

		card << "[" << i << "]: " << (std::string)my_cards[i] << std::endl;

	}



	card << "\n===============================================" << std::endl;

	return card.str();

}

std::string StandardDeck::to_string() const
{
	std::stringstream stream;

	for (const auto card : m_pCards)
	{
		stream << card->to_string() << std::endl;
	}

	return stream.str();
}

void StandardDeck::Shuffle()
{
	// creating card objects
	PlayingCard samCard, ran1, ran2;
	for (int i = 0; i < my_card_size; i++)
	{
		// making it random
		int randomCard1;

		randomCard1 = rand() % 52;

		int randomCard2;

		randomCard2 = rand() % 52;

		ran1 = my_cards[randomCard1];

		ran2 = StandardDeck::my_cards[randomCard2];

		samCard = my_cards[randomCard1];

		//Shuffuling
		my_cards[randomCard1] = my_cards[randomCard2];
		my_cards[randomCard2] = samCard;
		cout << (string)my_cards[randomCard1] << "\n";

	}
	cout << "Shuffuling Completed!" << endl;
}


PlayingCard StandardDeck::DrawRandomCard()
{
	// show error if size is 0
	if (my_card_size <= 0)

		throw out_of_range(" empty deck. ");

	// making random cards 
	int random;

	random = rand() % 52;

	cout << "\n" << random << endl;

	my_cards[random].SetSuit(rand() % (PlayingCard::SUITS));
	my_cards[random].SetRank(1 + rand() % (PlayingCard::RANKS));

	for (int moveTo = random; moveTo < my_card_size - 1; moveTo++)
	{
		cout << "\n" << moveTo << endl;

		my_cards[moveTo] = my_cards[moveTo + 1];

	}

	my_card_size = my_card_size - 1;

	// print results
	cout << "\n[" << random << "]: " << (string)my_cards[random] << endl;
	cout << "\n" << random << endl;
	cout << "\n[" << random << "]: " << (string)my_cards[random] << endl;

	return my_cards[random];
}

