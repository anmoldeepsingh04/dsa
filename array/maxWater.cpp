#include <iostream>

using namespace std;

int maxAreaBF(vector<int>& height) {
        int maxWater = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i+1; j < height.size(); j++){
                maxWater = max(maxWater, min(height[i], height[j]) * (j-i));
            }
        }
        return maxWater;
    }

int maxAreaO1(vector<int>& height){
        int maxWater = 0, left = 0, right = height.size() - 1;
        while(left < right){
            maxWater = max(maxWater, min(height[left], height[right]) * (right - left));
            (height[left] < height[right]) ? left++ : right--;
    }
    return maxWater;
}

int main(){
    vector<int> height = {1,8,2,7};
    // cout<<maxAreaBF(height)<<endl;
    cout<<maxAreaO1(height)<<endl;
    return 0;
}