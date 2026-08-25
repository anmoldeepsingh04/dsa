#include <iostream>

using namespace std;

int singleElementBF(vector<int>& arr){

    for(int i = 1; i < arr.size() - 1; i++){
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
            return arr[i];
        }
    }

    return -1;  
}

int singleElementO(vector<int>& arr){
    if(arr.size() == 1){
        return arr[0];
    }
    int st = 0, end = arr.size() - 1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(mid == 0 && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if(mid == arr.size() - 1 && arr[mid-1] != arr[mid-2]){
            return arr[mid];
        }
        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }
        if(mid % 2 == 0){
            if(arr[mid - 1] == arr[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        else{
            if(arr[mid-1] == arr[mid]){
                st =
                mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }

    return -1;  
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,5,6,6};
    cout<<singleElementO(arr)<<endl; 
    return 0;
}