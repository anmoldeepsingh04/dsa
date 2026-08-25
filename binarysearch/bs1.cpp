#include <iostream>

using namespace std;

int binSearchIterative(vector<int>& ans, int target){
    int mid = 0, start = 0, end = ans.size() - 1;
    while(start <= end){
        mid = (start + end)/2;
        if(ans[mid] > target){
            end = mid - 1;
        } 
        else if(ans[mid] < target){
            start = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int binSearchRecur(vector<int>& ans, int target, int start, int end){
    if(start <= end){
        int mid = start + (end - start)/2;
        if(ans[mid] > target){
            return binSearchRecur(ans, target, start, mid - 1);
        } 
        else if(ans[mid] < target){
            return binSearchRecur(ans, target, mid + 1, end);
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1, 0, 3, 4, 6, 5, 9, 12, 15, 67, 93, 191, 295, 389, 486, 565};
    int target  = 12;
    cout<<binSearchIterative(arr, 191)<<endl;
    cout<<binSearchRecur(arr, 191, 0, arr.size())<<endl;

    return 0;
}