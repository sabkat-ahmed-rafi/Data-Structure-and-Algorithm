#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> hashSet;

    hashSet.insert(1);
    hashSet.insert(2);
    hashSet.insert(3);
    hashSet.insert(4);
    hashSet.insert(5);

    hashSet.erase(5);

    // search a value
    if(hashSet.find(3) != hashSet.end()) {
        cout<< "The value found";
    }

    for (const int &elem : hashSet) {
        cout << elem << " ";
    }

    hashSet.clear();

    return 0;
}