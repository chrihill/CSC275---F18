#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card{
public:
    Card();
    Card(string my_face, string my_name,
         char my_suit, int my_relval,
         int my_pointval);
    string get_name() const;
    string get_face() const;
    char get_suit() const;
    int get_rel() const;
    int get_points() const;

    bool same_suit(const Card& card2) const;
    bool is_next(const Card& card2) const;

    friend bool operator <(const Card& card1,
                           const Card& card2 );
    friend bool operator ==(const Card& card1,
                            const Card& card2);


private:
    string face = "";
    string name = "";
    char suit = '\0';
    int rel_val = 0;
    int point_val = 0;


};


int main(){

    vector<Card> hand;

    hand.push_back( Card("Ace","Ace of Spades", 'S', 14, 0));
    hand.push_back( Card("King","King of Spades", 'S', 13, 0));
    hand.push_back( Card("Two","Two of Clubs", 'C', 2, 0));
    hand.push_back( Card("Two","Two of Hearts", 'H', 2, 0));
    hand.push_back( Card("Two","Two of Diamonds", 'D', 2, 0));


}



Card::Card(){/*intentionally empty*/}

Card::Card(string my_face, string my_name,
     char my_suit, int my_relval,
     int my_pointval) :
         face(my_face),
         name(my_name),
         suit(my_suit),
         rel_val(my_relval),
         point_val(my_pointval)
    {}


string Card::get_name() const {return name;}
string Card::get_face() const {return face;}
char Card::get_suit() const {return suit;}
int Card::get_rel() const {return rel_val;}
int Card::get_points() const { return point_val;}

bool Card::same_suit(const Card& card2) const{
    return suit == card2.suit;
}

bool Card::is_next(const Card& card2) const{
    return rel_val == 1 + card2.rel_val;
}

bool operator <(const Card& card1,
                        const Card& card2 ){
    return card1.rel_val < card2.rel_val;
}


bool operator ==(const Card& card1,
                         const Card& card2 ){
    return card1.rel_val == card2.rel_val;
}

