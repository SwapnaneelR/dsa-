#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
using namespace std;
// transform(s.begin(), s.end(), s.begin(), ::tolower);
const int N = 1e7;
ll Pos[N];
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};
void print(Node *&head)
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    else
    {
        Node *newhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
}
Node *reverseingroups(Node *head, int k)
{
    if (head == nullptr)
        return head;
    Node *curr = head;
    Node *forward;
    Node *prev = nullptr;
    for (int i = 1; i <= k; i++)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    if (forward != nullptr)
        head->next = reverseingroups(forward, k);
    return prev;
}
int main()

{
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *p = head;
    Node *n2 = new Node(2);

    n1->next = n2;

    Node *n3 = new Node(3);
    n2->next = n3;

    Node *n4 = new Node(4);
    n3->next = n4;
    print(p);
    cout << endl;
    Node *m1 = new Node(0);
    Node *head2 = m1;
    Node *q = head2;
    Node *m2 = new Node(8);

    m1->next = m2;

    Node *m3 = new Node(3);
    m2->next = m3;

    Node *m4 = new Node(5);
    m3->next = m4;

    print(head2);
    cout << endl;
    int k = 2;
}
