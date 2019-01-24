/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'/
 *
 *   ######      ######
 *   #######    #######
 *   ########  ########
 *    ################           Name:       Christian Hill
 *    #### ###### ####           Class:      CSC-275 - September 18
 *    ####  ####  ####           Project:    Assignment: Lab 2
 *   ######  ##  ######          Due Date:   09-15-2018
 *   ######      ######
 *   ######      ######
 *
/'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
// include libraries
#include <iostream>
#include <string>

using namespace std;

class Mario_Twins{
public:
    Mario_Twins();
    Mario_Twins(string my_name);
    static void add_coins(int t);
    static void check_coins();
    void collect_coin();
    int my_coins();
    string my_name();

private:
    static int coins_left;
    int coins = 0;
    string name;

};

int Mario_Twins::coins_left = 0;


int main()
{
    Mario_Twins p1("Mario");
    Mario_Twins p2;
    Mario_Twins::add_coins(2);

    p1.collect_coin();
    Mario_Twins::check_coins();
    p2.collect_coin();
    Mario_Twins::check_coins();
    p2.collect_coin();
    Mario_Twins::check_coins();

    cout << p1.my_name() << " has " << p1.my_coins() << " coins.\n";
    cout << p2.my_name() << " has " << p2.my_coins() << " coins.\n";

    return 0;
}

Mario_Twins::Mario_Twins(){
    cout << "Enter your player's name: ";
    cin >> name;
    cout << "Ready Player " << name << endl;
}

Mario_Twins::Mario_Twins(string my_name){
    name = my_name;
    cout << "Ready Player " << name << endl;
}

void Mario_Twins::add_coins(int t){
    cout << "Added " << t << " coins to the block.\n";
    coins_left+=t;
}

void Mario_Twins::check_coins(){
    cout << "There are " << coins_left << " coins remaining.\n";
}

void Mario_Twins::collect_coin(){
    if(coins_left > 0){
        cout << name << " got a coin.\n";
        coins++;
        coins_left--;
    }
    else
        cout << "Coin block is empty.  You must add more coins. \n";

}

int Mario_Twins::my_coins(){
    return coins;
}

string Mario_Twins::my_name(){
    return name;
}


