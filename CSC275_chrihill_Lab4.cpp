/*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'/
 *
 *   ######      ######
 *   #######    #######
 *   ########  ########
 *    ################           Name:       Christian Hill
 *    #### ###### ####           Class:      CSC-275 - September 2018
 *    ####  ####  ####           Project:    Assignment: Lab 4
 *   ######  ##  ######          Due Date:   09-29-2018
 *   ######      ######
 *   ######      ######
 *
/'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*'*/
// include libraries
#include <iostream>

using namespace std;

class Lab4{
public:
    Lab4();
    Lab4(int my_p);
    Lab4(const Lab4& mycopy);
    Lab4& operator = (const Lab4& rtside);
    ~Lab4();
private:
  int *p = new int;

};

int main(){


    return 0;
}

Lab4::Lab4(){
    *p = 0;
}

Lab4::Lab4(int my_p){
     *p = my_p;
}

Lab4::Lab4(const Lab4& mycopy){
    *p = *mycopy.p;

}

Lab4& Lab4::operator = (const Lab4& rtside){
    delete p;
    p = new int;
    *p = *rtside.p;
}

Lab4::~Lab4(){
    delete p;
}
