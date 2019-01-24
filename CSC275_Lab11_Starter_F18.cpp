#include <iostream>
#include <vector>
#include <set>
#include <time.h>
#include <random>

using namespace std;

void RandFill_Vector(int n);
void RandFill_Set(int n);
int main()
{
    time_t starttime, endtime;
    double dif;
    time(&starttime);   //Record start time for vector
    RandFill_Vector(1024); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl;
    return 0;
    /*

    B) Test results here:





    C) Test results here:






    D) Big Oh running time of find()






    E) Big Oh running time of RandFill_Vector





    F) Big Oh running time of RandFill_Set




    */
}

void RandFill_Vector(int n){
    //Input n from user
    int r;
    bool found_r = false;
    //Create a vector v of type int
    vector<int> myvec;
    //Loop i = 1 to n
    int i = 1;
    while(i <= n){
        //r = random integer between 0 and n-1
        r = rand()%n;
        //linearly search through v for value r
        for(int j = 0; j<myvec.size(); j++){
            if( r == myvec[j]){
                found_r = true;
            }
        }
        if(!found_r){
            myvec.push_back(r);
            i++;
        }
        found_r = false;
    }

    cout << myvec.size() << " unique random values put into the vector " << endl;

}


void RandFill_Set(int n){
    //input n from user
    int r;
    //create set s of type int
    set<int> s;
    set<int>::iterator it;
    //loop i = 1 to n
    int i = 1;
    while(i <= n){
        //r = random integer between 0 and n-1
        r = rand()%n;
        //use s.find(r) to search of r is already in the set
        it = s.find(r);
        if(it == s.end()){
            s.insert(r);
            i++;
        }

    }

    cout << s.size() << " unique random values put into the set " << endl;


}
