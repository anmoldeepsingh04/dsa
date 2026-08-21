#include <iostream>

using namespace std;

void func1(int* ptr){
    *ptr += 10;
}

void func2(int& alias){
    alias += 10;
}

int main(){
    int a= 10;
    int* ptr = &a;
    cout<<"Value of a: "<<a<<" "<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Address stored in ptr: "<<ptr<<endl;
    cout<<"Value stored at the address stored in ptr: "<<*ptr<<endl;
    cout<<"Address of the pointer storing the address of a: "<<&ptr<<endl;


    // pass by reference
    // using pointers
    int b = 10;
    func1(&b);
    cout<<b<<endl;

    // using aliases
    int c = 10;
    func2(c);
    cout<<c<<endl;

    return 0;
}