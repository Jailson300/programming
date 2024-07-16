#include<iostream>
using namespace std;

class Calculation{
     float rad;
     float circum;
     float area;
     
     public:
    void getdata(){
        cout<<"Enter radius: ";
        cin>>rad;
    }

    void calc(){
        circum = 2*3.14*rad;
        area = 3.14*rad*rad;
    }

    void display(){
        cout<<"circumference :"<<circum<<endl;
        cout<<"Area :"<<area<<endl;
    }
};

int main(){
    Calculation obj;
    obj.getdata();
    obj.calc();
    obj.display();
    return 0;
}