#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSumBF(vector<int>& vec, int& target){
    vector<int> ans;
    for(int i = 0; i < vec.size(); i++){
        for(int j = i+1; j < vec.size(); j++){
            if(vec[i] + vec[j] == target){
                ans.push_back(i); 
                ans.push_back(j);
                break;
            }
        }
    }
    return ans; 
}

vector<int> pairSumO1(vector<int>& vec, int& target){
    int start = 0, end = vec.size() - 1;
    vector<int> ans;
    while(start < end){
        int sum = vec[start] + vec[end];
        if(sum == target){
            ans.push_back(start);
            ans.push_back(end);
            break;
        }
        else if(sum > target){
            end -= 1;
        }
        else{
            start += 1;
        } 
    }
    return ans;
}



int main(){
    vector<int> vec = {2,7,11,15};
    int target = 17 ;
    // auto ans = pairSumBF(vec, target);
    auto ans = pairSumO1(vec, target);
    cout<<"Target sum "<<target<<" is achieved by elements "<<vec[ans[0]]<<" and "<<vec[ans[1]]<<" on index "<<ans[0]<<" and "<<ans[1]<<endl;
    return 0;
}