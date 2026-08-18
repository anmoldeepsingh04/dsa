/*
q1. calculate sum and product of all numbers in an array
q2. swap the max and min number of an array
q3. print all the uniqies values in an array
q4. print intersection of 2 arrays
*/

#include <iostream>

using namespace std;

int summation(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int product(int arr[], int size){
    int prod = 1;
    for(int i = 0; i < size; i++){
        prod *= arr[i];
    }
    return prod;
}

// not valid as we changed the position of elements. But can be used to sort an array
void swapExtreme1(int arr[], int size){
    int count = 1;
    while(count != 0){
        count = 0;
        for(int i = 0; i < size-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                count++;
            }
        }
    }
    swap(arr[0], arr[size-1]);
}

void swapExtreme2(int arr[], int size){
    int small = INT_MAX, large = INT_MIN, min = 0, max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < small){
            small = arr[i];
            min = i;
        }
        if(arr[i] > large){
            large = arr[i];
            max = i;
        }
    }
    swap(arr[min], arr[max]);
}

std::vector<int> uniqueElem(int arr[], int size){
    std::vector<int> res = {};
    bool present = 1;
    for(int i = 0; i < size; i++){
        present = 1;
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j] && i != j){
                present = 0;
                break;
            }
        }
        if(present){res.push_back(arr[i]);}
    }
    return res;
}

std::vector<int> intersect(int arr1[], int arr2[], int size1, int size2){
    std::vector<int> res;
    bool present = 0;
    for(int i = 0; i < size1; i++){
        present = 0;
        for(int j = 0; j < size2; j++){
            if(arr1[i] == arr2[j]){
                present = 1;
                break;
            }
        }
        if(present){res.push_back(arr1[i]);}
    }
    return res;
}

int main(){
    // // q1
    // int arr[5] = {1,2,3,4,5};
    // cout<<"The sum of the elements is: "<<summation(arr, 5)<<endl;
    // cout<<"The product of the elements is: "<<product(arr, 5)<<endl;

    // // q2
    // int arr[5] = {12,-22,-23,8,125};
    // for(int i: arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // swapExtreme2(arr, 5);
    // for(int i: arr){
    //     cout<<i<<" ";
    // }

    // // q3
    // int arr[10] = {12, -22, 23, 8, 125, 12, -22, 637, -23, 8};
    // vector<int> res = uniqueElem(arr, 10);
    // for(auto i: res){
    //     cout<<i<<" ";
    // }

    // q4
    int arr2[5] = {1,2,3,4,5};
    int arr1[4] = {6, 1};
    int size1 = (int)(sizeof(arr1)/sizeof(int)), size2 = (int)(sizeof(arr2)/sizeof(int));
    vector<int> res = intersect(arr1, arr2, size1, size2);
    for(auto i: res){
        cout<<i<<" ";
    }



    return 0;
}