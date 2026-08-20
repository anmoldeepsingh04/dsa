#include <iostream>
#include <vector>

using namespace std;

int bruteForceMSS(vector<int> vec){
    int maxSum = INT_MIN;
    for(int start = 0; start < vec.size(); start++){
        int currSum = 0;
        for(int end = start; end < vec.size(); end++){
            currSum += vec[end];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int KadaneMSS(vector<int> vec){
    int maxSum = 0, currSum = 0;
    for(int i = 0; i < vec.size(); i++){
        currSum += vec[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

int main(){

    vector<int> vec = {3,-4, 5, 4, -1, 7, -8};
    
    cout<<bruteForceMSS(vec)<<endl;
    cout<<KadaneMSS(vec)<<endl;

    return 0; 
}