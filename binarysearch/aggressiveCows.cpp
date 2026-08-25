#include <iostream>

using namespace std;

bool isValid(vector<int>& arr, int n, int c, int minAllowedDistance){
    int cows = 1, lastStall = arr[0];
    for(int i = 1; i < n; i++){
        if((arr[i] - lastStall) >= minAllowedDistance){
            cows++;
            lastStall = arr[i];
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& arr, int n, int c){
    sort(arr.begin(), arr.end());
    int start = arr[1] - arr[0], end = arr[arr.size() - 1] - arr[0],  ans = 0, mid = 0;
    while(start <= end){
        mid = start + (end - start)/2;
        if(isValid(arr, n, c, mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,9,8,4};
    cout<<aggressiveCows(arr, arr.size(), 3)<<endl;

    return 0;
}