#include <iostream>
using namespace std;

void bubbleSort(vector<int>& arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < arr.size() - 1 - i; j++) {
            if(arr[j] >  arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

int main() {
    vector<int> arr = {8,9,4,2,1,7};
    bubbleSort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }

}