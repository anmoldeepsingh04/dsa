#include <iostream>

using namespace std;

int idxFinder(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1 ;
}

void arrReverse(int arr[], int size){
    int start = 0;
    int end = size - 1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

}

int main(){
    // // q1: find the smallest and largest element in the array
    // int marks[6] = {5, 15, 22, 1, -15, 24}; 
    // int small = INT_MAX;
    // int large =  INT_MIN;

    // for(int i : marks){
    //     (small > i) ? small = i : small;
    //     (large < i) ? large = i : large;
    // }

    // cout<<"The smallest element is: "<<small<<"\nThe largest element is: "<<large<<endl;

    // // q2: find the index of the smallest and largest element in the array
    // int marks[6] = {5, 15, 22, 1, -15, 24};
    // int small = INT_MAX;
    // int large =  INT_MIN;
    // int max = 0;
    // int min = 0;
    // for(int i = 0; i < (int)(sizeof(marks)/sizeof(int)); i++){
    //     if(marks[i] < small) {
    //         small = marks[i];
    //         min = i;
    //     }
    //     if(marks[i] > large) {
    //         large = marks[i];
    //         max = i;
    //     }
    // }
    // cout<<"The smallest element is: "<<small<<" stored at index "<<min<<"\nThe largest element is: "<<large<<" stored at index "<<max<<endl;

    // // q3: find the index of the target element in the array
    // int marks[6] = {5, 15, 22, 1, -15, 24};
    // int target = 22;
    // cout<<"The target "<<target<<" is present at index "<<idxFinder(marks, 6, target) <<endl;

    // q4: Given an array, reverse it without using additional memory
    // solved using two pointer approach
    int marks[6] = {5, 15, 22, 1, -15, 24};
    arrReverse(marks, 6);
    for(auto i : marks){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}