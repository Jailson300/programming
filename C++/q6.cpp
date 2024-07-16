#include <iostream>
using namespace std;

class PrimeChecker {
private:
    int number;

public:
    PrimeChecker(int num) : number(num) {}

    bool isPrime() {
        if (number <= 1)
            return false;
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    static void generatePrimesLessThan100() {
        cout << "Prime numbers less than 100: ";
        for (int i = 2; i < 100; ++i) {
            PrimeChecker checker(i);
            if (checker.isPrime())
                cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    int num;
    cout << "Enter a number to check if it is prime: ";
    cin >> num;

    PrimeChecker checker(num);
    if (checker.isPrime()) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    PrimeChecker::generatePrimesLessThan100();

    return 0;
}

