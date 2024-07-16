#include<iostream>
using namespace std;

class palin {
private:
    string str;

public:
    void getdata() {
        cout << "Enter the string: ";
        cin >> str;
    }

    void check() {
        int pal = 0;
        int strlen = str.length();
        for (int i = 0; i < strlen / 2; ++i) 
		{
            if (str[i] != str[strlen - i - 1]) 
			{
                pal = 1;
                break; // Exit loop early if not a palindrome
            }
        }
        display(pal);
    }

    void display(int pal) 
	{
        if (pal == 1) {
            cout << "The string is not a palindrome" << endl;
        } else {
            cout << "The string is a palindrome" << endl;
        }
    }
};

int main() {
    palin obj;
    obj.getdata();
    obj.check();
    return 0;
}

