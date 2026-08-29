#include <iostream>

using namespace std;

void selectionSort(vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; i++){
        int smallestIdx = i;
        for(int j = i + 1; j < arr.size() ; j++){
            if(arr[j] < arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void vecPrint(vector<int>& arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> arr = {1,4,2,33,-1,-23};
    selectionSort(arr);
    vecPrint(arr);
    return 0;
}