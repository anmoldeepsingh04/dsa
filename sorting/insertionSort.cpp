#include <iostream>

using namespace std;

void insertionSort(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void vecPrint(vector<int>& arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> arr = {1,4,2,33,-1,-23};
    insertionSort(arr);
    vecPrint(arr);
    return 0;
}