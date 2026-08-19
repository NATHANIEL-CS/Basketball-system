#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true){
        int hula;
        srand(time(0));
        int number = rand() % 4 + 1; 
        cout << "HULA: ";
        cin >> hula;
        if(hula == number){
            cout << "\nTAMA" << endl;
            cout << "" << number << endl;
        } else {
            cout << "\nMALI" << endl;
            cout << "" << number << endl;
        }
    }

    return 0;
}