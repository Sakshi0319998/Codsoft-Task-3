
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

struct Task 
{   
    string name,description;
    bool completed;

    //Task(string desc) : name(name),description(desc), completed(false) {}
     Task(const string & name, const string & description)
        : name(name)
        , description(description)
        , completed(false)
        {

        }
        
};


class ToDoList 
{
private:
    vector<Task> tasks;

public:
// add to task
    void addTask(const string & name,const string & description)
 {
    
    cout<<"\t\t\t=========================================================================="<<endl;
	cout<<"\t\t\t*                     WELLCOME TO YOUR TODO LIST                         *"<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    
        tasks.emplace_back(name, description);
        cout << "\t\tTask added successfully!" << endl;
        cout << "\t\tTask name: " << name << endl;
        cout << "\t\tTask description: " << description << endl;
        
 }

// display tha task
void viewTasks()
 {
    
    cout<<"\t\t\t=========================================================================="<<endl;
	cout<<"\t\t\t*                      WELLCOME TO YOUR TODO LIST                        *"<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;

    cout << "\n\t\t*-------------------Your current task in the list-----------------*" << endl;
    
        if (tasks.empty()) 
        {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "\t\tView the tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i)
         {
            cout << i + 1 << ". " << tasks[i].description << tasks[i].description
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }


    
//mark as completed task
 void markTaskCompleted(int index) 
 {
    
    cout<<"\t\t\t=========================================================================="<<endl;
	cout<<"\t\t\t*                     WELLCOME TO YOUR TODO LIST                         * "<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    
        if (index < 1 || index > tasks.size())
         {
            cout << "\t\tInvalid task number." << endl;
            return;
        }
        tasks[index - 1].completed = true;
        cout << "\t\tTask marked as completed: " << tasks[index - 1].description << endl;
    }

//remove the task from list
 void removeTask(int index) 
 {
        
    cout<<"\t\t\t=========================================================================="<<endl;
	cout<<"\t\t\t*                      WELLCOME TO YOUR TODO LIST                        *"<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    
        if (index < 1 || index > tasks.size())
         {
            cout << "\t\tInvalid task number." << endl;
            return;
        }
        cout << "\t\tRemoving task: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() 
{
    
    system("Color E0"); // "Color XY", X - backgroung color, Y - text color
    system("title todoapp @copyassignment");
    cout<<"\t\t\t=========================================================================="<<endl;
	cout<<"\t\t\t*                      WELLCOME TO YOUR TODO LIST                        *"<<endl;
    cout<<"\t\t\t=========================================================================="<<endl;
    
    ToDoList todoList;
    int choice;
    do 
    {
        cout << "\t\t\t\t*---------------------To-Do List Menu----------------------*" << endl;
        cout << "\t\t1. Add New Task" << endl;
        cout << "\t\t2. View Tasks" << endl;
        cout << "\t\t3. Mark Task as Completed" << endl;
        cout << "\t\t4. Remove Task" << endl;
        cout << "\t\t5. Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) 
        {
            case 1: 
            {   
                string taskname;
                cout << "\t\tEnter Your Task Name: ";
                getline(cin, taskname);
                string taskDescription;
                cout << "\t\tEnter Your Task Description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskname,taskDescription);
                break;
            }
            case 2:
            {
                todoList.viewTasks();
                break;
            }
            case 3:
             {
                int taskNumber;
                cout << "\t\tEnter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: 
            {
                int taskNumber;
                cout << "\t\tEnter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            }
            case 5:
                cout << "\t\tExiting the program." << endl;
                break;
            default:
                cout << "\t\tInvalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
