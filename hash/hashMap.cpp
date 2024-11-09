#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> hashMap;

    hashMap["rafi"] = 1;
    hashMap["kafi"] = 2;
    hashMap["safi"] = 3;
    hashMap["nafi"] = 4;
    

    // search a value 
    if(hashMap.find("rafi") != hashMap.end()) {
        cout<< "The value of rafi is found";
    }

    cout << "Size: " << hashMap.size() << endl;

    return 0;
}