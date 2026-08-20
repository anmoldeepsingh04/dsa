#include <iostream>
#include <vector>

using namespace std;

int main(){

    // vector<int> vec; // vector of size 0
    // cout<<vec[0]; // gives a segmentation fault, which means we are trying to access a memory address for which we don't have the permission, as the element we are trying to access does not exist.
     
    vector<int> vec = {1,2,3,2,1,4,4};
    int ans = 0;
    for(int i : vec){
        ans ^= i;
    }
    cout<<ans<<endl;

    return 0;
}