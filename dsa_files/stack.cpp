#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
using namespace std;
// transform(s.begin(), s.end(), s.begin(), ::tolower);
const int N = 1e7;
ll Pos[N];
class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int(size);
    }
    void push(int data)
    {
        if (top == size - 1)
            cout << "size finish";
        else
            arr[++top] = data;
    }

    void pop()
    {
        if (top == -1)
            cout << "empty";
        else
            top--;
    }

    int peek()
    {
        if (top == -1)
            return -1;
        else
            return arr[top];
    }
    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
};
void insertAtBottom(stack<int> &s, int n)
{
    if (s.empty())
    {
        s.push(n);
        return;
    }
    int x = s.top();
    s.pop();
    insertAtBottom(s, n);
    s.push(x);
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
vector<int> nextSmallerElement(vector<int> arr, int n)
{
    // returns the indexes od nextsmaller
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleinHistogram(vector<int> &heights)
{
    int n = heights.size();
    for (int i : heights)
        cout << i;
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    cout << endl
         << "next";
    for (int i : next)
        cout << i << " ";

    cout << endl
         << "prev";
    for (int i : prev)
        cout << i << " ";

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
vector<int> prevGreaterElement(vector<int> arr, int n)
{
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    vector<int> ans(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    for (auto i : ans)
        cout << i << " ";
}
int main()
{
}
