/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'/
 *
 *   ######      ######
 *   #######    #######
 *   ########  ########
 *    ################           Name:       Christian Hill
 *    #### ###### ####           Class:      CSC-275 - September 2018
 *    ####  ####  ####           Project:    Assignment: Lab 2
 *   ######  ##  ######          Due Date:   09-22-2018
 *   ######      ######
 *   ######      ######
 *
/'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
// include libraries
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
/*
// Purpose:         Game for a standard deck of 52 playing cards.
// Precondition:    The IOstream, string, vector, and algorithm library must be loaded.
                        main function should create a vector<Card> Deck; object for storing the deck of cards.
                        It should also initialize a seed for the random number generator.
// Postcondition:   After filling the deck with the 52 standard playing cards, you should use the random_shuffle()
                        function from the algorithm library to randomize the Deck.
// Input:           (int) random_shuffle - Shuffles the 52 cards randomly
// Output:          (int) point_val      - determines the score at the end of a hand
                    (int) rel_val        - compares and sorts cards in order
*/

class Card{
public:
    Card();
    Card(string face, string name, char suit, int rel_val, int point_val);
    /*Purpose:          Get the name, face, suit, and value of the card
      Preconditions:    None
      Postconditions:   Return the string, char, and int value of card*/
    string get_name() const;
    /*Purpose:          Get the name of the card
      Preconditions:    None
      Postconditions:   Return the name of the card as a string*/
    string get_face() const;
    /*Purpose:          Get the face value of the card
      Preconditions:    None
      Postconditions:   Return the face of the card as a string*/
    char get_suit() const;      //Returns the suit of the card as a char
    int get_rel() const;        //Returns the rel_val of the card as an integer
    int get_points() const;     //Return the point_val of the card as an integer
    bool same_suit() const;     /*Takes one parameter, a Card object card.
                                            Returns true if suit_val of the calling object is equal to card2.suit_val
                                            Returns false otherwise*/
    bool is_next() const;       /*Takes one parameter, a Card object card.
                                            Returns true if rel_val of the calling object is equal to 1 + card
                                            Returns false otherwise*/
    friend bool operator < (const Card& card1, const Card& card2);    //Used to compare two Card objects by rel_val, card1 < card2
    friend bool operator == (const Card& card1, const Card& card2);   //Used to compare two Card objects by rel_val, card1 == card2

private:
    string face;   //Stores the face value of the card.
    string name;   //Stores a descriptive name of the card.
    char suit;     //Stores the suit of the card. Used for checking for flushes.
    int rel_val;   /*Stores the value of the card relative to other cards.
                            Used for comparison, sorting cards in order, checking for a straight*/
    int point_val; /*Stores the point value of the card for certain games.
                            Used to determine the score at the end of a hand in certain games.*/
};

int main()
{
    vector<Card> hand;

    hand.push_back(Card("Ace","Ace of Spades", 'S', 14, 0));    //for creating the Ace of Spades and pushing it onto the Vector.
    hand.push_back(Card("King","King of Spades", 'S', 13, 0));
    hand.push_back(Card("Two", "Two of Clubs", 'C', 2, 0));
    hand.push_back(Card("Two", "Two of Hearts", 'H', 2, 0));
    hand.push_back(Card("Two", "Two of Diamonds", 'D', 2, 0));

    return 0;
}

Card::Card(){

}

Card::Card(string face, string name, char suit, int rel_val, int point_val){
    /*intentionally empty*/
}

string Card::get_name() const{
    cout << " " << face << " of " << suit << " " << endl;
    return name;
}

string Card::get_face() const{
    face () = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                "Ten", "Jack", "Queen", "King"};
    return face;
}

char Card::get_suit() const{
    suit() = {"Hearts", "Diamonds", "Clubs", "Spades"};
    return suit;
}

int Card::get_rel() const{
    rel_val() = {14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    return rel_val;
}

int Card::get_points() const{
    point_val = 0;
    return point_val;
}

bool Card::same_suit(int suit_val) const{

    return suit_val;
}
bool Card::is_next() const{
    return rel_val == 1 + rel_val;
}

bool operator < (const Card& card1, const Card& card2){
    return card1.rel_val() < card2.rel_val();
}

bool operator == (const Card& card1, const Card& card2){
    return card1.rel_val() == card2.rel_val();
}


