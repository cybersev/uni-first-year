// Week 2 coding tutourial: peas in a pod, Lewis Burrows

#include <iostream>
using namespace std;

int main()
{
    int pods, peas, totalPeas;
    cout << "No. pods: \n";
    cin >> pods;
    cout << "No. peas in each pod: \n";
    cin >> peas;
    totalPeas = pods * peas;

    cout << "If you had " << pods << " pods and " << peas << " peas in each pod, you would have " << totalPeas << " peas in total!\n";

    return 0;
}

