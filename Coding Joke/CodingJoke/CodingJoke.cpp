// Week 1 tutourial, Lewis Burrows//

#include <iostream>

int main()
{
    using namespace std;
    string name;
    double number1;
    double number2;
    cout << "cin, cout, shake it all about!\n";
    cout << "Please enter a name\n";
    cin >> name;
    cout << "please enter a number\n";
    cin >> number1;
    cout << "please enter another number\n";
    cin >> number2;
    cout << number1 + number2 << endl;
    cout << (number1 + number2) / 2 << endl;
    return 0;
}