#include<iostream>
using namespace std;
#define swap(x,y) x=x+y,y=x-y,x=x-y
int main()
{
int a,b;
cout<<"Enter two numbers:"; cin>>a>>b;
cout<<"x="<<a<<"y="<<b;
swap(a,b);
cout<<"\nx="<<a<<"y="<<b; 
return 0;
}