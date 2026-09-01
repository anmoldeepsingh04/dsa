#include <iostream>

using namespace std;

void nextPerm(vector<int>& arr){
    int pivot = -1, n = arr.size();
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(arr.begin(), arr.end());
        return;
    }


    for(int i = n-1; i > pivot; i--){
       if(arr[i] > arr[pivot]){
        swap(arr[i], arr[pivot]);
        break;
       } 
    }

    int start = pivot + 1, end = n-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(vector<int>& arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,1,5};
    nextPerm(arr);
    printArray(arr);

    return 0;
}