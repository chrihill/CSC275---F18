#include <iostream>
#include <string>

using namespace std;

int getProductID(int ids[], string names[], int numProducts, string target);

int main()
{
    int productIds[] = {4,5,8,10,13};
    string products[] = {"computer","flash drive","mouse","printer","camera"};
    string searchtarget;
    cout << getProductID(productIds, products, 5, "computer") << endl;     //4
    cout << getProductID(productIds, products, 5, "mouse") << endl;     //8
    cout << getProductID(productIds, products, 5, "camera") << endl;    //13
    cout << getProductID(productIds, products, 5, "laptop") << endl;    //-1
    cout << "Give another product you want to search for: ";
    cin >> searchtarget;
    cout << getProductID(productIds, products, 5, searchtarget) << endl;    //?????
    return 0;
}


int getProductID(int ids[], string names[], int numProducts, string target){
    for(int i = 0; i < numProducts; i++){
        if (names[i] == target)
            return ids[i];
    }
    return -1;  //not found

}
