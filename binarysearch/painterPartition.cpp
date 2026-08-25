#include <iostream>

using namespace std;

bool isValid(vector<int>& arr, int boardCount, int painterCount, int maxTime){
    int painters = 1, time = 0;
    for(int i = 0; i < arr.size(); i++){
        if(time + arr[i] <= maxTime){
            time += arr[i];
        }
        else{
            painters++;
            time = arr[i];
        }
    }
    return painters <= painterCount ? true : false;
}

int painterPartition(vector<int>& arr, int boardCount, int painterCount){
    int start = INT_MIN, end = 0, ans = -1;
    for(auto i : arr){
        (i > start) ? start = i : start;
        end += i; 
    }
    int mid = 0;
    while(start <= end){
        mid = start + (end - start)/2;
        if(isValid(arr, boardCount, painterCount, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40, 30, 10, 20};
    cout<<painterPartition(arr, 4, 2)<<endl;
    return 0;
}