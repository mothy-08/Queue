#include <iostream>

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
            std::cout << "Queue is full. Cannot add element." << std::endl;
            system("pause");
            return;
        }

        if (isEmpty()) 
            front = rear = 0;        
        else 
            rear++;
        
        elements[rear] = data;
        std::cout << "Element " << data << " added to the queue." << std::endl;
        system("pause");
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            std::cout << "Queue is empty. Cannot delete element." << std::endl;
            system("pause");
            return;
        }

        int data = elements[front];

        if (front == rear) 
            front = rear = -1;
        else 
            front++;
        
        std::cout << "Element " << data << " deleted from the queue." << std::endl;
        system("pause");
    }

    int searchElement(int data) 
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot search for element." << std::endl;
            system("pause");
            return -1;
        }

        for (int i = front; i <= rear; i++)
        {
            if (elements[i] == data) 
            {
                std::cout << "Element " << data << " found at index " << i << "." << std::endl;
                system("pause");
                return i;
            }
        }
        std::cout << "Element " << data << " not found in the queue." << std::endl;
        system("pause");
        return -1;
    }

    void display() 
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Nothing to display." << std::endl;
            system("pause");
            return;
        }

        std::cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
        system("pause");
    }

    int getLargestElement() 
    {
        if (isEmpty()) 
        {
            std::cout << "Queue is empty. Cannot find the largest element." << std::endl;
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

        std::cout << "The largest element in the queue is: " << largest << std::endl;
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
        std::cout << "QUEUE DATA STRUCTURES" << std::endl << std::endl;
        std::cout << "[1] ADD" << std::endl;
        std::cout << "[2] DELETE" << std::endl;
        std::cout << "[3] SEARCH ELEMENT (IDENTIFY THE INDEX OF THE ELEMENT)" << std::endl;
        std::cout << "[4] DISPLAY ELEMENTS" << std::endl;
        std::cout << "[5] IDENTIFY THE LARGEST INTEGER" << std::endl;
        std::cout << "[6] EXIT" << std::endl << std::endl;
        std::cout << "ENTER YOUR CHOICE (1-6): ";
        std::cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "ERROR: INVALID CHOICE. PLEASE ENTER (1-6): ";
            std::cin >> choice;

        }

        system("cls");

        switch (choice) 
        {
        case 1:
        {
            std::cout << "Enter the element to add: ";
            std::cin >> element;
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
            std::cout << "Enter the element to search: ";
            std::cin >> element;
            index = queue.searchElement(element);

            if (index != -1) 
            {
                std::cout << "Index of element " << element << " is " << index << "." << std::endl;
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
            std::cout << "Exiting the program..." << std::endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
