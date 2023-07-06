#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
    int elements[MAX_SIZE]{}, front{}, rear{};

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() 
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int data) 
    {
        if (isFull()) 
        {
            cout << "Queue is full. Cannot add element." << endl;
            system("pause");
            return;
        }

        if (isEmpty()) 
            front = rear = 0;        
        else 
            rear++;
        
        elements[rear] = data;
        cout << "Element " << data << " added to the queue." << endl;
        system("pause");
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot delete element." << endl;
            system("pause");
            return;
        }

        int data = elements[front];

        if (front == rear) 
            front = rear = -1;
        else 
            front++;
        
        cout << "Element " << data << " deleted from the queue." << endl;
        system("pause");
    }

    int searchElement(int data) 
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot search for element." << endl;
            system("pause");
            return -1;
        }

        for (int i = front; i <= rear; i++)
        {
            if (elements[i] == data) 
            {
                cout << "Element " << data << " found at index " << i << "." << endl;
                system("pause");
                return i;
            }
        }
        cout << "Element " << data << " not found in the queue." << endl;
        system("pause");
        return -1;
    }

    void display() 
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Nothing to display." << endl;
            system("pause");
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
        system("pause");
    }

    int getLargestElement() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot find the largest element." << endl;
            system("pause");
            return -1;
        }

        int largest = elements[front];

        for (int i = front + 1; i <= rear; i++) 
        {
            if (elements[i] > largest) 
            {
                largest = elements[i];
            }
        }

        cout << "The largest element in the queue is: " << largest << endl;
        system("pause");
        return largest;
    }
};

int main() 
{
    Queue queue;
    int choice{}, element{}, index{};

    do 
    {
        system("cls");
        cout << "QUEUE DATA STRUCTURES" << endl << endl;
        cout << "[1] ADD" << endl;
        cout << "[2] DELETE" << endl;
        cout << "[3] SEARCH ELEMENT (IDENTIFY THE INDEX OF THE ELEMENT)" << endl;
        cout << "[4] DISPLAY ELEMENTS" << endl;
        cout << "[5] IDENTIFY THE LARGEST INTEGER" << endl;
        cout << "[6] EXIT" << endl << endl;
        cout << "ENTER YOUR CHOICE (1-6): ";
        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "ERROR: INVALID CHOICE. PLEASE ENTER (1-6): ";
            cin >> choice;

        }

        system("cls");

        switch (choice) 
        {
        case 1:
        {
            cout << "Enter the element to add: ";
            cin >> element;
            queue.enqueue(element);
            break;
        }

        case 2:
        {
            queue.dequeue();
            break;
        }

        case 3:
        {
            cout << "Enter the element to search: ";
            cin >> element;
            index = queue.searchElement(element);

            if (index != -1) 
            {
                cout << "Index of element " << element << " is " << index << "." << endl;
            }
            break;
        }
            
        case 4:
        {
            queue.display();
            break;
        }
            
        case 5:
        {
            queue.getLargestElement();
            break;
        }

        case 6:
        {
            cout << "Exiting the program..." << endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
