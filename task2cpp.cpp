#include<iostream>
using namespace std;

void run()
{
    float var1, var2 ;
    char oper='\0';
    var1=var2 = 0;

    cout << "Enter first digit " << endl;
    cin >> var1;
    cout << "Enter second digit "<< endl;
    cin >> var2;
    cout << "Enter operation you want to perform, supported operations +,-,*,/,%" << endl;
    cin >>oper;
    if (oper == '+'){
        cout << var1 << " + "  << var2 << " = " << var1+var2 << endl; 
    }
    else if (oper == '-')
    {
        cout << var1 << " - "  << var2 << " = " << var1-var2 << endl; 
    }
    else if (oper == '*')
    {
        cout << var1 << " * "  << var2 << " = " << var1*var2 << endl; 
    }
    else if (oper == '/')
    {
        if (var2 == 0)
        {
            cout << "Division not possible " << endl;
        }
        else 
        cout << var1 << " / "  << var2 << " = " << var1/var2 << endl; 
    }
    else if (oper == '%')
    {
        cout << var1 << " % "  << var2 << " = " << int(var1)%int(var2) << endl; 
    }
    else
    {
        cout << "Operator not supported " << endl;
    }
}



int main()
{
    do 
    {
        run();
        char choice;
        cout << "Do you want to perform calculation again, if yes press any key, else press q/Q " <<endl;
        cin >> choice;
        if (choice == 'q' || choice == 'Q')
        {
            break;
        }
    }
    while(true);
    
    return 0;
}
