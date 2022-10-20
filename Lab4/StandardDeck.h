/*Name: - Nirmal Patel &  Megh Patel
 *Group 2
 *Subject OOps
 *Lab 4
 */
#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include <deque>

#include "PlayingCard.h"

class StandardDeck
{
public:
	// constructor(s)
	StandardDeck();

	// destructor
	~StandardDeck();
	

	// get / accessors

	int GetAnyCardsLeft() const;
	PlayingCard* my_cards = 0;
	static const int numSuits = 4;
	static const int numCards = 13;

	// set / mutators
	void SetAnyCardsLeft(int remaining);

	// overloaded operators

	// public methods
	virtual void Initialize();
	int CardsRemaining()
	{
		return my_card_size;
	}

	PlayingCard DrawNextCard();


	PlayingCard DrawRandomCard();

	void Shuffle();
	std::string Remaining() const;


	// overriden methods
	std::string to_string() const;
	bool isdrawn[numCards][numSuits];

private:
	// private instance members

	std::deque<PlayingCard*> m_pCards;

	int my_card_size;

	// private utility methods

};

#endif /* defined (__STANDARD_DECK__) */

