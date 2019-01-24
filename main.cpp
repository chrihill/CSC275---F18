/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'/
 *
 *   ######      ######
 *   #######    #######
 *   ########  ########
 *    ################           Name:       Christian Hill
 *    #### ###### ####           Class:      CSC-275 - September 2018
 *    ####  ####  ####           Project:    Assignment: Project 3
 *   ######  ##  ######          Due Date:   11-29-2018
 *   ######      ######
 *   ######      ######
 *
/'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
/*
========================================================================
-------             -Project 3: Auto Card Game-                  -------
========================================================================
*/
// Include libraries
#include <iostream>     // std::cout
#include <vector>       // std::vector
/*~*/

// Include Header files
#include "Player.h"     // Player class and objects
#include "HandyPlayer.h"// HandyPlayer class and objects
#include "PokerPlayer.h"// PokerPlayer class and objects
#include "Card.h"       // Card class and objects
/*~*/

// Declare name-space
using namespace std;    // Need the standard name-space

// Main Function
int main()
{
    //Sets players name
    Player *player1 = new Player("Christian");
    cout << "Initial name: " << player1->getName() << endl;
    cout << endl;

    //Sets a new name for a player
    player1->setName("Mike");
    cout << "New name: " << player1->getName() << endl;
    cout << endl;

    //Sets a handyplayers name
    HandyPlayer *handyplayer1 = new HandyPlayer("Bob");
    cout << "Handyplayers initial name: " << handyplayer1->getName() << endl;
    cout << endl;

    // Adds cards to the handyplayers hand
    handyplayer1->addCard(Card("Ace", "Ace of Clubs", 'C', 14, 15));
    handyplayer1->addCard(Card("Ace", "Ace of Spades", 'S', 14, 15));
    handyplayer1->addCard(Card("King", "King of Spades", 'S', 13, 10));
    handyplayer1->addCard(Card("Jack", "Jack of Spades", 'S', 11, 10));
    handyplayer1->addCard(Card("Queen", "Queen of Spades", 'S', 12, 10));
    handyplayer1->addCard(Card("Two", "Two of Spades", 'S', 2, 5));
    handyplayer1->addCard(Card("Three", "Three of Spades", 'S', 3, 5));

    // Checks to see if another card can be added to the handyplayers hand
    try{
        cout << "ATTEMPTING TO ADD AN 8TH CARD" << endl;
        handyplayer1->addCard(Card("Three", "Three of Spades", 'S', 3, 5));
    }
    // Throws an error after trying to add an 8th card to the handyplayers hand
    catch(string err){
        cout << err << endl;
    }

    // Displays the handplayers hand
    handyplayer1->displayHand();

    // Removes the 2nd card from the Handplayers hand
    handyplayer1->removeCard(2);

    // Checks to see if a card that is not in the vector can be removed from the handyplayers hand
    try{
        cout << "ATTEMPTING TO REMOVE A CARD THAT IS NOT IN THE HAND" << endl;
        handyplayer1->removeCard(8);
    }
    // Throws an error after trying to remove a card that was not in handyplayers hand
    catch (string err) {
        cout << err << endl;
    }

    cout << endl << endl;

    cout << "REMOVING CARD AT INDEX 2" << endl << endl;

    // Displays the handtplayers hand
    handyplayer1->displayHand();

    cout << endl;
    cout << "SORTING HAND" << endl;
    cout << endl;

    // Sorts the handyplayers hand by relative card value
    handyplayer1->sortHand();
    cout << endl;

    // Sets the names for two poker players and adds 7 chips to the 2nd poker player
    PokerPlayer *pokerplayer1 = new PokerPlayer("Tim");
    PokerPlayer *pokerplayer2 = new PokerPlayer("Nancy", 7);
    // Sets the name for the first poker player
    cout << "First Poker players name: " << pokerplayer1->getName() << endl;
    cout << endl;

    // Sets the name for the second poker player
    cout << "Second Poker players name: " << pokerplayer2->getName() << endl;
    // Displays the amount of chips the second poker player starts with
    cout << "They start with: " << pokerplayer2->getChipcount() << " chips" << endl;
    cout << endl;
    // Adds 4 chips to second poker player
    pokerplayer2->addChips(4);
    cout << "Second Poker player receives an additional 4 chips for a total of: " << pokerplayer2->getChipcount() << endl;

    // Checks to see if Second poker player can receive 20 more chips
    try {
         cout << "ATTEMPTING TO ADD 20 CHIPS" << endl;
        pokerplayer2->addChips(20);
    }
    // Throws an error after attempting to add 20 chips
    catch(string err){
        cout << err << endl;
    }

    // Removes 7 chips from the second poker player
    pokerplayer2->removeChips(7);
    cout << "Second Poker player loses 7 chips for a total of: " << pokerplayer2->getChipcount() << endl;

    // Checks to see if 20 poker chips can be removed from second poker player
     try {
         cout << "ATTEMPTING TO REMOVE 20 CHIPS" << endl;
        pokerplayer2->removeChips(20);
    }
    // Throws an error after trying to remove 20 chips from second poker player
    catch(string err){
        cout << err << endl;
    }

    // Checks to see if second poker player can bet 1 chip
    if (pokerplayer2->canCoverBet(1)) {
        cout << "Second Poker player can cover a bet of 1 chip" << endl;
    }

    // Checks to see if second poker player can bet 12 chips
    if (!pokerplayer2->canCoverBet(12)){
        cout << "Second Poker player cannot cover a bet of 12 chips" << endl;
    }

    return 0;
}
