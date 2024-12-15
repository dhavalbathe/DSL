#include<iostream>
using namespace std;
#define MAX 10

class Queue
{
    public:
    int front, rear;
    int arr[MAX];

    public:
    Queue()
    {
        front = rear = -1;
    }

    int isempty();
    int isfull();
    void push(int);
    void pop();
    void display();
};

int Queue::isempty() {
    return front == rear;
}

int Queue::isfull() {
    return rear==MAX;
}

void Queue::push(int x) {
    if(isfull()) cout << "Queue Overflow!!!" << endl;
    else {
        rear = rear+1;
        front = 0;
        arr[rear] = x;
    }
}

void Queue::pop() {
    if(isempty()) cout << "Queue Underflow!!!" << endl;
    else {
        rear = rear - 1;
    }
}

void Queue::display() {
    for(int i=front; i<=rear; i++) cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    Queue q1;
    int ch, x;
    do {
        cout << "1. Insert Job " << endl;
        cout << "2. Delete Job " << endl;
        cout << "3. Display " << endl;
        cout << "4. Exit " << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1: 
            cout << "Enter data: ";
            cin >> x;
            q1.push(x);
            cout << endl;
            break;

            case 2:
            q1.pop();
            cout << "Remaining Jobs: " << endl;
            q1.display();
            break;

            case 3:
            cout << "Queue contains: " << endl;
            q1.display();
            break;

            case 4: cout << "Exiting Program...";
        } 
    }while(ch != 4);

    return 0;
}
