#include <iostream>
using namespace std;

#define SIZE 10

class Deque
{
    int arr[SIZE];
    int front, rear;

public:
    Deque()
    {
        front = -1;
        rear = -1;
    }

    void insertBeginning(int value)
    {
        if(front == 0 && rear == SIZE - 1)
        {
            cout << "Deque is Full\n";
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[front] = value;
        }
        else if (front > 0)
        {
            front = front - 1;
            arr[front] = value;
        }
        else
        {
            cout << "Insertion at beginning not possible\n";
        }
    }

    void deleteEnd()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Deque is Empty\n";
        }
        else if (front == rear)
        {
            cout << "Deleted element is: " << arr[rear] << endl;
            front = rear = -1;
        }
        else
        {
            cout << "Deleted element is: " << arr[rear] << endl;
            rear = rear - 1;
        }
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Deque is Empty\n";
        }
        else
        {
            cout << "Elements in Deque are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Deque d;
    int choice, value;

    do
    {
        cout << "\n--- DEQUE MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Delete at End\n";
        cout << "3. Display Deque\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            d.insertBeginning(value);
            break;

        case 2:
            d.deleteEnd();
            break;

        case 3:
            d.display();
            break;

        case 4:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}