// Week 4 tutourial, Lewis Burrows//

#include <iostream>

int main()
{
    using namespace std;
    double number1;
    double number2;
    double number3;
    double number4;
    double number5;

    cout << "Please input number 1: \n";
    cin >> number1;
    cout << "Please input number 2: \n";
    cin >> number2;
    cout << "Please input number 3: \n";
    cin >> number3;
    cout << "Please input number 4: \n";
    cin >> number4;
    cout << "Please input number 5: \n";
    cin >> number5;

    cout << "Average of all numbers is: " << (number1 + number2 + number3 + number4 + number5) / 5 << endl;
    return 0;
}