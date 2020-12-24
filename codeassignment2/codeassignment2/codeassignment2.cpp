// Name: Lewis Burrows
// Version:1.0.2
/*Explanation of code: This code runs the USW Cyber app and has the main functions of creating a username, password , and making
sure that the password created is very secure and strong.*/

#include<iostream>
#include<fstream>
using namespace std;    //using the standard namespace

int vowels(string fullname) { //This bit of the code stores the name variable and insures the pin knows how many vowels are in the name and the length of the name
    int count = 0;
    for (int i = 0; i < fullname.length(); i++) 
        if (fullname[i] =='a' || fullname[i] =='e' || fullname[i] =='i' || fullname[i] =='o' || fullname[i] =='u')//This is for generating the unique pin based on the vowels in the username
            count++;
    return count;
}

int reverse(int n) {
    int reversedNo = 0, modulo;
    while (n != 0) {
        modulo = n % 10;
        reversedNo = reversedNo * 10 + modulo;
        n /= 10;
    }
    return reversedNo;
}

int dayofweek(int d, int m, int y) //Calculating the day the user was born and store it in a variable
{
    int t[] = {0,3,2,5,0,3,5,1,4,6,2,4}; //This is Tomohiko Sakamoto's Algorithm
    y -= m < 3;
    return (y+y / 4-y / 100+y / 400 + t[m - 1] + d) % 7;
}
int passwordcheck(string passw) { //this is the code to store the password variables of capital letters, numbers and symbols to be used to test the password strength later

    if (passw.length() < 14)
        return 0;
    int cap = 0, num = 0, symb = 0;

    for (int i = 0; i < passw.length(); i++) {

        if (passw[i] >= 'A' && passw[i] <= 'Z')
            cap++;                                  //Adding to the count of capital letters 
        else if (passw[i] >= '0' && passw[i] <= '9')
            num++;                                  //Adding to the count of numbers
        else
            symb++;                                 //Adding to the count of symbols
    }

    if (passw.length() >= 18 && cap >= 4 && num >= 3 && symb >= 3)      //if the password contains these variables and is that long it returns how strong it is (strong)
        return 3;
    else if (passw.length() >= 16 && cap >= 2 && num >= 2 && symb >= 2) //if the password contains these variables and is that long it returns how strong it is (medium)
        return 2;
    else if (passw.length() >= 14 && cap >= 1 && num >= 1 && symb >= 1) //if the password contains these variables and is that long it returns how strong it is (weak)
        return 1;

}
int check(string message) {
    int f = 0;
    while (1) {
        cout << message;
        cin >> f;
        if (!cin.fail() && f > 0) {
            return f;
        }
        cin.clear();
        cin.ignore();
        cout << "Must be a whole/postive number" << endl;
    }
}

int main() //The starting sequence of the app
{

    string fullname;
    int enrollmentno, age, day, month, year;                                    //Initialising variables
    cout << "Welcome to the new USW Cyber App! :) \n";
    cout << "Please enter your full name with spaces: ";                        //Telling the user to enter their name and the format
    cin >> fullname;                                                            //Storing name
    fflush(stdin);
    cout << "Please enter your USW Enrollment number: ";                        //Telling the user to enter their enrollment number
    cin >> enrollmentno;                                                        //Storing enrollment number
    age = check("Please enter your age: ");                                    //Telling the user to enter their age and checking it
    cout << "Please Enter your date of birth on the next line (dd/mm/yyyy) \n"; //Telling the user to enter their DOB and the format
    day = check("Day: ");                                                       //Storing day variable
    month = check("Month: ");                                                   //Storing month variable
    year = check("Year: ");                                                     //Storing year variable
    day = dayofweek(day, month, year);

    string week[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" }; //initialising "week" array with the days
    cout << "You were born on a " << week[day] << endl;                                        //Telling the user what day of the week they were born on

    int count = vowels(fullname);           //Counting the vowels in the name to generate pin
    int reverse_age = reverse(age);         //Reversing the age to generate pin
    int pin = count * reverse_age;          //Calculation to generate unique pin
    cout << "Generating pin...\n";
    cout << "Your unique pin is: ";
    printf("%04d\n", pin);

    int account, i = 3, check = 1;
    cout << "Please enter your Enrollment number: ";     //Telling the user to enter their enrollment number again for the account
    cin >> account;                         //Storing into account variable
    cout << "Please enter your pin: ";
    cin >> pin;

    while (i--) { //While loop for entering enrollment number and pin until it is correct

        if (pin == pin && account == enrollmentno)//this double checks that the pin and enrollment number are the same as entered
            break;

        cout << "The enrollment number or pin is incorrect! Try again.\n";  //Tells the user that there was an issue
        cout << "Please enter your Enrollment number: ";
        cin >> account;
        cout << "Please enter your pin: ";
        cin >> pin;
    }

    if (i + 1 == 0) {
        cout << "3 Attempts made";
        return 0;
    }
    string username, temp;
    cout << "Please make a new username (no spaces allowed!): "; //This is telling the user that they have to create a username which they will use to login later
    cin >> username;                       //Storing username

    string password;
    cout << "The Password must contain 18 characters, 3 upper case, 3 numbers and 3 symbols! \n";
    cout << "Please Make a new strong Password: "; //This is telling the user that they have to create a password that is 18 characters long, with 3 upper case, 3 number and 3 symbols
    cin >> password;                              //Storing password
    check = passwordcheck(password);              //Checking password
    while (check != 3) {    //While loop to check the password is strong and has the right amount of numbers, symbols and length and repeats until they do.

        if (check == 0) {
            cout << "Password not suitable, try again \n";
        }
        else if (check == 1) {
            cout << "Password too weak, try again \n";
        }
        else {
            cout << "Medium strength password try again \n";
        }
        cout << "The Password must contain 18 characters, 3 upper case, 3 numbers and 3 symbols! \n";
        cout << "Please Make a new strong password: ";
        cin >> password;
        check = passwordcheck(password); //Repeating the check after telling them what they need to include to be sure
    }
    cout << "Your password is strong! Well done! \n";
    cout << "Thank you for using the USW cyber app! \n";
    cout << "Saving account...\n";

    ofstream file;
    file.open("2FA_users.txt", ios::app);//This stores all the account data the users have made into a text file so administrators can manually look at it and remove users easily
    file << account << " " << pin << " " << username << " " << password << endl;    //Saving to file
    return 0;                                                                       //End of program
}