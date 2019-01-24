/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'/
 *
 *   ######      ######
 *   #######    #######
 *   ########  ########
 *    ################           Name:       Christian Hill
 *    #### ###### ####           Class:      CSC-275 - September 2018
 *    ####  ####  ####           Project:    Assignment: Project 1
 *   ######  ##  ######          Due Date:   10-02-2018
 *   ######      ######
 *   ######      ######
 *
/'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/

/*
NEED TO ADD:
0. Display win case. *!*
1. Display dealer's hand when you bust (lose). *!*
2. Display player's point total & dealer's point total when bust (lose) *!*
3. When the player eventually stands, the dealer's entire hand is revealed. *!*
    Then, while the dealer has < 17 points, the dealer must continue taking a hit until either busting or standing.
    Dealer automatically stands upon reaching >= 17 points.
4. Display dealer & player total points when dealer bust (you win). *!*
5. Make the game loop. (create a menu to ask if they want to play again.)
*/

// include libraries
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

class Cards{
public:
    Cards();
    Cards(string myFace, string myName,
         char mySuit, int myRel_val,
         int myPoint_val);
    string get_name() const;    //*** accessors need to be const!!! ***//
    string get_face() const;
    char get_suit() const;
    int get_rel() const;
    int get_points() const;

    bool same_suit(const Cards& card2) const;
    bool is_next(const Cards& card2) const;
    friend bool operator < (const Cards& card1,
                            const Cards& card2);
    friend bool operator == (const Cards& card1,
                             const Cards& card2);
    //*** these are all prototypes ***
private:
    string face = " ";
    string name = " ";
    char suit = '\0';
    int rel_val = 0;
    int point_val = 0;
};

// Menu choices.
const int HIT_CHOICE = 1, STAND_CHOICE = 2, QUIT_CHOICE = 3;

// Function prototypes.
int displayMainMenu();
void pushNewCardToHand(vector<Cards> &Deck, vector<Cards> &hand);
bool stand(vector<Cards> &playerHand, vector<Cards> &dealerHand);
bool didPlayerLose(int points);
bool didPlayerLoseAgainstDealer(int playerPoints, int dealerPoints);

int main()
{
    char repeatChoice = 'y';
    while (repeatChoice == 'Y' || repeatChoice == 'y') {
        repeatChoice = 'N';
        vector<Cards> Deck;  //Creates vector of Cards
        srand(unsigned (time(0)));  // Rand seed

        int new_suit = 0;
        string faces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
        string names[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
        char suits[4] = { 'D', 'C', 'H', 'S' };
        int rel_vals[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };


        for (int i = 0; i < 52; i++)
        {
            string face = faces[i % 13];
            string name = names[new_suit];
            char suit = suits[new_suit];
            int rel_val = rel_vals[i % 13];

            if ((i + 1) % 13 == 0)
                new_suit++;

            Deck.push_back(Cards(face, name, suit, rel_val, 0));
        }

        random_shuffle(Deck.begin(), Deck.end());

        // Dealer cards.
        vector<Cards> dealerCards;
        int dealerPoints = 0;
        dealerCards.push_back(Deck[0]);
        Deck.erase(Deck.begin());
        dealerCards.push_back(Deck[0]);
        Deck.erase(Deck.begin());

        // Player cards.
        int totalPlayerPoints = 0;
        vector<Cards> playerCards;

        playerCards.push_back(Deck[0]);
        totalPlayerPoints += Deck[0].get_rel();
        Deck.erase(Deck.begin());
        playerCards.push_back(Deck[0]);
        totalPlayerPoints += Deck[0].get_rel();
        Deck.erase(Deck.begin());

        cout << "Dealer card #1: " << dealerCards[0].get_face() << " of " << dealerCards[0].get_name() << endl;

        cout << endl;

        cout << "Player card #1: " << playerCards[0].get_face() << " of " << playerCards[0].get_name() << endl;
        cout << "Player card #2: " << playerCards[1].get_face() << " of " << playerCards[1].get_name() << endl;
        cout << "Current points: " << totalPlayerPoints << endl;


        // Menu choices.
        int mainMenuChoice = displayMainMenu();
        bool didLose = false;

        while (mainMenuChoice != QUIT_CHOICE) {
            if (mainMenuChoice == HIT_CHOICE) {
                pushNewCardToHand(Deck, playerCards);

                cout << endl << "CURRENT CARDS: " << endl;

                int playerPoints = 0;
                for (int i = 0; i < playerCards.size(); i++) {
                    cout << "Player card #" << i + 1 << ": " << playerCards[i].get_face() << " of " << playerCards[i].get_name() << endl;
                    playerPoints += playerCards[i].get_rel();
                }

                cout << "Current points: " << playerPoints << endl;

                didLose = didPlayerLose(playerPoints);

                if (didLose) {
                    for (int i = 0; i < dealerCards.size(); i++) {
                        dealerPoints += dealerCards[i].get_rel();
                    }

                    cout << "Dealers hand: " << endl;
                    cout << "Dealer card #1: " << dealerCards[0].get_face() << " of " << dealerCards[0].get_name() << endl;
                    cout << "Dealer card #2: " << dealerCards[1].get_face() << " of " << dealerCards[1].get_name() << endl;
                    cout << endl;
                    cout << "Dealers point score: " << dealerPoints << endl;
                    cout << "Players point score: " << playerPoints << endl;
                    cout << endl;
                    cout << endl << endl << "YOU LOST!! :(" << endl;

                    mainMenuChoice = QUIT_CHOICE;
                }
            } else if (mainMenuChoice == STAND_CHOICE) {
                // stand will return true if we lost, false otherwise.
                didLose  = stand(playerCards, dealerCards);

                cout << "Dealers hand: " << endl;
                cout << "Dealer card #1: " << dealerCards[0].get_face() << " of " << dealerCards[0].get_name() << endl;
                cout << "Dealer card #2: " << dealerCards[1].get_face() << " of " << dealerCards[1].get_name() << endl;
                cout << endl;

                if (dealerPoints < 17){
                    dealerCards.push_back(Deck[0]);
                    Deck.erase(Deck.begin());
                } else if (dealerPoints >= 17) {
                    for (int i = 0; i < dealerCards.size(); i++) {
                        cout << "Dealer card #" << i + 1 << ": " << dealerCards[i].get_face() << " of " << dealerCards[i].get_name() << endl;
                        dealerPoints += dealerCards[i].get_rel();
                    }

                    didLose = didPlayerLoseAgainstDealer(totalPlayerPoints, dealerPoints);
                }

                if (didLose) {
                    cout << endl << endl << "YOU LOST!! :(" << endl;
                    mainMenuChoice = QUIT_CHOICE;
                } else {
                    cout << "---------------" << endl;
                    cout << "****YOU WIN****" << endl;
                    cout << "---------------" << endl;
                    cout << endl;
                    mainMenuChoice = QUIT_CHOICE;
                }
            }

            if (!didLose && mainMenuChoice != QUIT_CHOICE) {
                mainMenuChoice = displayMainMenu();
            }

        }

        cout << "Thank you for playing Christian Hill's Black Jack!" << endl;

        cout << "Do you want to play again? (Press y for yes.) ";
        cin >> repeatChoice;
        //cin.clear();
    }
}

/*
* Displays the main menu.
*/
int displayMainMenu()
{
	int choice;

	cout << endl;
	cout << "Do you want to hit or stand?" << endl;
	cout << "1 Hit" << endl;
	cout << "2 Stand" << endl;
	cout << "3 Quit" << endl
        << "Enter a number between 1 and 3: ";

	//While the input entered is not an integer, prompt the user to enter an integer.
	while (!(cin >> choice) || choice < 0)
	{
		cout << "Bad input - try again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	while (choice != HIT_CHOICE && choice != STAND_CHOICE && choice != QUIT_CHOICE) {
        cout << "INVALID CHOICE. Try again: ";
        cin >> choice;
    }

	return choice;
}

void pushNewCardToHand(vector<Cards> &Deck, vector<Cards> &hand)
{
    hand.push_back(Deck[0]);
    Deck.erase(Deck.begin());
}

bool stand(vector<Cards> &playerHand, vector<Cards> &dealerHand)
{
    int playerPoints = 0;
    for (int i = 0; i < playerHand.size(); i++) {
        playerPoints += playerHand[i].get_rel();
    }

    int dealerPoints = 0;
    for (int i = 0; i < dealerHand.size(); i++) {
        cout << "Dealer card #" << i + 1 << ": " << dealerHand[i].get_face() << " of " << dealerHand[i].get_name() << endl;
        dealerPoints += dealerHand[i].get_rel();
    }

    cout << endl << "Player points: " << playerPoints << endl;
    cout << endl << "Dealer points: " << dealerPoints << endl;

    return didPlayerLoseAgainstDealer(playerPoints, dealerPoints);
}

bool didPlayerLose(int points)
{
    if (points > 21)
        return true;

    return false;
}

bool didPlayerLoseAgainstDealer(int playerPoints, int dealerPoints)
{
    if (dealerPoints > 21) {
        cout << endl << "Player points: " << playerPoints << endl;
        cout << endl << "Dealer points: " << dealerPoints << endl;
        return false;
    }

    if (playerPoints > 21) {
        return true;

    } else if (playerPoints > dealerPoints) {
        cout << endl << "Player points: " << playerPoints << endl;
        cout << endl << "Dealer points: " << dealerPoints << endl;
        return false;
    }

    return true;
}

Cards::Cards(/*intentionally empty*/){
    /*intentionally empty*/
}

Cards::Cards(string myFace, string myName, char mySuit, int myRel_val, int myPoint_val):
    face(myFace),
    name(myName),
    suit(mySuit),
    rel_val(myRel_val),
    point_val(myPoint_val)
    {}


string Cards::get_name() const{
    return name;
}

string Cards::get_face() const{
    return face;
}

char Cards::get_suit() const{
    return suit;
}

int Cards::get_rel() const{
    return rel_val;
}

int Cards::get_points() const{
    return point_val;
}

bool Cards::same_suit(const Cards& card2) const{
    return suit == card2.suit;
}

bool Cards::is_next(const Cards& card2) const{
    return rel_val == 1 + card2.rel_val;
}

bool operator < (const Cards& card1, const Cards& card2){
    return card1.rel_val < card2.rel_val;
}

bool operator == (const Cards& card1, const Cards& card2){
    return card1.rel_val == card2.rel_val;
}
