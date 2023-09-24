#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void viewTasks(const vector<Task>& tasks) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        }
        cout << tasks[i].description << endl;
    }
    cout << endl;
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Add Task
            string taskDesc;
            cout << "Enter the task description: ";
            cin.ignore(); 
            getline(cin, taskDesc);
            Task newTask(taskDesc);
            taskList.push_back(newTask);
            cout << "Task added successfully!" << endl;
        } else if (choice == 2) {
            viewTasks(taskList);
        } else if (choice == 3) {
          
            int taskNumber;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskNumber;
            if (taskNumber >= 1 && taskNumber <= static_cast<int>(taskList.size())) {
                taskList[taskNumber - 1].completed = true;
                cout << "Task marked as completed!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        } else if (choice == 4) {
           
            int taskNumber;
            cout << "Enter the task number to remove: ";
            cin >> taskNumber;
            if (taskNumber >= 1 && taskNumber <= static_cast<int>(taskList.size())) {
                taskList.erase(taskList.begin() + taskNumber - 1);
                cout << "Task removed successfully!" << endl;
            } else {
                cout << "Invalid task number." << endl;
            }
        } else if (choice == 5) {
            
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


