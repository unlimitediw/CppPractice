#include <iostream>
#include "Array.h"


int main() {
    Solution A;
    vector<int> vect{2,7,11,15};
    vector<int> myRes = A.twoSumMap(vect,9);
    for(int i = 0;i< myRes.size();i++){
        cout << myRes.at(i) << endl;
    }
    return 0;
}