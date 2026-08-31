#include <iostream>

using namespace std;

void mergeSorted(vector<int>& arr1, int m, vector<int>& arr2, int n){
    int idx = m+n - 1, i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0){
        if(arr1[i] >= arr2[j]){
            arr1[idx] = arr1[i];
            idx--;
            i--;
        }
        else{
            arr1[idx] = arr2[j];
            idx--;
            j--;
        }
    }

    while(j >= 0){
        arr1[idx] = arr2[j];
        idx--;
        j--;
    }

}

void printArray(vector<int>& arr){
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    
    vector<int> arr1 = {1,2,3,0,0,0};
    vector<int> arr2 = {2,5,6};
    int m = 3, n = 3;
    mergeSorted(arr1, m, arr2, n);
    printArray(arr1);
    return 0;
}