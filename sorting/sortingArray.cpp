#include <iostream>

using namespace std;

void sortArrayBF(vector<int>& arr){
    sort(arr.begin(), arr.end());
}

void sortArrayOptimized(vector<int>& arr){
    int countZ = 0, countO = 0, countT = 0;
    for(auto i : arr){
        if(i == 0){
            countZ++;
        }
        else if(i == 1){
            countO++;
        }
        else{
            countT++;
        }
    }
    for(int i = 0; i < arr.size(); i++){
        if(countZ != 0){
            arr[i] = 0;
            countZ--;
        }
        else if(countO != 0){
            arr[i] = 1;
            countO--;
        }
        else{
            arr[i] = 2;
            countT--;
        }
    }
}

void DNF(vector<int>& arr){
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(vector<int>& arr){
    for( auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {2,0,2,1,1,0,1,2,0,0};
    DNF(arr);
    printArray(arr);
    return 0;
}