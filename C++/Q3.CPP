#include<iostream>
using namespace std;

int main(){
    float n,sum = 0, i;

    cout<<"Enter the nth term: ";
    cin>>n;

      for (i = 1; i <= n; i++) {
        sum = sum + (1 / i);
    }

    cout<<"The sum of the given series is : "<<sum<<endl;

    return 0;
}