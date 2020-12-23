// Week 4 tutourial, Lewis Burrows//

#include <iostream>

int main()
{
    using namespace std;
    int A1weight;
    int A2weight;
    double A1mark;
    double A2mark;
    double FinalGrade;

    cout << "Please input the weighting for the first assignment: \n";
    cin >> A1weight;
    cout << "Please input the weighting for the second assignment: \n";
    cin >> A2weight;
    cout << "Please input the mark you got for the first assignment: \n";
    cin >> A1mark;
    cout << "Please input the mark you got for the second assignment: \n";
    cin >> A2mark;

    FinalGrade = (A1weight * (A1mark / 100)) + (A2weight * (A2mark / 100));

    cout << "Your overall grade is: " << FinalGrade << "%" << endl;

    return 0;
}