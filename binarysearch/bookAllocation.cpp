#include <iostream>

using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int student = 1, pages = 0;
    for(int i = 0; i < n; i++){
        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            student++;
            pages = arr[i];
        }
    }
    return (student <= m) ? true : false;
}

int bookAllocation(vector<int>& arr, int n, int m){
    if(m > n){
        return -1;
    }
    int sum = 0;
    for(int i : arr){
        sum += i;
    }
    int start = 0, end = sum, mid = 0, ans = -1;
    while(start <= end){
        mid = start + (end - start)/2;
        if(isValid(arr, n, m, mid)){
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
    vector<int> arr = {2,1,3,4};
    cout<<bookAllocation(arr, arr.size(), 2)<<endl;

    return 0;
}