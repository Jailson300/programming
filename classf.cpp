#include<iostream>
using namespace std;

class fruit{
    public:
  string name;
  string color;
};

int main(){
    fruit apple; //object
    apple.name =  "Apple";
    apple.color = "Red";

    cout<<apple.name<<endl;
}