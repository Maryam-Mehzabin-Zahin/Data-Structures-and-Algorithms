#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int> lists) {
    int n = lists.size();
    unordered_map<int, int> countMap;

    for (int i = 0; i < lists.size(); i++) {
        countMap[lists[i]]++;
        if (countMap[lists[i]] > (n / 2)) {
            return lists[i];
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    vector<int> lists(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << majorityElement(lists) << endl;
    return 0;
}
