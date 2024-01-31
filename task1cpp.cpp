#include<iostream>
#include<ctime>
using namespace std;
void run()
{
    srand(time(0));
    int randnum = rand() % 1000;
    // cout << randnum;
    int usernum = 0;
    do 
    {
        cout << "Enter number between 0 and 500" << endl;
        cin >> usernum;
        if (usernum == randnum)
        {
            cout <<" Congratulations you've Won " << endl;
            break;
        }
        else if (usernum < randnum)
        {
            cout << "Low" << endl;
        }
        else if (usernum > randnum)
        {
            cout << "High" << endl;
        }
    } 
    while (true);

}

int main()
{
    do 
    {
        run();
        char choice;
        cout << "Would you like to Play Again, press any key,else press q/Q to EXIT " << endl;
        cin >> choice;
        if(choice == 'q' || choice == 'Q')
        {
            cout << "Thank you for playing " << endl;
            break;
        }
    }
    while(true);
}