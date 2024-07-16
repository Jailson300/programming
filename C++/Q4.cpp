#include<iostream>
using namespace std;

int main(){
    int n,sum=0;

    cout<<"Enter the n terms: ";
    cin>>n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            sum = sum + i;
        } else {
            sum = sum - i;
        }
    }

    cout<<"The sum of the given series is "<<sum<<endl;
    return 0;
}