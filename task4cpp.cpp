#include<iostream>
#include<string>
using namespace std;
static int num = 1;
static int tasks = 0;
struct Task
{
    Task* next;
    Task* prev;
    bool complete;
    string task;
    int tasknum;
    Task() : next(nullptr),complete(false),task("\0") {}
};


struct tmange      //  task manager
{
    Task *head;
    tmange() : head(nullptr) {}

    void addtask()
    {
        Task *newtask = new Task;
        cout << "Enter Task " << endl;
        cin.ignore();
        getline(cin,newtask->task);
        newtask->next = nullptr;
        newtask->prev = nullptr;
        newtask->tasknum = num++;
        if (!head)
        {
            head = newtask;
        }
        else
        {
            Task * curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newtask;
            newtask->prev = curr;
        }
        tasks++;
    }
    

    void marktask(int tasknumber)
    {
        
        Task *curr = head; 
        while (curr)
        {
            if (curr->tasknum == tasknumber)
            {
                curr->complete = true;
                break;
            }
            curr = curr->next;
        } 
    }
    void removetask(int tnum)
    {
        if(!head)
        {
            cout << "No task Present " << endl;
        }
        else if (tnum == 0)
        {
            cout << "No such task " << endl;
        }
        else 
        {
            Task * curr = head;
            while (curr)
            {
                if (tnum == curr->tasknum)
                {
                    
                    if (curr->prev)
                    {
                        curr->prev->next = curr->next;
                    }
                    else 
                    {
                        head = curr->next;
                    }

                    if (curr->next)
                    {
                        curr->next->prev = curr->prev;
                    }
                }
                
                
                curr = curr->next;
            }
            
        }
    }

    void viewtask()
    {
        Task * curr = head;
        while (curr)
        {
            string status = "\0";
            if (curr->complete == 0)
            {
                status = "Pending";
            }
            else
            status = "Complete";
            cout << curr->tasknum << "   " << curr->task << "   Status  " << status << endl; 
            curr = curr->next;
        }
    }
};


void run()
{
    tmange * manager = new tmange;
    char choice = '\0';
    while (true)
    {
        cout << "Would you like to add a new task press 1 , view task 2, mark task 3 or remove task 4, press q to exit" << endl;
        cin >> choice;
        if (choice == '1')
        {
            manager->addtask();
        }
        else if (choice == '2')
        {
            manager->viewtask();
        }
        else if (choice == '3')
        {
            manager->viewtask();
            cout << "Which task do you want to mark " << endl;
            int tnum = 0;
            
            cin >> tnum;
            manager->marktask(tnum);
        }
        else if (choice == '4')
        {
            cout << "Which task do you want to remove " << endl;
            int tnum = 0;
            cin >> tnum;
            manager->removetask(tnum);
        }
        else if (choice == 'q' || choice == 'Q')
        {
            break;
        }
        

    }
}

int main()
{
    run();
}