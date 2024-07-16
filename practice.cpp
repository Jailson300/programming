#include<iostream>
using namespace std;

class Student{
    public:
    float pi;
    float rad;
    public:

    Student(){
       pi=3.14;
       rad=7;
    }

    void display(){
        cout<<"Area of the circle is : "<<(2*pi)*rad<<endl;
    }
};

int main(){
    Student obj;
   obj.display();
    return 0;
}