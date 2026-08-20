// q1. write linear search algorithm for vector
// q2. write array reversal code for vector

#include <iostream>

using namespace std;

int vectorLinearSearch(vector<int>& vec, int target){
    int idx = -1;
    for(int i = 0; i < vec.size(); i++){
        if(vec.at(i) == target) idx = i;
    }

    return idx;
}

void vectorReversal(vector<int>& vec){
    int start = 0, end = vec.size() - 1;
    
    while(start < end){
        swap(vec[start], vec[end]);
        start++, end--;
    }
}

void printVec(vector<int> vec){
    for(int i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> vec = {1,2,3,4,23,1,4,9};
    
    //q1
    cout<<vectorLinearSearch(vec, 9)<<endl;
    
    //q2
    printVec(vec);
    vectorReversal(vec);
    printVec(vec);

    return 0;
}