// codeassignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fstream>
using namespace std;

int count_vowels(string name) // Lines 5 to 15 shows the implementation of the vowels a,e,i,o and this will be used when the user enters the day, month, year, fullname and enrollment number and it will generate a pin with 4 digits.
{

    int count = 0;

    for (int i = 0; i < name.length(); i++)
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
            count++;

    return count;
}

int reverse(int n) { // Lines 17 to 28 this part of the code will be used to reverse the age of the user e.g. I enter 21 and change into 12 return the answer as a pseudo-random four digit pin.

    int reversedNumber = 0, remainder;

    while (n != 0) {
        remainder = n % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
    }

    return reversedNumber;
}


int Day_Of_Week(int d, int m, int y) //Lines 31 to 36 this part of code works out the the day of the week, if i type in 17/02/1980 itll show Sunday.
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int check_pass(string pass) //Lines 38 to 62 shows the how long and short the password can be for it to accept the password, I have also added it has to be greater = a and less than and = z when someone is creating or created and account.
{

    if (pass.length() < 14) //Password length that can be used
        return 0;

    int cap = 0, num = 0, symb = 0;

    for (int i = 0; i < pass.length(); i++)
    {

        if (pass[i] >= 'A' && pass[i] <= 'Z')
            cap++;
        else if (pass[i] >= '0' && pass[i] <= '9')
            num++;
        else
            symb++;
    }

    if (pass.length() >= 18 && cap >= 4 && num >= 3 && symb >= 3)
        return 3;
    else if (pass.length() >= 16 && cap >= 2 && num >= 2 && symb >= 2)
        return 2;
    else if (pass.length() >= 14 && cap >= 1 && num >= 1 && symb >= 1)
        return 1;

}
int check(string message)
{
    int n;
    cout << message;
    cin >> n;
    if (n < 0)
    {
        check(message);

    }
    else
        return n;

}


int main() // This is where the program starts in terms of entering the required information need for the program to work.
{
    cout << "Welcome to the USW Cyber APP \n";
    int day = check("Enter day: ");
    int month = check("Enter current month: ");
    int year = check("Enter current year: "); // This is the integer for the day,month and year and Line 66 to 71 is where the user will input the current day,month and year.



    int DAY = Day_Of_Week(day, month, year); //When a user enters the day, month and year used from above can figure out what the current date e.g. Sunday

    if (DAY == 0)
        cout << "Sunday";
    else if (DAY == 1)
        cout << "Monday";
    else if (DAY == 2)
        cout << "Tuesday";
    else if (DAY == 3)
        cout << "Wednesday";
    else if (DAY == 4)
        cout << "Thursday";
    else if (DAY == 5)
        cout << "Friday";
    else if (DAY == 6)
        cout << "Saturday";
    else
        cout << "Sunday";
    cout << endl;

    string name;

    cout << "Enter full name: ";
    cin >> name;

    fflush(stdin);

    int enrol_num = check("Enter Enrollment Number: ");
    int age = check("Enter your Age: ");


    int count = count_vowels(name);
    int reverse_age = reverse(age);
    // Lines 109 and 110 are used to reverse the age and get the vowels from the users name then to lines 112 to 114 will generate a 4 digit pin.
    int pin = count * reverse_age;
    cout << "4-Digit pin: ";
    printf("%04d\n", pin);

    int acc, t_pin, i = 3, check = 1;
    cout << "Enter Account number:"; //Enter the enrolment number
    cin >> acc;
    cout << "Enter pin:";
    cin >> t_pin;

    while (i--)
    {

        if (pin == t_pin && acc == enrol_num)
            break;

        cout << "Error!\n";
        cout << "Enter Enrolment number:";
        cin >> acc;
        cout << "Enter pin:";
        cin >> t_pin;
    }

    if (i + 1 == 0) {

        cout << "Session ended 3 trials done!";
        return 0;
    }

    string uname, temp;
    cout << "Enter username:";
    cin >> uname;

    ifstream infile;
    infile.open("Users.txt"); //Users name will be stored within a .txt file so the code knows whos name has been used.

    while (!infile.eof()) {

        infile >> temp;

        if (uname == temp) {

            cout << "Username already exists!"; //If the user already exists the program should close
            return 0;
        }
    }

    string pass; // Lines 159 to 178 the user will enter a password and the program will see if the password is allowed to be used and will store the password in the .txt file.
    cout << "Please Make a Password:";
    cin >> pass;
    check = check_pass(pass);
    while (check != 3) {

        if (check == 0)
            cout << "Invalid!\n";
        else if (check == 1)
            cout << "Weak!\n";
        else
            cout << "Medium!\n";

        cout << "Enter pass:";
        cin >> pass;
        check = check_pass(pass);
    }
    cout << "Strong!\n";

    cout << "Writing to file!\n";

    ofstream file;
    file.open("2FA_users.txt", ios::app);
    file << acc << " " << pin << " " << uname << " " << pass << endl;
    file.close();                  // Lines 180 and 185 this section when the account is created, enrollement number, name, pin this will be stored in a .txt file where the users credentials will be saved so when they enter their credentials again itll be saved within the system.
    file.open("users.txt", ios::app);
    file << uname << endl;

    return 0;
}