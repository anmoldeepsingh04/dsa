#include <iostream>

using namespace std;

void bubbleSort(vector<int>& arr){
    for(int j = 0; j < arr.size() - 1; j++){  
        bool swapped = false;
        for(int i = 0; i < arr.size() - j - 1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        if(!swapped){
            return;
        }
    }
}

void vecPrint(vector<int>& arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> arr = {1,4,2,33,-1,-23};
    bubbleSort(arr);
    vecPrint(arr);
    return 0;
}