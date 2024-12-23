#include<iostream>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int maxEnd = arr[0];
    int res = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        maxEnd = max(maxEnd + arr[i], arr[i]);
        res = max(maxEnd, res);
    }

    return res;
}


int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);
    return 0;
}