#include <iostream>

using namespace std;

vector<int> productExceptSelfBF(vector<int>& nums) {
    vector<int> ans;
    int prod = 1;
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size(); j++){
            (j != i) ? prod *= nums[j] : prod;
        }
        ans.push_back(prod);
        prod = 1;
    }
    return ans;
}

vector<int> productExceptSelfO1(vector<int>& nums) {
    vector<int> prefix(nums.size(), 1);
    vector<int> suffix(nums.size(), 1);
    vector<int> ans(nums.size(), 1);

    for(int i = 1; i < nums.size(); i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    for(int i = nums.size() - 2; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    for(int i = 0; i < nums.size(); i++){
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

vector<int> productExceptSelfO2(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);

    // storing all prefixes first in ans
    for(int i = 1; i < nums.size(); i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    // multiplying the prefixes in ans with their suffixes
    int suffix = 1;
    for(int i = nums.size() - 2; i >= 0; i--){
        suffix *= nums[i+1];
        ans[i] = ans[i] * suffix;
    }

    return ans;
}

int main(){

    vector<int> nums = {1,2,3,4};
    auto ans1 = productExceptSelfBF(nums);
    auto ans2 = productExceptSelfO2(nums);
    for(auto i : ans1){
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto i : ans2){
        cout<<i<<" ";
    }

    return 0;
}