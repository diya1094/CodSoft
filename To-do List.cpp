#include <iostream>
#include <string>
#include <list>
using namespace std;

list<string> item;

void add();
void display();
void markTaskCompleted();
void remove();

void add(){
    string x;
    cout << "Enter task: ";
    cin.ignore(); 
    getline(cin, x);
    item.push_back(x);
}

void display(){
    int id = 1;
    cout << "------------------------------" << endl;
    if(item.empty()){
        cout << "No task in the list" << endl;
    }else{
        cout << "Tasks: " << endl;
       for (const string& tasks: item)
        {
            if (tasks.find("[Completed]") != string::npos) {
                cout << "Task " << id++ << ": "<< tasks << endl;
            }else {
                cout << "Task " << id++ << ": "<< tasks << " [Pending]" << endl;
            }
        }
    }
    cout << "------------------------------" << endl;
}
void markTaskCompleted(){
int id;
    list<string>::iterator it;
    cout << "Enter the task id: ";
    cin >> id;
    if (id > 0 && id <= item.size()) {
        int i = 1;
        for (it = item.begin(); it != item.end(); it++) {
            if (i == id) {
                *it += " [Completed]";
                cout << "Marked task " << id << " as completed" << endl;
                break;
            }
            i++;
        }
    } else {
        cout << "Invalid task id." << endl;
    }
}

void remove(){
    int id,currentId=1;
    list <string>:: iterator it;
    cout << "Enter task id: ";
    cin >> id;
    if(id>0 && id <= item.size()){
        for(it = item.begin(); it !=item.end(); it++){
            if(currentId == id){
                item.erase(it);
                return;
            }
            currentId++;
        }
    }else{
        cout << "Invalid ID";
    }
}

int main(){
    int choice = -1;
    cout << endl <<  "-----TO-DO LIST-----" <<endl;
    cout << "1.Add new task\n2.Display all tasks\n3.Mark a task as completed\n4.Remove a task\n5.Exit the list" << endl;
    cout << "--------------------" << endl;
    while(choice!=5){
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                remove();
                break;
            case 5:
                cout << "Exit";
                break;
        }
    }
    return 0;
}
