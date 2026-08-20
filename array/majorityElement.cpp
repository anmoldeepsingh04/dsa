#include <iostream>
#include <vector>

using namespace std;

int majorityElementBF1(vector<int>& vec){
    int maxEl = 0, maxOccurence = 0, currEl = 0, count = 0;
    for(int i = 0; i < vec.size(); i++){
        currEl = vec[i];
        count = 0;
        for(int j = i; j < vec.size(); j++){
            if(currEl == vec[j]){
                count++;
            }
        }
        if(count > maxOccurence){
            maxEl = currEl;
            maxOccurence = count;
        }
    }

    return maxEl;
}

int majorityElementBF2(vector<int>& vec){
    int freq = 0;
    int ans = -1;
    for(auto i : vec){
        freq = 0;
        for(auto j: vec){
            if(i == j){
                freq++;
            }
        }
        if(freq > vec.size()/2){
            ans = i;
        }
    }
    return ans;
}

int majorityElementO1_1(vector<int>& vec){
    // using sorting
    sort(vec.begin(), vec.end());
    int freq = 1, ans = vec[0];
    for(int i = 1; i < vec.size(); i++){
        if(ans == vec[i]){
            freq++;
        }
        else{
            ans = vec[i], freq = 1;
        }
        if(freq > vec.size()/2){
            return ans;
        }
    }
    return ans;
}

int majorityElementO1_2(vector<int>& vec){
    // using sorting
    sort(vec.begin(), vec.end());
    return vec[floor(vec.size()/2)];
}

int mooreVotingAlgo(vector<int>& vec){
    int ans = 0, freq = 0;
    for(auto i : vec){
        (freq == 0) ? ans = i : ans;
        (ans == i) ? freq++ : freq--;
    }

    // checking if this element is really the majority ([1,2,3,4] -> none exist in this case)
    int count = 0;
    for(int i : vec){
        (i == ans) ? count++ : count;
    }

    return (count > vec.size()/2) ? ans : -1;
}

int main(){

    vector<int> vec = {4,4,1,4,3,3,4};
    cout<<mooreVotingAlgo(vec)<<endl;
    return 0;
}