#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
using namespace std;
// transform(s.begin(), s.end(), s.begin(), ::tolower);
const int N = 1e7;
ll Pos[N];
class Queue
{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == size - 1; }
    void push(int x)
    {
        if (isFull())
        {
            cout << "overflow";
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            arr[0] = x;
        }
        else
            arr[++rear] = x;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow";
            return;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
                front++;
        }
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
};
class CircularQueue
{

    int *arr;
    int front, rear;
    int size;

public:
    CircularQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % size == front; }
    void push(int x)
    {
        if (isFull())
        {
            cout << "overflow";
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            arr[0] = x;
        }
        else
            arr[(++rear) % size] = x;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow";
            return;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
                front = (front + 1) % size;
        }
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
};
class Node
{
public:
    Node *next;
    Node *prev;
    int data;
    Node(int x)
    {
        next = NULL;
        prev = NULL;
        data = x;
    }
};
class Deque
{
    Node *front;
    Node *rear;

public:
    Deque()
    {
        front = rear = nullptr;
    }
    void push_front(int x)
    {
        Node *t = new Node(x);
        if (front == nullptr)
            front = rear = t;
        else
        {
            front->prev = t;
            t->next = front;
            front = t;
        }
    }
    void push_back(int x)
    {
        Node *t = new Node(x);
        if (front == nullptr)
            front = rear = t;
        else
        {
            rear->next = t;
            t->prev = rear;
            rear = t;
        }
    }
    void pop_back()
    {
        if (front == nullptr)
        {
            cout << "underflow";
            return;
        }
        else
        {
            Node *t = rear;
            rear = rear->prev;
            free(t);
            if (rear)
                rear->next = nullptr;
            else
                front = nullptr;
        }
    }
    void pop_front()
    {
        if (front == nullptr)
        {
            cout << "underflow";
            return;
        }
        else
        {
            Node *t = front;
            front = front->next;
            free(t);
            if (front)
                rear->prev = nullptr;
            else
                rear = nullptr;
        }
    }
    int start()
    {
        if (front == nullptr)
        {
            cout << "under flow";
            return -1;
        }
        return front->data;
    }
    int end()
    {
        if (front == nullptr)
        {
            cout << "under flow";
            return -1;
        }
        return rear->data;
    }
};

void print(queue<int> t)
{
    while (!t.empty())
    {
        cout << t.front() << " ";

        t.pop();
    }
    cout << endl;
}

int main()
{
    Deque d;
    d.push_back(5);
    d.push_front(8);
    d.push_front(6);
    d.push_front(1);
    d.pop_front();
    cout << d.start() << endl;
}
