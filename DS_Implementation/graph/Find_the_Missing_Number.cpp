#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int missingNumber(vector<int> arr) {

    int n = arr.size() + 1;
    unordered_set<int> numberSet;

    for(auto num: arr) {
        numberSet.insert(num);
    }

    for(int i = 1; i <= n; i++) {
        if(numberSet.find(i) == numberSet.end()) return i;
    }
    return -1;

}

int main() {
    vector<int> arr = {1, 2, 3, 5};
    int res = missingNumber(arr);
    cout << res << endl;
    return 0;
}